#include<bits/stdc++.h>
using namespace std;

// Simple binary search algorithm
int binarySearch(int arr[], int l, int r, int x)
{
	if (r >= l)
	{
		int mid = l + (r - l) / 2;
		if (arr[mid] == x)
			return mid;
		if (arr[mid] > x)
			return binarySearch(arr, l, mid - 1, x);
		return binarySearch(arr, mid + 1, r, x);
	}
	return -1;
}

// function takes an infinite size array and a key to be
//  searched and returns its position if found else -1.
// We don't know size of arr[] and we can assume size to be
// infinite in this function.
// NOTE THAT THIS FUNCTION ASSUMES arr[] TO BE OF INFINITE SIZE
// THEREFORE, THERE IS NO INDEX OUT OF BOUND CHECKING
int findPos(int arr[], int key)
{
	int l = 0, h = 1;

	// Find h to do binary search
	while (arr[h] < key)
	{
		l = h;        // store previous high
		h = 2 * h;    // double high index
	}

	//ab, l and h ke beech key lie krti hai, toh yaha se ham simple binary search lgake answer nikal skte hai
	// at this point we have updated low and
	// high indices, Thus use binary search
	// between them
	return binarySearch(arr, l, h, key);
}

int main()
{
	int arr[] = {3, 5, 7, 9, 10, 90, 100, 130,
	             140, 160, 170
	            };
	int ans = findPos(arr, 170);
	if (ans == -1)
		cout << "Element not found";
	else
		cout << "Element found at index " << ans;
	return 0;
}