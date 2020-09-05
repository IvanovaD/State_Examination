Задача 3. (10 т.) В дясната страна на листа опишете какво очаквате да бъде изведено на
стандартния изход (терминала), като резултат от изпълнението на следната програма на С, в която
са използвани системни примитиви на ОС UNIX и LINUX:


// in general, the standard output stdout is line buffered.
// So unless the buffer is either full, or received a newline, the content is not flushed.
#include <unistd.h>
#include <stdio.h>
main( )
{
int a = 1000;
if ( fork() )   //в родителя сме? Защото в родителя се връща резултат >0, тоест true
{
a /= 2; // a = 500;
printf ("\nValue of a = %d", a); //Value of a = 500
}
else //в детето сме
{
	if ( fork() ) // то също става родител
	{
		a*=2; //a = 2000, тъй като а си пази копие на променливата
		printf ("\nValue of a = %d", a); //Value of a = 2000 !!!
		// !Изчезва тъй като излизаме от програмата а printf буферира cout-a. Буферът флъшва на всеки newline
		if ( execlp("ls","ls", "-l", 0 ) == -1 ) //излизаме от програмата и извеждаме ls -l резултата
		{
			//няма как да стигнем до тук
			a = a + 2;
			printf ("\nValue of a = %d", a);
		}
	}
	else   //във внука сме
	{
	a+=2; 
	printf ("\nValue of a = %d", a);//Value of a = 1002
	}
}
a++; //минават дядото и внука и всеки си инкрементира с по 1 своя резултат
printf ("\nValue of a = %d", a); //Value of a = 1003
								 // Value of a = 501
}
Output:
Value of a = 500
ls -l резултата
Value of a = 1002
Value of a = 1003
Value of a = 501