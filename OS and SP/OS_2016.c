//9.09.2016 

Текстов файл с име procA съдържа зададената по-долу последователност от
команди на bash за Linux. Да се напише вдясно какво ще бъде изведено на стандартния изход
и какво ще бъде съдържанието на файловете f1 и f2 след стартиране на командната
процедура със следния команден ред:
bash procA ab bc cd    // $# = 3
ако на стандартния вход бъде подадена последователността от символи b c
//  INTEGER1 -gt INTEGER2
//  INTEGER1 is greater than INTEGER2
//expr -  Print  the  value of EXPRESSION to standard output.
//until 
/* The until loop is used to execute a given set of commands as 
long as the given condition evaluates to false.

The Bash until loop takes the following form:
until [CONDITION]
do
  [COMMANDS]
done 

The condition is evaluated before executing the commands.
 If the condition evaluates to false, commands are executed. 
 Otherwise, if the condition evaluates to true the loop 
 will be terminated and the program control will be passed 
 to the command that follows.
 
 $* Expands to the positional parameters, starting from one.
 поз параметри се разделят по думи
*/

/*break command is used to terminate the execution of for loop, 
while loop and until loop. It can also take one parameter i.e.[N]. 
Here n is the number of nested loops to break. The default number is 1.
Syntax:
break [n]
*/

count=1
for i in 6 1 4 2
do
	for each								  // цикли по поз параметри почващи от 1
	do if test $i -gt $# 				      //тества дали и-тия елемент е по-голям от 4 
			then count=` expr $count \* $i`   // count = count*$i, но не се eval още
			echo $count $each >> f1           // изкарваме във f1 стойността, която се оценява
										      // и тя е 6 както и each което заема стойност
											  // на позиционните параметри 6 ab
											  //                          36 bc
											  //                        216  cd
		else until false                      // влизаме тук за 1 
			do echo $*  					 
			// $* са позиционните параметри
///////////////////////// *********** ab bc cd
			break 3						      // излизаме и от трите цикъла
			done
			fi
	done
done
read k1 k2   								  //въвеждаме b c
while cat f1 | grep $k1                       //взимаме от f1 редовете съдържащи b
////////////////////////////////////////////// тоест 6 ab
///////////////////////////////////////////////      36 bc
do set $k1 $k2 $count				          // променяме поз параматери на b c 6
	shift									  //изместваме ги  i 1 и стават c 6
	echo $1 $2								
	//////////////////////////////////////// ************c 216
	grep $2 f1 > f2   //взимаме редовете от f1 където има 216ка, 
					  //записваме ги в f2 
					  //216 cd
	wc -c f2         
	///////////////////////////////////////// ****** 7 f2 т.е брои и newline
	exit   //излизаме от програмата
	echo END
done
wc -l f1
tail -2l f1
echo FIN

output:
ab bc cd
6 ab
36 bc
c 216
7 f2

f1:
6 ab
36 bc
216 cd

f2:
216 cd