#include <iostream>
#include <vector>
#include <string>
using namespace std;

int LCS1(string a, string b) {
	int n = a.length();
	int m = b.length();
	vector<vector<int> > keep;
	keep.resize(n);
	for (int i = 0; i < n; i++){
		keep[i].resize(m);
	}
	for (int i = 0; i < a.length(); i++) {
		keep[i][0] = 0;
	}
	for (int j = 0; j < b.length(); j++) {
		keep[0][j] = 0;
	}
	for (int i = 1; i < a.length(); i++) {
		for (int j = 1; j < b.length(); j++) {
			if (a[i] == b[j])
				keep[i][j] = keep[i - 1][j - 1] + 1;
			else
				keep[i][j] = keep[i - 1][j] > keep[i][j-1] ? keep[i-1][j] : keep[i][j-1];
		}
	}
	return keep[a.length()-1][b.length()-1];
}

int main() {
	string a;
	string b;
	cout << "a:" << endl;
	cin >> a;
	cout << "b:" << endl;
	cin >> b;
	int max_common = LCS1(a, b);
	cout << max_common << endl;
	system("pause");
	return 0;
}