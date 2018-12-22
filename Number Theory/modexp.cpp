#include <iostream>
#include <vector>
using namespace std;

bool is_odd(int x) {
	return x - x / 2 * 2;
}

int mode(int x, int N) {
	return x - x / N * N;
}

int modexp(int x, int y, int N) {
	if (y == 0)
		return 1;
	int z = modexp(x, y / 2, N);
	if (!is_odd(y))
		return mode(z*z, N);
	return mode(x*z*z, N);
}

int main() {
	int x, y, N;
	cout << "x:  ";
	cin >> x;
	cout << "y:  ";
	cin >> y;
	cout << "N:  ";
	cin >> N;
	cout << modexp(x, y, N) << endl;
	system("pause");
}