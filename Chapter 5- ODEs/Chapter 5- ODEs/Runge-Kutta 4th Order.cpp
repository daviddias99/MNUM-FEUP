#include <iostream>
#include <iomanip>

using namespace std;

double func(double x, double y) {


	return sin(y) + sin(2 * x);
}


double RK4Integral(double f(double, double), double startX, double startY, double step, double endX) {

	double y = startY;
	double dy1, dy2, dy3, dy4;
	int i = 0;
	double x;

	for ( x = startX; x < endX; x += step, i++) {

		cout << "i: " << i << " x: " << x << " y: " << y << endl;

		dy1 = step * f(x, y);
		dy2 = step * f(x + step / 2, y + dy1 / 2);
		dy3 = step * f(x + step / 2, y + dy2 / 2);
		dy4 = step * f(x + step, y + dy3);

		y = y + 1.0 / 6 * dy1 + 1.0 / 3 * dy2 + 1.0 / 3 * dy3 + 1.0 / 6 * dy4;

	}
	cout << "i: " << i << " x: " << x << " y: " << y << endl;

	return y;
}

int main() {

	double S = RK4Integral(func, 1, 0, 0.5, 1.5);
	cout << endl;
	double Sl = RK4Integral(func, 1, 0, 0.25, 1.5);
	cout << endl;
	double Sll = RK4Integral(func, 1, 0, 0.125, 1.5);
	cout << endl;

	double Qc = (Sl - S) / (Sll - Sl);
	double error = (Sll - Sl) / 15;

	cout << setprecision(15) << "Qc: " << Qc << " error: " << error;

	return 0;
}