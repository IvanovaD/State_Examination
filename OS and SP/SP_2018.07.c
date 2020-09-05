//2018.07


Задача 5. В текущия каталог се намира текстов файл f1.txt със следното съдържаниe:
xyzabcd //8символа с newline
0123456789 // 11 символа с newline
ABCD // 5 символа с newline
//общо 24
Изпълнимият файл, получен след компилация на зададения по-долу програмен фрагмент, се
стартира със следния команден ред:
./a.out f1.txt f2.txt
Напишете какво ще бъде изведено на стандартния изход и какво ще бъде 
съдържанието на файловете
f1.txt и f2.txt след приключване на успешното изпълнение.

 lseek - reposition read/write file offset
  off_t lseek(int fd, off_t offset, int whence);
  RETURN VALUE
       Upon successful completion, lseek() returns the resulting offset location as measured in  bytes  from  the
       beginning of the file.  On error, the value (off_t) -1 is returned and errno is set to indicate the error.
	If whence is SEEK_SET, the file offset shall be set to offset bytes.

	If whence is SEEK_CUR, the file offset shall be set to its current location plus offset.

	If whence is SEEK_END, the file offset shall be set to the size of the file plus offset.

//The  dup()  system  call  creates  a  copy  of the file descriptor oldfd, using the lowest-numbered unused
      // descriptor for the new descriptor.

#include <stdio.h>
#include <fcntl.h>
main(int argc, char * argv[]) {
int des1, des2, k, broi, i = 0, status;
char buff[40], c;
if ((des1 = open(argv[1], O_RDWR))== -1){ //отваряме първия файл за четене и писане с дескриптор дес1
printf("\n Cannot open \n");
exit(1);
}
if ((des2 = open(argv[2], O_CREAT | O_TRUNC | O_RDWR, 0666)) == -1) { 
printf("\n Cannot open \n");
exit(1); //отваряме втория файл, ако не съществува го създаваме
// и го отваряме с rd wr permissions а ако съществува изтриваме старото съдържание
}
if (fork() == 0) { // създаваме нов процес и сме в детето?
broi = read(des1, buff, 22);  // четем от файл1 в буфера 22 симввола и връщаме броя прочетени
//преместваме файловия дескрипор на 23 позиция
write(1, buff, 10); //пишем на стандартния изход 10 символа от буфера 
//****** xyzabcd\n01

k = dup(1); //дупликираме стандартния изход, за да го запомним

close(1);   // и затваряме стандартния изход
dup(des1);  // дупликираме файловия дескр на файл 1, и той се отваря на мястото на ст изход
c = buff[i++]; // c = buff[0] = x
if (c <= '0' || c >= '9') { //ако c не е число, а то не е:
while (buff[i++] != '\n' && i < broi) //докато не стигнем до нов ред или до i = 22 
    write(1, "x", 1);  //пишем х във файл 1 от 23 символ,
//	защото почваме от 1, 6 пъти до нов ред xxxxxx\n
write(1, "\n", 1); // добавяме нов ред във файл 1
close(1);  // затваряме копието на фд на файл 1
dup(k);    //връщаме стария стандартен изход
write(1, buff, 4);  
//***** пишем на изхода xyza 
write(des2, buff, 12); //пишем в f2 първите 12 символа xyzabcd\n0123
} else {
write(1, buff, broi);
close(1);
dup(k);
write(1, "x\n", 2); 
}
lseek(des2, 0, 0);  //0 offset във file 2 и четем  от нулевия символ
write(des2, "x\n", 2); //пишем x\n във втория файл        x\nzabcd\n0123
close(des1); //затваряме на файл1 и на файл2 дескриптора
close(des2);
} else { //в родителя сме
wait( &status ); //чакаме детето да приключи
close(1);         // затваряме станд изход
dup(des1);     //дупликираме дескр на файл 1 защото родителя си има копие на des1
execlp("head", "head", "-2",argv[2],0);  //извършваме командата head с аргумент -2 
//върху втория файл  тоест първите два реда на втория файл които са x\n и zabcd\n
//1 и записваме в първия x\nzabcd  
//******   
execlp("wc", "wc", "-l", argv[1], 0); //не стигаме до този ред
}
execlp("grep", "grep", "x", "f1.txt", 0); //първия ред прихващаме и изкарваме на ст изход
//***** xyzabcd
//ABCxxxxxx

f1:xyzabcd
0123456789
ABCDxxxxxx
x\n
zabcd\n

f2:x\nzabcd\n0123

output:

xyzabcd
01xyzaxyzabcd
ABCxxxxxx
