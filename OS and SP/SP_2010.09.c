08.09.2010г.
Задача 2. (13 точки) В текущия каталог се намира текстов файл fileB.txt със следното
съдържание
12345$$6789 //12
$$abcdefg  // 10 

Да се напише вдясно на програмния код какво ще бъде изведено на стандартния изход
(терминала) като резултат от изпълнението на файла, получен при успешна компилация на
зададения по-долу програмен код на езика С, в който са използвани системни примитиви на ОС
UNIX и LINUX:
#include <stdio.h>
#include <fcntl.h>
main()
{
int fdr, fdw, n_byt, i = 0 , status;
char buff [40], c ;
if (fork( ))  //ако е true, т.е >0, тоест в родителя
	{
	wait (&status);                       //чакаме детето
	if (open("file_new", 0) != -1)        
	execlp("grep", "grep", "$", "file_new",0);  //родителя търси във новия файл $"
	}
else										//детето
	{
	if ((fdr = open("fileB.txt",0))== -1)             //отваряме fileB
		{ printf("\n Cannot open \n"); exit(1); }
	if (( fdw = creat ("file_new",0666))== -1)        //отваряме file_new
		{ printf ("\n Cannot creat \n"); exit (1); }
	n_byt = read (fdr,buff,40);    						//n_byte = 22
	c = buff[i++];										//buff[0] = 1		
	if (c <= '1' || c >= '9')   //влизаме в този if
	{
		while ( buff [i++] != '\n' && i < n_byt)  //влиза 10 пъти
			write( fdw, "$", 1 );   //пишем $ 10 пъти
		write(fdw,"\n",1); //пишем във fdw нов ред 
		write(1,"\n",1);  // пишем на стандартния изход нов ред
	}
	else { write(1,buff,n_byt ); write ( 1, "\n", 1 ); }
	
	write (fdw, "$", 1); // пишем във файл още едно $ на новия ред,  write не добавя нов ред
	close (fdr); close (fdw);
	}
}
output:
\n
$$$$$$$$$$
$

file_new:
$$$$$$$$$$
$