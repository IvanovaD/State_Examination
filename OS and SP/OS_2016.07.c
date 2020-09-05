//2016.07

Задача 5 . Текстов файл с име comproc1 съдържа зададената подолу
последователност
от команди на bash за Linux. Да се подчертаят операторите, които извеждат текст на
стандартния изход и за всеки от тях да се напише вдясно какво ще бъде изведено след
стартиране на файла със следния команден ред:
bash comproc1 1 3 5 //$# =3
ако на стандартния вход бъде подадена последователността от символи c d


br=1
br=`expr $br \* $2`  //присвояване на br литерала expr $br \* $2 без оценяване, стойността е 3 на израза
a=$3                 // a = 5
set ab bc cd de      //нови позиц параметри 
shift				 // bc cd de
while true
do echo $*           //!!!!!!!!!!!!!!!!! --> bc cd de
		for j        // j = bc, j = cd, j = de
			do if test $# -lt $br         //Итер1: 3 < 3 ? Не; Итер2: 3 < 8 Да; Итер3: 3< 4 Да
				then br=` expr $br / 2`     //br = 4; br =2;
					echo $br $j >> file		// 4 cd >> file; 2 de >> file
				else br=`expr $br + $a`     //br = 3 + 5 = 8
					 echo $br $j >> file    // 8 bc >> file
				  fi
		done
break  //излизаме от външния цикъл
done
read a1 a2  //четем c d
while cat file | grep $a1     ////--> 8 bc
                               // --> 4 cd 		
do echo $a $a2                 // --> 5 d
	wc -l file				   // --> 3
	tail -5c file			   // --> 2 de ;; tail не добавя \n накрая на командата но го взима от последния симнол
								// докато head може да не прихване \n 
	exit                       // Излизаме от програмата
	echo FIN
done
echo $a $a1
wc c
file
tail 2l 
file


output:
bc cd de
8 bc
4 cd 
5 d
3 file
2 de

file:
8 bc
4 cd
2 de 

