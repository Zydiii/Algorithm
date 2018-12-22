#include <iostream>
#include <vector>
using namespace std;

struct gcd {
	int x;
	int y;
	int d;
};

int mode(int x, int N) {
	return x - x / N * N;
}

struct gcd extended_Euclid(int a, int b) {
	struct gcd g;
	if (b == 0) {
		g.x = 1;
		g.y = 0;
		g.d = a;
		return g;
	}
	g = extended_Euclid(b, mode(a, b));
	struct gcd c;
	c.x = g.y;
	c.y = g.x - a / b * g.y;
	c.d = g.d;
	return c;
}

int main() {
	int x, y;
	cout << "x:  ";
	cin >> x;
	cout << "y:  ";
	cin >> y;
	struct gcd g = extended_Euclid(x, y);
	cout << g.d << endl;
	system("pause");
}