#include <stdlib.h>
#include <stdio.h>
#include "Queue.h"

int dequeue(int intArray[], int size) {
	//delete right-most element in the array by forgetting that it ever existed
	intArray[size - 1] = NULL;
	return (size - 1);
}
int enqueue(int** intArray, int size, int value) {
	int * _intArray = NULL;

	//make memory bigger to accomodate larger array
	_intArray = (int*)malloc((size + 1) * sizeof(int));

	if (_intArray == NULL)
		return -1;

	//Copy contents from original array into new memory location
	for (int i = 0; i < size; i++)
	{
		_intArray[i] = (*intArray)[i];
	}
	//deallocate the old memory block
	free(*intArray);
	
	*intArray = _intArray;

	//move all values over to the right
	for (int i = size; i >= 0; i--)
	{
		_intArray[i] = _intArray[i - 1];
	}

	//insert new value in the back of the line (left)
	_intArray[0] = value;

	return size + 1;
}
int getNext(int intArray[], int size) {
	//return rightmost/first inserted element
	return intArray[size-1];
}
void display(int intArray[], int size) {
	for (int i = 0; i < size; i++)
	{
		printf("| %d |", intArray[i]);
	}
}