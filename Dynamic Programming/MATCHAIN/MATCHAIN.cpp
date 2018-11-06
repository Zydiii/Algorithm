#include <iostream>
#include <vector>
#include <string>
#include <limits>
using namespace std;

int MATCHAIN(vector<int> size, int n){
	vector<vector<int> > C;
	C.resize(n + 1);
	for (int i = 0; i <= n; i++) {
		C[i].resize(n + 1);
	}
	for (int i = 1; i <= n; i++) {
		C[i][i] = 0;
	}
	for (int d = 1; d <= n - 1; d++) {
		for (int i = 1; i <= n - d; i++) {
			int j = i + d;
			C[i][j] = 2147483647;
			for (int k = i + 1; k <= j; k++) {
				int x = C[i][k - 1] + C[k][j] + size[i - 1] * size[k - 1] * size[j];
				C[i][j] = C[i][j] < x ? C[i][j] : x;
			}
		}
	}
	return C[1][n];
}
int main() {
	vector<int> size;
	int s;
	int n;
	cout << "n:" << endl;
	cin >> n;
	int i = 0;
	cout << "size" << ":" << endl;
	while (i <= n)
	{
		cin >> s;
		size.push_back(s);
		i++;
	}
	int match = MATCHAIN(size, n);
	cout << match << endl;
	system("pause");
	return 0;
}