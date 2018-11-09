#include <iostream>
#include <vector>
using namespace std;

void SPLIT(vector<int> &A, int &w, int low, int high) {
	int x = A[low];
	int i = low;
	for (int j = low + 1; j <= high; j++) {
		if (A[j] <= x) {
			i++;
			if (i != j) {
				int k = A[i];
				A[i] = A[j];
				A[j] = k;
			}
		}
	}
	int k = A[i];
	A[i] = A[low];
	A[low] = k;
	w = i;
}

void quicksort(vector<int> &A, int low, int high, int w) {
	if (low < high){
		SPLIT(A, w, low, high);
		quicksort(A, low, w - 1, w);
		quicksort(A, w + 1, high, w);
	}
}

int main() {
	vector<int> A;
	int size;
	cout << "size:  " << endl;
	cin >> size;
	cout << "x:  " << endl;
	for (int i = 0; i < size; i++) {
		int k;
		cin >> k;
		A.push_back(k);
	}
	quicksort(A, 0, size-1, 0);
	for (int i = 0; i < size; i++) {
		cout << A[i] << "  ";
	}
	system("pause");
	return 0;
}