//OS 2014.07

Задача 3. (10 т.) Текстов файл с име comproc1 съдържа зададената по-долу последователност от
команди на bash за Linux. Напишете вдясно какво ще бъде изведено на стандартния изход след
стартиране на файла с команден ред
bash comproc1 ab cd ef  //$# =3
ако на стандартния вход бъде подадена следната последователност от символи: 1 2

count=1
for i in 5 1 4 2
do for j
	do if test $i –ge $#                      //5>= 3 Да ; Iter2: 5>=3 ? Да; ... Iter4: 1>=3 No
			then count=` expr $count \* $i`   // count  = 1*5 = 5; count = 25
			echo $count $j >> f1              // 5 ab >> f1; 25 cd >> f1; 125 ef
			else while true
				do echo $*                    // output --> ab cd edf
					break 3					  //излизаме
		        done
		fi
	done
done
read k1 k2               // 1 2
while cat f1 | grep $k2  // търсим в f1 2 и го има на два реда, извеждаме го
do set $k1 $count         // нови поз параметри 1 125
	shift					// 125 единств позицион параметър
	echo $2					// извеждаме празен ред
	echo $1 $i				// извеждаме 125 1
	exit
done
echo FIN    //

f1:
5 ab
25 cd
125 ef

output: 
ab cd ef
25 cd
125 ef

125 1
