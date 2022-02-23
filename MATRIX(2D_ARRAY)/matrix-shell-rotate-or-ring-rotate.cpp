#include <bits/stdc++.h>
using namespace std;

//****************************
// NOTE: INPUT FOR CONSTRUCT MATRIX.
// 3
// 4
// 11
// 12
// 13
// 14
// 21
// 22
// 23
// 24
// 31
// 32
// 33
// 34
//*******************************

vector<vector<int>>  constructMatrix() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> arr(n, vector<int> (m, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	return arr;
}

void displayMatrix(vector<vector<int>> arr) {
	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < arr[i].size(); j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

void rotateOneD(vector<int> *arr, int rotate) {
	//***********************
	// LOGIC: 1. REVERSE PART 1
	// 2. REVERSE PART 2
	// 3. REVERSE THE WHOLE ARRAY
	//*****************************
	rotate = rotate % arr->size();
	// handling negative rotations
	if (rotate < 0) {
		rotate = rotate + arr->size();
	}
	// 3 step process (remember) --> see above comment
	std::reverse(arr->begin(), arr->end() - rotate );
	std::reverse(arr->end() - rotate, arr->end());
	std::reverse(arr->begin(), arr->end());
}

vector<int> fillOnedFromShell(vector<vector<int>> *arr, int shell) {
	int minr = shell - 1;
	int minc = shell - 1;
	int maxr = arr->size() - shell;
	int maxc = arr[0].size() - shell;
	// the above things are the result of critical thinking draw diagram and think about it.

	// finding shell size
	// formula(think): shellSize = left wall + bottom wall + right wall + top wall - 4(bcoz corner are taken twice)
	// (or) shellSize = 2*(left wall) + 2*(top wall)

	// int shellSize = (maxr - minr + 1) + (maxc - minc + 1) + (maxr - minr + 1) + (maxc - minc + 1) - 4; // think using diagram
	// after simplification we the get formal of shell size as
	int shellSize = 2 * (maxr - minr +  maxc - minc);
	vector<int> resOneDArray(shellSize);
	int idx = 0;
	// left wall
	for (int i = minr; i <= maxr; i++) {
		resOneDArray[idx] = (*arr)[i][minc];
		idx++;
	}
	minc++;
	// bottom wall
	for (int j = minc; j <= maxc; j++) {
		resOneDArray[idx] = (*arr)[maxr][j];
		idx++;
	}
	maxr--;
	// right wall
	for (int i = maxr; i >= minr; i--) {
		resOneDArray[idx] = (*arr)[i][maxc];
		idx++;
	}
	maxc--;
	// top wall
	for (int j = maxc; j >= minc; j--) {
		resOneDArray[idx] = (*arr)[minr][j];
		idx++;
	}
	minr++;
	return resOneDArray;

}

void fillShellFormOneD(vector<vector<int>> *arr, int shell, vector<int> resOneDArray) {
	int minr = shell - 1;
	int minc = shell - 1;
	int maxr = arr->size() - shell;
	int maxc = arr[0].size() - shell;
	// the above things are the result of critical thinking draw diagram and think about it.
	int idx = 0;
	// left wall
	for (int i = minr; i <= maxr; i++) {
		(*arr)[i][minc] = resOneDArray[idx];
		idx++;
	}
	minc++;
	// bottom wall
	for (int j = minc; j <= maxc; j++) {
		(*arr)[maxr][j] =	resOneDArray[idx];
		idx++;
	}
	maxr--;
	// right wall
	for (int i = maxr; i >= minr; i--) {
		(*arr)[i][maxc] = 	resOneDArray[idx];
		idx++;
	}
	maxc--;
	// top wall
	for (int j = maxc; j >= minc; j--) {
		(*arr)[minr][j] = resOneDArray[idx];
		idx++;
	}
	minr++;
}

void shellRotate(int shell, int rotate, vector<vector<int>> *arr) {
	vector<int> oned = fillOnedFromShell(arr, shell);

	rotateOneD(&oned, rotate);
	fillShellFormOneD(arr, shell, oned);
}


int main()
{
	vector<vector<int>> arr;
	arr = constructMatrix();
	displayMatrix(arr);
	//*************************
	// STEPS:
	// 1. GIVEN SHELL KO 1D ARRAY ME CONVERT KARO
	// 2. 1D ARRAY KO GIVEN ROTATION SE ROTATE KARO
	// 3. 1K ARRAY KO VAPIS SE SHELL ME STORE KARO.
	//******************************************
	shellRotate(2, 1, &arr);
	cout << "after shell rotation" << endl;
	displayMatrix(arr);


}