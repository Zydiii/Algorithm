#include <iostream>
#include <vector>
using namespace std;

int KNAPSACK(int n, int C, vector<int> size, vector<int> value){
	vector<vector<int> > V;
	V.resize(n + 1);
	for (int i = 0; i <= n; i++)
		V[i].resize(C + 1);
	for (int i = 0; i <= n; i++) {
		V[i][0] = 0;
	}
	for (int j = 0; j <= C; j++) {
		V[0][j] = 0;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= C; j++) {
			V[i][j] = V[i - 1][j];
			if (size[i - 1] <= j) {
				V[i][j] = V[i][j] > V[i - 1][j - size[i - 1]] + value[i - 1] ? V[i][j] : V[i - 1][j - size[i - 1]] + value[i - 1];
			}
		}
	}
	return V[n][C];
}

int main(){
	int n;
	int C;
	vector<int> size;
	vector<int> value;
	cout << "n:  ";
	cin >> n;
	cout << "C:  ";
	cin >> C;
	cout << "size: " << endl;
	for (int i = 0; i < n; i++) {
		int j;
		cin >> j;
		size.push_back(j);
	}
	cout << "value: " << endl;
	for (int i = 0; i < n; i++) {
		int j;
		cin >> j;
		value.push_back(j);
	}
	int v = KNAPSACK(n, C, size, value);
	cout << v;
	system("pause");
	return 0;
}