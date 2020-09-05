Задача 5 (10 точки) . Текстов файл с име comproc1 съдържа зададената подолу
последователност
от команди на bash за Linux. Напишете вдясно какво ще бъде изведено на стандартния изход след
стартиране на файла с команден ред
bash comproc1 3 4 5 //$# = 3
ако на стандартния вход бъде подадена последователността от символи 6 7

br=0                     
br=`expr $br + $2`      //br =4 
set 3 5 7				// нови позици параметри
shift					// вече са само 5 и 7
for j   //въртим по позиц парам; 
do for var //въртим по позици параметри 
	do if test $br –lt $2                // Iter1) 4 < 7?  Не;  Iter2) 28 < 7 Не
			then br=` expr $br \* $2`    // br = br*7=28 
			echo $br $var $j >> file     // 28 5 5 >> file
		else br=`expr $br - $2`            //  br = 21
			echo $var $br $j >> file	   //  7 21 5 >> file
		fi
	done
	echo $*   //output--> 5 7
	break
done
read a1 a2   //6 7
until cat file | grep $a1  //нямаме 6 във файла, значи влизаме в цикъла
do echo $#                  // output -->2
	grep $1 file			// output --> грепваме 5ца и взимаме всички редове
	exit
	echo END
done
echo $3
wc –l < file
echo FINAL

file:
28 5 5
7 21 5


output:
5 7
2
28 5 5
7 21 5
