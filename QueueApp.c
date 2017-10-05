/*
* @author Tara Williams
*/

#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"
#pragma warning(disable:4996)


int main() {

	//initialize array addresses
	Queue* array1 = NULL;

	array1 = new Queue();

	//load contents into array1
	for (int i = 0; i < 15; i++)
		array1->enqueue(i);

	//display array1
	array1->display();

	int value = 0;
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
			array1->enqueue(value);
			break;

		case ('D'):
			array1->dequeue();
			break;

		case ('N'):
			printf("Next: %d", array1->getNext());
			break;

		case ('S'):
			array1->display();
			break;

		case ('E'):
			done = true;
			break;

		default:
			printf("Enter a valid response.\n");

		}
	}

	//keep window open
	system("pause");

	//release the memory
	delete array1;

}