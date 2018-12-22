#include <iostream>
#include <vector>
using namespace std;

struct div{
	int divide;
	int rem;
};

bool is_odd(int x) {
	return x - x / 2 * 2;
}

struct div divide(int x, int y) {
	struct div d;
	if (x == 0) {
		d.divide = 0;
		d.rem = 0;
		return d;
	}
	d = divide(x / 2, y);
	d.divide = 2 * d.divide;
	d.rem = 2 * d.rem;
	if (is_odd(x))
		d.rem++;
	if (d.rem >= y) {
		d.rem -= y;
		d.divide ++;
	}
	return d;
}

int main() {
	int x, y;
	cout << "x: ";
	cin >> x;
	cout << "y: ";
	cin >> y;
	struct div d = divide(x, y);
	cout << d.divide << endl;
	system("pause");
}