#include <iostream>
#include <vector>
using namespace std;

void siftUP(vector<int> &A, int i){
	bool done = false;
	if (i == 1)
		return;
	while (i>1 && !done) {
		if (A[i] > A[i / 2]) {
			swap(A[i], A[i / 2]);
		}
		else
			done = true;
		i /= 2;
	}
}

void siftDOWN(vector<int> &A, int i, int n) {
	bool done = false;
	if (2 * i > n)
		return;
	while (2 * i <= n && !done) {
		i *= 2;
		if (i + 1 <= n && A[i + 1] > A[i])
			i++;
		if (A[i / 2] < A[i])
			swap(A[i / 2], A[i]);
		else
			done = true;
	}
}

void Insert(vector<int> &A, int x) {
	A.push_back(x);
	int n = A.size();
	siftUP(A, n);
}

void Delete(vector<int> &A, int i, int n) {
	if (i == n)
		return;
	int x = A[i], y = A[n];
	A[i] = y;
	A.erase(A.end() - 1);
	if (y >= x)
		siftUP(A, i);
	else
		siftDOWN(A, i, n);
}

int deleteMAX(vector<int> &A) {
	int x = A[1];
	int n = A.size();
	Delete(A, 1, n);
	return x;
}

void pA(vector<int> A) {
	for (int i : A)
		cout << i << "  ";
	cout << endl;
}

void iA(vector<int> &A) {
	int x;
	while(1){
		cin >> x;
		if (x == 0)
			break;
		A.push_back(x);
	};
}

void makeHEAP(vector<int> &A, int n) {
	for (int i = n / 2; i >= 1; i--)
		siftDOWN(A, i, n);
}

void sortHEAP(vector<int> &A) {
	int n = A.size();
	makeHEAP(A, n);
	for (int j = n; j >= 2; j--) {
		swap(A[1], A[j]);
		siftDOWN(A, 1, n - 1);
	}
}

int main() {
	vector<int> A;
	A.push_back(0);
	iA(A);
	siftUP(A, 10);
	pA(A);
	int n = A.size();
	siftDOWN(A, 1, n);
	pA(A);
	Insert(A, 18);
	pA(A);
	cout << deleteMAX(A) << endl;
	pA(A);
	system("pause");
}