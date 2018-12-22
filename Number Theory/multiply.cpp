#include <iostream>
using namespace std;

bool is_odd(int x) {
	return x - x / 2 * 2;
}

int multiply(int x, int y) {
	if (!y)
		return 0;
	int z = multiply(x, y / 2);
	if (!is_odd(y))
		return 2*z;
	return 2*z + x;
}

int main() {
	int x, y;
	cout << "x: ";
	cin >> x;
	cout << "y: ";
	cin >> y;
	cout << "result:" << multiply(x, y) << endl;
	system("pause");
}