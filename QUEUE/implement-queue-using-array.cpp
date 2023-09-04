#include <bits/stdc++.h>
using namespace std;

// A structure to represent a queue
class Queue {
public:
	int front, rear, size;
	int capacity;
	int* array;

	Queue(int cap) {
		capacity = cap;
		array = new int[capacity];
		front = 0;
		// This is important, see the enqueue
		rear = capacity - 1;
		size = 0;
	}

	// Queue is full when size
	// becomes equal to the capacity
	int isFull()
	{
		return (size == capacity);
	}

	// Queue is empty when size is 0
	int isEmpty()
	{
		return (size == 0);
	}

	// Function to add an item to the queue.
	// It changes rear and size
	// in queue --> addition rear se hota and removal front se
	void enqueue(int item)
	{
		if (isFull()) {
			cout << "queue is full" << endl;
			return;
		}
		rear = (rear + 1)
		       % capacity;
		array[rear] = item;
		size = size + 1;
		cout << item << " is enqueued" << endl;
	}

	// Function to remove an item from queue.
	// It changes front and size
	int dequeue()
	{
		if (isEmpty()) {
			cout << "queue is empty" << endl;
			return INT_MIN;
		}
		int item = array[front];
		front = (front + 1)
		        % capacity;
		size = size - 1;
		cout << item << " is dequeued" << endl;
		return item;
	}

	// Function to get front of queue
	int getFront()
	{
		if (isEmpty()) {
			cout << "queue is empty" << endl;
			return INT_MIN;
		}
		return array[this->front];
	}

	// Function to get rear of queue
	int getRear()
	{
		if (isEmpty()) {
			cout << "queue is empty" << endl;
			return INT_MIN;
		}
		return array[rear];
	}

};


// Driver code
int main()
{
	/*
	NOTE: please refer to the design circular dequeue question first
	*/
	Queue queue(3);

	queue.enqueue(10);
	queue.dequeue();
	queue.enqueue(20);
	queue.dequeue();

}

// This code is contributed by rathbhupendra
