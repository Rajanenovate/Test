#include <stdio.h>
#include <stdlib.h>

int curr_brk, def_brk, new_brk;

int main()
{
	int ret, *p;

	/*Grab current program break address*/
	curr_brk = sbrk(0);
	def_brk = curr_brk;
	printf("Current program break:\t %d\n", curr_brk);
	malloc_stats();
	getchar();

	/*change program location of program break using brk
	(Allocate 100 bytes of heap)*/
	//brk(curr_brk + 100);
	p = (int *)malloc(100);

	/*verfy changes*/
	curr_brk = sbrk(0);
	printf("\nAfter malloc................\n");
	printf("Program current break:\t %d\n", curr_brk);
	malloc_stats();
	getchar();

	/*Restore the old location of the program break using brk*/
	//brk(def_brk);
	free(p);
	curr_brk = sbrk(0);
	printf("\nAfter free..................\n");
	printf("Default program break:\t %d\n", curr_brk);
	malloc_stats();
	return 0;
}
