#include<bits/stdc++.h>
using namespace std;

int countSmallerElements(vector<vector<int>> arr, int assumedMedian) {
	//here, in this function me bhi hm binary search use krke, assumedMedian se <= elements ka count find krege
	int countOfSmallerElements = 0;
	for (int i = 0; i < arr.size(); i++) {
		//all rows are sorted, given in question
		//every row me hm binary search se count of <= assumedMedian find krege
		int start = 0;
		int end = arr[0].size() - 1;

		while (start <= end) {
			int mid = start + (end - start) / 2;
			if (arr[i][mid] <= assumedMedian) { //move right
				start = mid + 1;
			}
			else {
				end = mid - 1;
			}
		}

		//start vo index me hoga jo just greater than the assumedMedian, so no of smaller element start(index) hoge(think, CS)(as the row is sorted)
		countOfSmallerElements += start;
	}
	return countOfSmallerElements;
}

int medianOfRowWiseSortedMatrix(vector<vector<int>> arr) {
	//WV recommended
	int N = arr.size() * arr[0].size(); //total element in the matrix
	int medianIndex = N / 2; //given in question that no of elements are always odd, so median hmesa n/2 hi hoga(think, CS)
	int start = 1;
	int end = 2000; //given in question the range of number

	while (start <= end) {
		int assumedMedian = start + (end - start) / 2; //aka mid
		//no of elements less than or equal to the assumed median
		int noOfSmallerElements = countSmallerElements(arr, assumedMedian);

		if (noOfSmallerElements <= medianIndex) { //move right, km h or hme or badane h so move right
			start = assumedMedian + 1;
		}
		else { //move left
			end = assumedMedian - 1;
		}

	}

	return start; //ispe kahi sochna ki start hi kyo return kia h(Think, CS)
}

int main() {
	/*
	NOTE: WV highly recommended
	QUESTION: https://takeuforward.org/data-structure/nth-root-of-a-number-using-binary-search/
	VIDEO LINK: https://www.youtube.com/watch?v=WjpswYrS2nY&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=63
	*/
	// vector<vector<int>> arr = {{2, 6, 9}, {1, 5, 11}, {3, 7, 8}};
	vector<vector<int>> arr = {{1, 3}, {1, 2, 3}};
	cout << medianOfRowWiseSortedMatrix(arr);
}