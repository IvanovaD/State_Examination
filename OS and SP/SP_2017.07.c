//11. 07. 2017

В текущия каталог се намира текстов файл file.txt със следното съдържание
abcdef //7
0123456789 //11
ABCD		// 5
Изпълнимият файл, получен след компилация на зададения 
по-долу програмен фрагмент, се стартира с командния ред:
./a.out ff
Напишете какво ще бъде изведено на стандартния изход и
 какво ще бъде съдържанието на двата файла след приключване на успешното изпълнение
 
#include <stdio.h>
#include <fcntl.h>
main( int argc, char * argv[])
{
int fdi, fdo, k,broi, i = 0 , status;
char buff [ 40 ], c ;
if ( ( fdi = open ("file.txt", O_RDWR ) ) = = -1 )
{ printf ("\n Cannot open \n" ); exit (1); }
if ( ( fdo= open (argv[1], O_CREAT| O_TRUNC| O_RDWR, 0666) ) = = -1 )
{ printf ("\n Cannot open \n" ); exit (1); }
if ( fork( ) = = 0 )
{
k=dup(1); close(1); dup(fdi); //пренасочваме ст изход към fdi
broi = read ( fdi , buff, 40 ); //прочитаме първите 23 символа
c = buff[ i++]; 
if ( c <= '0' || c >= '9' )
{ while ( buff [ i ++] != '\n' && i < broi )
		write ( 1, "*", 1 ); //пишем накрая на файла ***** 
write ( 1, "\n", 1 );        // и слагаме нов ред
close(1); dup(k);			 //възст стандартния изход
write ( 1, buff, 3 );  		 // и cout<< първите три символа abc
write ( fdo, buff, 10 );     // пишем във fdo cdef\n01
}
else { write( 1, buff, broi ); close(1);dup(k);
write ( 1, "*\n", 2 ); }
lseek( fdo,0, 0);
write ( fdo, "*\n", 2 );
close ( fdi); close (fdo);
}
else { wait ( &status);
close(1); dup(fdi); пренасочваме стандартния изход към fdi
execlp ("grep", "grep", "c", argv[1], 0 ); //взимаме от fdo редът със с а именно abcdef
// и го записваме във fdi
execlp ("wc", "wc", "-l", “ff” , 0 );
}
}

file.txt:
abcdef
0123456789
ABCD
*****
cdef

ff:cdef\n01

output:abc