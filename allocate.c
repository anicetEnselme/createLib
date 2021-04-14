#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h> 
#include <unistd.h> 
#include <stdbool.h>
#include <ctype.h>
#include "ma_lib.h"


int main()
{

	// This pointer will hold the
	// base address of the block created
	int* ptr;
	long int n;
	int i;
	//size_t taille;

	// Get the number of elements for the array
	n = 0;
	pid_t yo = getpid();
	printf("voici mon PID:%d et celui de mon père est :%d\n", yo,getppid());
	printf("Enter number of elements: %ld\n", n);

	// Dynamically allocate memory using malloc()
//	long int j=0;
	//char rep;
	//scanf("%s",&rep);
	while( n < 409600000000)
	{
		
			ptr = (int*)malloc(n);
			printf("Mémoires demandée : %ldbytes\n", n);
			get_metrics(yo);
			sleep(60);

	// Check if the memory has been successfully
	// allocated by malloc or not
	// for (int i = 0; i < 9999; ++i)
	// {
	// 	tab[i] = i;
	// }
	if (ptr == NULL) {
		printf("Memory not allocated.\n");
		exit(0);
	}
	else {

		// Memory has been successfully allocated
		printf("Memory successfully allocated using malloc.\n");

		// Get the elements of the array
		for (i = 0; i < n; ++i) {
			ptr[i] = i + 1;
		}

		// Print the elements of the array
		// printf("The elements of the array are: ");
		// for (i = 0; i < n; ++i) {
		// 	printf("%d, ", ptr[i]);
		// }
	}
	//j++;
	//scanf("%s",&rep);
	n += 4096;
	}
	return 0;
}
