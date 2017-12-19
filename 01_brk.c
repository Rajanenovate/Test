#include <stdio.h>
#include <stdlib.h>

int curr_brk, def_brk, new_brk;

int main()
{
	/*Grab current program break address*/
	curr_brk = sbrk(0);
	def_brk = curr_brk;
	printf("Current program break: %d\n", curr_brk);
	getchar();

	/*change program location of program break using brk
	(Allocate 100 bytes of heap)*/
	brk(curr_brk + 100);

	/*verfy changes*/
	curr_brk = sbrk(0);
	printf("Now program current break: %d\n", curr_brk);
	getchar();

	/*Restore the old location of the program break using brk*/
	brk(def_brk);
	curr_brk = sbrk(0);
	printf("Default program break: %d\n", curr_brk);

	return 0;
}
