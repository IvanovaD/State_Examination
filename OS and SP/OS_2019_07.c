
//2019.07
x1
———————————————————————
5 line five
8 line eight
More text
0123456789
test check trial
9 line nine 10 line ten
abcdef

f1
———————————————————————
line
x1



/* В текущата директория се намира също и празният файл f4.
 Текстов файл с име comproc съдържа зададената по-долу последователност 
 от команди на bash за Linux. Да се напише какво ще бъде изведено на 
 стандартния изход след еднократно стартиране на comproc със следния
 команден ред 
 bash comproc ab cd ef gh
и при подаване на последователността от символи 3 1 на стандартния вход.
//for loop bash
for VARIABLE in 1 2 3 4 5 .. N
do
	command1
	command2
	commandN
done


wc - word count
wc -l - prints the number of lines in a file
everything between '  ' is counted as a single line
head -n reads first n lines
For compatibility head also supports an obsolete option syntax 
-[NUM][bkm][cqv],
 which is recognized only if it is specified first
head -1 file //first line of the file
  set - Change the value of shell attributes and positional parameters, or
    display the names and values of shell variables.
 */
grep `head -1 f1` `tail -1 f1` | wc -l > f2 //grep line line | wc -l > f2 
//3 линии
// *****************
a=`cat f2` //a = 3
echo $a $3 // ***********$a е 3, а $3 е третия позиционен параметър ef
set 9 7 5 3 //новите позиционни параметри са 9 7 5 3
shift 2 // остават само 5 3 
for j in 1 2 3 4 5 // повтаряме цикъла 5 пъти
do for i  //цикли по позиционните параметри
	do if test $a -lt $i  //INTEGER1 -lt INTEGER2
			   // проверка дали   INTEGER1 is less than INTEGER2 и винаги е вярно
	 
		then cat f1 f2 > f3 //копирам от f1 и f2 във f3 и f3 става: line
																    //x1
								//									 3
			wc -l f3			// *****броим редовете в f3 и те са 3 f3
							
			echo $i $j $a >> f4   // пишем във f4 
									//            5 1 3
									
else tee f2 f3 < f1 //пишем от f1 и едновременно изкарваме на станд изход line 
																	//    x1
			wc -w f2    //2 f2
			echo $i $j $a >> f4    // 3 1 3
		fi
	done //КРАЙ НА ВЪТРЕШНИЯ ЦИКЪЛ
	echo $# >> f4 // брой аргументи позиционни  добавяме ред 2
break //САМО ВЕДНЪЖ СЕ ЗАВЪРТА ВЪНШНИЯ ЦИКЪЛ ЦИКЪЛ т.е j=1
done
read key1 key2 //четем от клавиатурата съответно 3 1
while cat f4 | grep $key2 //****търсим в f4 1чката и я намираме 2 пъти
	do sort f4 //SORT command sorts the contents of a text file, line by line
						// ****
						//	 2 
	                    //   3 1 3
						//	 5 1 3
	a=`wc -c < f4` //броя букви в f4 т.е 1
	echo -n "Character count: $a" // 14 = 11 + 3(new line)
	exit  //излизаме от програмата

				
done                 // въобще не стигаме до тачи част
grep $key1 f4     // връща реда с 3ка - 3 1 3
b=`wc -l < f4`    // броу редове в f4 - 5
echo -n "Lines count: $b" //5




Output: 

student@banshee:~$ bash comproc ab cd ef gh

3 ef
3 f3
line
x1
2 f2
3 1
5 1 3
3 1 3
2
3 1 3
5 1 3
Character count: 14