#include <stdlib.h>
#include <stdio.h>
#include "Queue.h"



Queue::Queue() {
	cursize = 0;
	maxsize = initialSize;
	data = (int*)malloc(initialSize * sizeof(int));
}

Queue::~Queue() {
	free(data);
}

bool Queue::dequeue() {
	//delete right-most element in the array by forgetting that it ever existed
	data[cursize - 1] = NULL;
	cursize--;
	return true;
}


bool Queue::enqueue(int value) {
	int * _intArray = NULL;

	//if the size is at too much already
	if (cursize == maxsize) {

		//make temp
		int* _data = NULL;

		//get bigger possible space
		_data = (int*)malloc(sizeof(int) * maxsize * 2);
		if (_data == NULL)
			return false;

		maxsize = maxsize * 2;

		//copy old info to bigger space
		for (int i = 0; i < cursize; i++)
			_data[i] = data[i];

		//delete small space and assimilate the personality of temp
		free(data);
		data = _data;
	}

	//move everything to the right to make space in back of line
	for (int i = cursize; i > 0; i--)
		data[i] = data[i - 1];
	//put new value in back of line
	data[0] = value;

	cursize++;
	return true;

}

int Queue::getSize() {
	return cursize;
}

int Queue::getNext() {
	//return rightmost/first inserted element
	return data[cursize-1];
}

void Queue::display() {
	printf("Array:\n");

	for (int i = 0; i < cursize; i++)
	{
		printf("%d\n", data[i]);
	}
	printf("\n");
}