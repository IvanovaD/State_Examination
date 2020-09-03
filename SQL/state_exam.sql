--2019.09
use movies;
--Зад 1.
-- Да се огради буквата на заявката, която извежда за всеки продуцент името му и броя на фил
-- мите му по години.
-- Продуценти, които нямат нито един филм, НЕ трябва да присъстват в резултатното множество
SELECT ME.NAME, M.YEAR, COUNT(*) AS CNT
FROM MOVIEEXEC ME
JOIN MOVIE M ON 
ME.CERT# = M.PRODUCERC#
GROUP BY ME.CERT#, ME.NAME, M.YEAR;

--Да се напише заявка, която да изведе името на най-младата звезда (полът е без значение).
select name, birthdate
from moviestar
where BIRTHDATE >= all(select birthdate from moviestar);

--2019.07
--зад1.а)Да се огради буквата на заявката, която извежда име на студио и броя на филмите му, за тези студия 
--с по-малко от два филма. Студиата, които нямат нито един филм, НЕтрябва да присъстват в резултата.

SELECT S.NAME, COUNT(M.TITLE) as CNT
FROM STUDIO S JOIN MOVIE M
ON S.NAME = M.STUDIONAME
GROUP BY S.NAME
HAVING COUNT(M.TITLE) < 2;

--Да се напише заявка, която да изведе имената на всички продуценти с минимален нетен актив.
select name, networth 
from movieexec
where networth <= all(select networth from movieexec);

--2018.09
--Да се напише заявка, която извежда име на клас, годината на първата битка, в която кораб на този клас е участвал,
-- годината на последната битка, в която кораб на този клас е участвал, и броя на всички различни битки, 
--в които кораби на този клас са участвали, само за тези класове, започващи с буквата N. Ако за даден клас няма кораб, 
--който да е участвал в битка, за съответните години да се върне стойност null.


use ships;

select class, min(year(date)), max(year(date)), count(distinct battle)
from ships left join outcomes on ship = ships.name
left join battles on battles.name = battle
where class	like 'N%'
group by class


--Да се напише заявка, която да изведе имената на тези битки, за които броят на корабите
-- от тип 'bb', участвали в тази битка, е по-голям от броя на корабите от тип 'bc',
-- участвали в същата битка. Битки, в които не е участвал нито един кораб, да не се 
--извеждат в резултата.

select battle
from outcomes join ships on ship = name
 left join classes bb on bb.class = ships.class and bb.type = 'bb'
 left join classes bc on bc.class = ships.class and bc.type = 'bc'
 group by battle
 having count(bb.class) > count(bc.class) and count(bb.class) + count(bc.class) > 0


--2018.07
--Да се напише заявка, която да изведе име на студио, годината на първия филм за това студио, 
--годината на последния филм за това студио и броя на всички филми за това студио, само за тези студиа 
--започващи с буквата ‘M’.
--2.Да се напише заявка, която да изведеимето на актрисата, участвала в най-много филми,
-- и броя на филмите, в които е участвала.

use movies;
select name, min(movie.year), max(movie.year), count(distinct title)
from studio join movie on studioname = name
where name like 'M%'
group by name;

select starname, count(	movietitle) as totalMovies
from starsin join moviestar on name = starname
where gender='F'
group by starname
having count(movietitle) >= all(select count(movietitle) from starsin join moviestar 
on name = starname  where gender = 'F' group by starname );


--2017.09
--Попълнете липсващите части, обозначени с ______ така, че заявката да изведе име и 
--държава на корабите, които никога не са потъвали в битка (може и да не са участвали).
USE SHIPS;

SELECT name, country, result
 FROM ships left join outcomes ON name=ship
 left join classes ON ships.class=classes.class
 WHERE ship not in(select ship from outcomes where result = 'sunk' )
 or result is null;
--2. Попълнете липсващите части, обозначени с ______ така, че заявката да изведе име, 
--водоизместимост и брой оръдия на най-леките кораби с най-много оръдия.
SELECT name, displacement, numguns
FROM classes c JOIN ships s ON s.class=c.class
WHERE displacement = (SELECT min(displacement) FROM classes) AND
numguns = (SELECT max(numguns) from classes c1
WHERE c1.class=c.class);
--09.09.2017г. ДИ:ОКС „Бакалавър” по Компютърни науки, ФМИ–СУстр. 6/133. 
--Попълнете липсващите части, обозначени с ______ така, че заявката да изведе име
-- на битките, в които е участвал един кораб.
SELECT battle
FROM outcomes o1
WHERE exists 
(SELECT * FROM outcomes o2
WHERE o1.ship<>o2.ship and o2.battle = o1.battle)

SELECT class, COUNT(DISTINCT name)
FROM ships s JOIN outcomes o 
ON s.name=o.ship
WHERE result='sunk' AND class IN (SELECT c.class
FROM classes c JOIN ships s ON c.class=s.class
GROUP BY c.class
HAVING COUNT(name)>5)

GROUP BY class;


--2017.07
use movies;
--да изведе за всяко студио името на студиото, заглавието и годината на филма,
--излязъл последно на екран за това студио
SELECT studioname, title, year FROM movie m
 WHERE year = (SELECT max(year) FROM movie WHERE m.studioname = studioname)
--11.07.2017г. ДИ:ОКС „Бакалавър” по Компютърни науки, ФМИ–СУстр. 6/152. 
--Попълнете липсващитечасти, обозначени с ______ така, че заявката да изведе
-- име на продуцент и обща дължина на продуцираните от него филми, за тези продуценти,
-- които имат поне един филм преди 1980 г.
SELECT name, sum(length)
FROM movieexec JOIN movie ON producerc# = cert#
where name in (select name from movieexec join movie on producerc# = cert#
where year < 1980 )
group by name




 
--3. Попълнете липсващите части, обозначени с ______ така, че
 --заявката да изведе име на актьорите, участвали във филми на
 -- продуценти с най-големи нетни активи, както и заглавие на 
 --филмите, в които са участвали, име на продуцент и нетни активи.
 SELECT starname, title, name, networth
 FROM starsin JOIN movie ON movietitle=title AND movieyear=year
 JOIN (SELECT cert#, networth, name
 FROM movieexec
 WHERE movieexec.networth >= all(select networth from movieexec)) t
 on T.CERT#=PRODUCERC#;

 --4. Заградете буквата назаявката, която извежда името на продуцента, 
 --заглавието и годината на всички филми, продуцирани от продуцента на филма 
 --‘Interstellar’.A)

 SELECT name, title, year
 FROM movie JOIN movieexec ON producerc#=cert#
 WHERE cert# = ANY (SELECT producerc#
 FROM movie
 WHERE title='Star Wars');

--2016.09
 use ships;

SELECT DISTINCT c.country, (SELECT COUNT(o.result)
 FROM classes c1 JOIN ships s   ON c1.class=s.class 
 JOIN outcomes o ON s.name=o.ship 
 WHERE result='sunk'  AND c1.country=c.country)
 FROM classes c


 /*
 не е вярно
 SELECT DISTINCT battle
 FROM outcomes, (SELECT count(DISTINCT country) as NumCountries --cross join
 FROM outcomes o,ships s,classes c
 WHERE o.ship=s.name AND s.class=c.class  AND battle='Coral Sea') as t
 HAVING (SELECT count(DISTINCT country)  
 FROM outcomes o1,ships s,classes c  
 WHERE o1.ship=s.name AND s.class=c.class AND battle=o1.battle)  
  > (SELECT NumCountries FROM t)*/

  SELECT DISTINCT battle
  FROM outcomes o1
  WHERE(SELECT COUNT(DISTINCT country)
   FROM outcomes o,ships s,classes c
    WHERE o.ship=s.name AND s.class=c.class 
   AND battle=o1.battle) >
   (SELECT count(DISTINCT country) 
   FROM outcomes o,ships s,classes c 
    WHERE o.ship=s.name 
   AND s.class=c.class AND battle='North Cape')

   SELECT DISTINCT battle
   FROM outcomes o, ships s, classes c
   Where o.ship=s.name AND s.class=c.class
   GROUP BY battle
   HAVING COUNT(DISTINCT country)>(SELECT COUNT( country) --трябва да има дистинкт така че не е вярно
    FROM outcomes o, classes c, ships s WHERE ship=name AND s.class=c.class
	   AND battle='North Atlantic');


--07.2016
use movies;
SELECT t.name, title
FROM movie m JOIN (SELECT name, cert#   FROM movieexec   WHERE cert# IN
 (SELECT producerc#          FROM movie         WHERE title='Pretty Woman')) t
 ON m.producerc#=t.cert#;

 /*
 няма колона name и title в t

 SELECT name, title
 FROM (SELECT cert#
 FROM movieexec
 INTERSECT
 SELECT producerc#
 FROM movie
 WHERE title ='Pretty Woman') t
 */

 /* изарва само филма Хубава жена
 SELECT name, title
 FROM movie m JOIN movieexec me ON m.producerc#=me.cert#
 WHERE title = 'Pretty Woman'
 */

 /*
 изкарва продуцентите КОИТО НЕ СА направили Хубава жена
 SELECT name, title
 FROM movie m LEFT JOIN movieexec me ON m.producerc#=me.cert#
 WHERE me.cert# NOT IN (SELECT producerc#      FROM movie      WHERE title='Pretty Woman');*/

 -- ​Да се посочи заявката, която за актьорите, участвали в най-­много филми на съответното студио,
 -- извежда име на студио, име на актьор и брой филми, в които е участвал актьорът. 
 --Врезултата ​не​ трябва да се включват филми, за които името на студиото не е известно

 SELECT studioname, starname, COUNT(*)
 FROM movie m JOIN starsin ON title=movietitle AND year=movieyear
 WHERE studioname IS NOT NULL
 GROUP BY studioname, starname
 HAVING COUNT(*) >= ALL (SELECT COUNT(*)  FROM movie, starsin  WHERE title=movietitle    
 AND year=movieyear    AND studioname=m.studioname  GROUP BY studioname, starname);



 /*
 
 за всеки ред  студио и звезда може да съответства повече от един филм
Тъй като броим по колоната starname без повторения така губим различните филми 
при повтарящите се редове. Ако махнем Дистинкт ще проработи
 SELECT studioname, starname, COUNT(DISTINCT starname)
 FROM movie m JOIN starsin ON title=movietitle AND year=movieyear
 WHERE studioname IS NOT NULL
 GROUP BY m.studioname, starname
 HAVING COUNT(starname) >= ALL (SELECT COUNT(DISTINCT starname)   
 FROM movie, starsin   WHERE title=movietitle     AND year=movieyear
 AND studioname=m.studioname   GROUP BY studioname, starname);
 */
 /*
 count - приема един аргумент
 SELECT studioname, starname, COUNT(starname)
 FROM movie m LEFT JOIN starsin ON  title=movietitle AND 
 year=movieyear
 WHERE studioname IS NOT NULL
 GROUP BY studioname, starname
 HAVING COUNT(SELECT starname  FROM movie, starsin  WHERE title=movietitle
   AND year=movieyear AND studioname=m.studioname) >= ALL(SELECT COUNT(*) FROM movie, starsin WHERE title=movietitle 
     AND year=movieyear GROUP BY studioname, starname);
	 */
	 --2015.09
	 select address 
	 from studio

	 SELECT *FROM (SELECT name, address
	 FROM MovieStar
	 WHERE gender = 'F'UNION
	 SELECT name, address
	 FROM Studio) T
	 WHERE T.address LIKE '%Boulevard%'ORDER BY T.address;

	 /*
	 не изкарва името на студиото - плюс че изкарва адресите само където 
	 те съвпадат за звездите и за студията
	 SELECT MS.name, MS.address
	 FROM MovieStar AS MS
	 JOIN Studio S ON MS.address =S.address
	 WHERE MS.address LIKE '%Boulevard%'AND gender = 'F'
	 ORDER BY MS.address
	 */
	 /*
	 order by - не може да е по средата на query-то; винаги накрая
	 SELECT name, address
	 FROM MovieStar MS
	 WHERE gender = 'F'
	 ORDER BY address
	 UNION ALL
	 SELECT name, address
	 FROM Studio
	 WHERE address LIKE '%Sofia%' 
	 ORDER BY address;
	 */
	 /*
	 не се знае откъде взимаме името и адреса - дали от звездата или студиото?


	 SELECT DISTINCT name, address
	 FROM MovieStar
	 FULL JOIN Studio ON address LIKE '%Sofia%'
	 WHERE gender LIKE 'F'
	 ORDER BY address;
	 */
	 /*
	 INTERSECT Studio - не работи
	 когато използваме пресичане трябва да го направим върху проекция
	 с избрани съответните колони
	SELECT DISTINCT name, address
	FROM MovieStar INTERSECT Studio
	WHERE address IS NOT NULL
	AND gender LIKE 'F'
	GROUP BY address
	HAVING address LIKE '%Sofia%'
	*/
	/*
	не може в count () да имаме равенство */
	use movies;
	/*SELECT name, address, AVG(length) AS avgLength
	FROM Studio
	LEFT JOIN Movie ON name = studioName
	GROUP BY studioName, address
	HAVING COUNT(inColor = 'y') <= 3;*/

	/*получава се cross join тъй като не сме специфира 
	как да направим съединението*/
	SELECT DISTINCT name, address, avgLength
	FROM Studio, (SELECT studioName, AVG(length) AS avgLength
	FROM Movie
	GROUP BY studioName) Averages
	WHERE NAME = ANY (SELECT studioName
	FROM Movie
	WHERE inColor = 'n' 
	GROUP BY studioName
	HAVING COUNT(title) <= 3);

	/*В подзаявката не специфицираме че става въпрос за определено студио
	 и затова тя брои всички общо безцветни филми и за което и да е било студио*/
	/*Select Studio.name, Studio.address, AVG(Movie.length) AS avgLength
	FROM Movie
	RIGHT JOIN Studio ON studioName = name
	GROUP BY name, address
	HAVING (SELECT COUNT(*) FROM Movie WHERE inColor = 'n') <= 3*/

	SELECT name, address, AVG(length) AS avgLength
	FROM Studio
	LEFT JOIN Movie ON name = studioName
	WHERE NAME NOT IN (SELECT studioName
	FROM Movie
	WHERE inColor = 'n' 
	GROUP BY studioName
	HAVING COUNT(*) > 3)GROUP BY name, address;


	--07.2015

	--Да се посочи заявката,която извежда имената на всички филмови звезди,чието
	--име не завършва на “а” и са играли както в цветни, така и в черно­бели филми

	SELECT name
	FROM MovieStar, StarsIn, Movie
	WHERE name=starName AND movieTitle=title AND movieYear=year 
	AND name != '%a' AND inColor = 'y' AND inColor = 'n';
	--б)
	SELECT MovieStar.name
	FROM MovieStar
	WHERE NOT (name LIKE '%a')
	AND name IN (SELECT starName
				FROM StarsIn
				JOIN Movie ON movieTitle = title AND movieYear = year
				WHERE inColor = 'y' OR inColor = 'n');
	--в)
	SELECT DISTINCT starName
	FROM StarsIn
	INNER JOIN Movie ON movieTitle = title AND movieYear = year 
	WHERE starName NOT LIKE '%a' AND inColor = 'y'AND starName = (SELECT starName
	FROM StarsIn, Movie
	WHERE inColor = 'n');
	--г)
	SELECT starName
	FROM StarsIn
	JOIN Movie ON movieTitle = title AND movieYear = year
	WHERE starName NOT LIKE '%a' AND inColor = 'y'
	INTERSECT
	SELECT starName
	FROM StarsIn
	JOIN Movie ON movieTitle = title AND movieYear = year
	WHERE inColor = 'n'


	/*Посочете заявката, която извежда за всяка филмова звезда, играла в най­много 5 филма,
следната информация:
­ име;
­ рождена година;
­ брой студиа, с които е работила.
Ако за дадена звезда няма информация в какви филми е играла, за нея също да се извежда ред (с
брой студиа, равен на 0)*/

/*грешен синтаксис на функцията year + count трябва да брои distinct studioname
*/
/*
SELECT DISTINCT name, birthdate.year, COUNT(studioName)
FROM MovieStar, StarsIn, Movie
WHERE name = starname AND
((movieTitle = title AND movieYear = year) OR title IS
NULL)
GROUP BY name, birthdate.year
HAVING COUNT(title) <= 5;*/
--б)

/*title трябва да е дистинкт за да се избегнат повторенията
+ birthdate не се съдържа в group by
ако сложим birthdate в group by - ще се оправи*/
 /*SELECT name, YEAR(birthdate), COUNT(DISTINCT studioName)
FROM MovieStar
LEFT OUTER JOIN StarsIn ON name = starname
LEFT JOIN Movie ON movieTitle = title AND movieYear = year
GROUP BY name
HAVING COUNT(title) <= 5;

*/
--в) birthday не е в group  by + StarsIn.starname може да даде null за име 
/*SELECT starname, YEAR(birthdate),
COUNT(DISTINCT studioName)
FROM Movie
JOIN StarsIn ON movieTitle = title AND movieYear = year
RIGHT OUTER JOIN MovieStar ON MovieStar.name = StarsIn.starname
GROUP BY starname
HAVING COUNT(DISTINCT title) <= 5;*/
--г) не може да имаме подзаявка в агрегатна функция

 /*SELECT name, year(birthdate), COUNT(SELECT DISTINCT studioName
FROM Movie
JOIN StarsIn ON title = movieTitle AND year = movieYear
WHERE starname = name)
FROM MovieStar
HAVING COUNT(SELECT * FROM StarsIn WHERE starname = name) <= 5
ORDER BY name, year(birthdate);
*/

--2014.09
--1. Оградете буквата на заявката, която извежда имената на всички кораби, пуснати на вода в
--година, в която е имало битка (не е задължително корабът да е участвал в нея). 
use ships;

/*
не може да имам агрегатна функция в where клаузата
select name
from ships
where launched = any (
select year(date)  
from battles  
where count(*) >= 1);
*/


--Б)
 select distinct ships.name
from battles , ships
where launched = year(date);


--В)
/*
тук изброяваме битки вместо кораби
 select name
from battles
where exists (select distinct *  
from ships  
where year(date) = launched);*/
--Г)
/*
тук имаме двусмислица тъй като name е колона и в двете таблици
 select distinct name
from ships
join battles  
on launched = year(date);*/--2. Оградете буквата на заявката, която за всички държави, които имат най-много 3 (евентуално 0)
--кораба, извежда името на държавата и броя потънали кораби (който също може да бъде 0).
--А) тук сме филтрирали само по потъналите кораби държавите, а на нас ни трябва и тези без потънали
/* select country, count(result)
from classes c
left join ships s  
on c.class = s.class
left join outcomes o  
on s.name = o.ship
where o.result = 'sunk'
group by country
having count(ship) <= 3;*/
--Б)агрегатна фукция в where, и повече от един аргумент за count в селекта
 /*select country,  count(result is 'sunk')
from ships, classes, outcomes
where count(ship) <= 3  
or ship is null;
*/
--В) тук отново филтирараме само за държавите с потънали кораби
 /*select distinct classes.country, sunk_cnt
from classes
right join (select country,
count(*) as sunk_cnt
from classes c
join ships s  
on c.class = s.class
join outcomes o  
on s.name = o.ship
where result = 'sunk'
group by country) sunk  
on classes.country = sunk.country
where sunk_cnt <= 3;*/
--Г)проверка в агрегатна функция, опитваме се да групираме по невалидна колона
/* select country,  
count(result = 'sunk') as sunk_cnt
from ships s
join outcomes o on s.name = o.ship
right join classes c  
on s.class = c.class
where count(*) <= 3
group by country, sunk_cnt;*/

--Д) верен
select distinct country,  
(select count(*)
from classes c2 join ships s on c2.class = s.class
join outcomes o on s.name = o.ship
where c2.country = c.country and result = 'sunk')
from classes c
where (select count(*)
       from classes c2 join ships s  on c2.class = s.class
       where c2.country = c.country) <= 3;

	   /* проверка на отговора
	select country, name
	from classes left join ships on ships.class = classes.class;
	*/


	--2014.07

	-- Оградете буквата на заявката, която извежда всички производители на настолни компютри,
--които произвеждат и лаптопи.
use pc;
--А)верен

 select distinct maker
from product
where product.type = 'PC'
and maker in (select maker  
from product join laptop  
on product.model = laptop.model);
--Б) ползваме cross join; maker е двусмислено
 /*select maker
from product p1
cross join product p2
where p1.maker = p2.maker
and p1.type = 'PC'  
and p2.type = 'Laptop'
group by maker;*/
--В) няма как типът да е едновременно два различни типа
/* select distinct maker
from product
where type = 'PC'  
and type = 'Laptop';
*/
--Г) union няма да ни даде търсеното множество
 /*select maker
from product
where type = 'PC'
union
select maker
from product
where type = 'Laptop';*/
--2. Оградете буквата на заявката, която извежда кодовете, моделите и размерите на екраните на
--всички лаптопи, чиито производители имат не повече от три модела принтери (евентуално 0).
/*А) 
синтаксисът е тотално оплескан
select code, model, screen
from laptop, product
where maker is  
having count(printer.model) <= 3;*/
--Б)
/* в count не може да има подзаявка 
select code, l.model, screen
from product p
left join laptop l  
on p.model = l.model
having count(select *
from product
where maker = p.maker  
and type = 'Printer') <= 3;*/
--В)верен
select code, l.model, screen
from laptop l
inner join product p  
on l.model = p.model
where maker not in (select maker
from product
where type = 'Printer'
group by maker
having count(*) > 3);
--Г)почти всичко е еднакво с В с изключение на това че тук задължаваме производителя да прави принтери
--може тоест има между 1 и 3 принтера да има
 /*select l.code, l.model, l.screen
from laptop l
join product p  
on l.model = p.model
where maker in (select maker
from product
where type = 'Printer'
group by maker
having count(*) <= 3);*/
--Д) след като групираме в селекцията може да имаме само групираните атрибути и агрегатни функции
 /* плюс тва трябва да групираме по производител
 select l.code, l.model, l.screen
from product p left join laptop l on p.model = l.model
left join printer on p.model = printer.model
group by l.code
having count(distinct printer.code) <= 3;
*/

--2010.09
use movies;
--А) (4 точки) Да се посочи заявката, извеждаща всички актриси, които не са играли в нито един
--филм с име, започващо с буквата А. Актриси, за които в базата от данни няма информация за
--техните участия, също трябва да бъдат изведени.
--А) изкарваме актрисите които имат поне един филм не започващ с А
--SELECT DISTINCT NAME
--FROM MOVIESTAR
--LEFT JOIN STARSIN
-- ON NAME = STARNAME
--WHERE GENDER = 'F'
-- AND MOVIETITLE NOT LIKE 'A%';
--Б) взимаме само актирисите с техните филми започващи с А ... и накрая искаме да имат 0 филми
--SELECT NAME
--FROM MOVIESTAR
--JOIN STARSIN ON STARNAME = NAME
--WHERE GENDER = 'F'
-- AND MOVIETITLE LIKE 'A%'
--GROUP BY NAME
--HAVING COUNT(*) = 0;
--В) верен
SELECT MS.NAME
FROM MOVIESTAR MS
WHERE MS.GENDER = 'F'
 AND NOT EXISTS
 (SELECT 1
 FROM STARSIN SI
 WHERE SI.STARNAME = MS.NAME
 AND SI.MOVIETITLE LIKE 'A%');
--Г)Взимаме само филмите незапочващи с А и техните главни актриси и искаме да изкараме тези актриси
--SELECT NAME
--FROM MOVIESTAR
--WHERE GENDER = 'F' AND NAME IN
-- (SELECT DISTINCT STARNAME
-- FROM STARSIN
-- WHERE NOT MOVIETITLE LIKE 'A%'); 
--08.09.2010г. ДИ ОКС „Бакалавър” по Компютърни науки, СУ-ФМИ фак. № стр. 12/12
--Б) (6 точки) Да се посочи заявката, която за всяка филмова звезда (без значение от пола), родена
--преди 1990 г., извежда възрастта, на която е играла за първи път във филм. Звезди, за които няма
--sинформация за техните участия във филми, не трябва да бъдат извеждани.
--А)верен, защото MIN( MOVIEYEAR - YEAR(BIRTHDATE) дава най раната възраст за съответния актьор
SELECT NAME, MIN( MOVIEYEAR - YEAR(BIRTHDATE) ) AS DEBUT_AGE
FROM MOVIESTAR
JOIN STARSIN ON NAME = STARNAME
WHERE YEAR(BIRTHDATE) < 1990
GROUP BY NAME;
--Б) birthday не е в агрегатна функция така че не може да го бъде в селект листа
--SELECT NAME, MIN(MOVIEYEAR) - YEAR(BIRTHDATE) AS DEBUT_AGE
--FROM MOVIESTAR
--JOIN STARSIN ON NAME = STARNAME
--WHERE YEAR(BIRTHDATE) < 1990
--GROUP BY NAME;
--В) having трябва да съдържа условие от булев тип, рожденната дата не се съдържа в group by
--плюс че left join запазва инфо за звезди за които няма инфо за техните участия във филми
--SELECT NAME, MIN(MOVIEYEAR) - YEAR(BIRTHDATE) AS DEBUT_AGE
--FROM MOVIESTAR
--LEFT JOIN STARSIN ON NAME = STARNAME AND YEAR(BIRTHDATE) < 1990
--GROUP BY NAME
--HAVING MIN(MOVIEYEAR);
--Г)за да ползаме having ни трябва или колоната да е в агр функц или да е в group by
--SELECT DISTINCT MS.NAME, MOVIEYEAR - YEAR(BIRTHDATE) AS DEBUT_AGE
--FROM MOVIESTAR MS, STARSIN
--WHERE MS.NAME = STARNAME AND YEAR(BIRTHDATE) < 1990
--HAVING MOVIEYEAR <= ALL (SELECT MOVIEYEAR
-- FROM STARSIN SI
-- WHERE SI.STARNAME = MS.NAME);


--2008.09
use ships;
--За всеки клас годината на най ранното и най-късно пуснатия на вода кораб
--a) не са групирани
-- select c.class, min(ss.launched), max(ss.launched)
--from classes c
--join ships ss on ss.class = c.class;
--b) верен
select c.class, min(ss.launched), max(ss.launched)
from classes c
join ships ss on ss.class = c.class
group by c.class;
--c) не трябва да има having от неусловен тип
-- select c.class, min(ss.launched), max(ss.launched)
--from classes c
--join ships ss on ss.class = c.class
--group by c.class
--having min(ss.launched) and max(ss.launched);
--d) union-a няма да ни даде това което търсим плюс че трябва групиране
-- select c.class, min(ss.launched)
--from classes c
--join ships ss on ss.class = c.class
--union all
--select c.class, max(ss.launched)
--from classes c
--join ships ss on ss.class = c.class;

--Държавите с най много класове
--агрегатна функция в where
--select c.country
--from classes c
--where not exists
--( select *
--from classes c1
--where c1.country != c.country and
--count(c1.class) > count(c.class)
--);
--b) where клаузата има агрегатна функц
-- select c.country
--from classes c
--group by c.country
--having max(count(c.class));
--c) не може в where да имаме count 
-- select c.country
--from classes c
--where count(*) = 
--( select max(count(c1.class)
--from classes c1
--group by c1.country)
--group by c.country;


--d)верен
 select c.country
from classes c
group by c.country
having count(*)>= all ( select count(*)
from classes c1
group by c1.country
);

--2008.07
--битките в които няма оцелели кораби 
--select distinct b.name
--from Battles b
--join Outcomes o on b.name = o.battle
--where o.result = 'sunk';

--select o.battle
--from Outcomes o
--group by o.battle,o.result
--having o.result = 'sunk';

select distinct o.battle
from Outcomes o
left join Outcomes o1 on o.battle = o1.battle and
o.ship = o1.ship and
o1.result = 'sunk'
group by o.battle
having count(o.ship)= count(o1.ship);

--select o.battle
--from Outcomes o
--group by o.battle
--having count(case when o.result = 'sunk' then 'Y' end)=0;

