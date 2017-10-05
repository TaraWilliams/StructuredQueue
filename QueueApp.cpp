/*
* @author Tara Williams
*/

#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"
#pragma warning(disable:4996)


int main() {

	const int initialSize = 10;

	//make a quick array1 
	int* array1 = (int*)malloc(initialSize * sizeof(int));
	for (int i = 0; i < initialSize; i++)
		array1[i] = i;

	//display initial array1	
	printf("Array 1 upon creation: \n");
	display(array1, initialSize);
	

	int value = 0;
	int newSize = initialSize;
	bool done = false;
	char select = 'X';

	while (done == false) {

		select = 'X';
		printf("\nYour options:\n  Add an integer to the end of the line - 'A'\n  Delete first in line - 'D'\n  See what integer is next in line - 'N'\n  Show the entire queue - 'S'\n  Exit the program - 'E'\n");
		scanf("\n");
		scanf("%c", &select);

		switch (select) {

		case ('A'):
			printf("Enter the integer you want to insert:\n");
			scanf("\n");
			scanf(" %d", &value);
			
			newSize = enqueue(&array1, initialSize, value);
			break;

		case ('D'):
			newSize = dequeue(array1, newSize);
			break;

		case ('N'):
			printf("Next: %d", getNext(array1, newSize));
			break;

		case ('S'):
			display(array1, newSize);
			break;
			
		case ('E'):
			done = true;
			break;
			
		default:
			printf("Enter a valid response.\n");
			
		}
	}

	//prevent the console window from closing immediately
	system("pause");

	//Deallocate memory
	free(array1);

	return 0;


}