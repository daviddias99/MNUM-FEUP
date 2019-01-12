#include <iostream>
#include <iomanip>

using namespace std;

double func1(double x, double y, double z) {

	return -exp(-0.5 / (z + 273))*y;
}

double func2(double x, double y, double z) {

	return 30 * exp(-0.5 / (z + 273))*y - 0.5 * (z - 20);
}

pair<double, double> RK4Integral(double f(double, double, double), double g(double, double, double), double startX, double startY, double startZ, double endX, double step) {

	double x;
	int i = 0;
	double y0 = startY;
	double z0 = startZ;
	double y, z;
	double dy1, dy2, dy3, dy4, dz1, dz2, dz3, dz4;
	for (x = startX; x < endX; x += step, i++) {

		cout << "i: " << i << " x: " << x << " y: " << y0 << " z: " << z0 << endl;

		dy1 = step * f(x, y0, z0);
		dz1 = step * g(x, y0, z0);
		dy2 = step * f(x + step / 2, y0 + dy1 / 2,  z0 + dz1 / 2);
		dz2 = step * g(x + step / 2, y0 + dy1 / 2,  z0 + dz1 / 2);
		dy3 = step * f(x + step / 2, y0 + dy2 / 2,  z0 + dz2 / 2);
		dz3 = step * g(x + step / 2, y0 + dy2 / 2,  z0 + dz2 / 2);
		dy4 = step * f(x + step, y0 + dy3, z0 + dz3);
		dz4 = step * g(x + step, y0 + dy3, z0 + dz3);

		y = y0 + 1.0 / 6 * dy1 + 1.0 / 3 * dy2 + 1.0 / 3 * dy3 + 1.0 / 6 * dy4;
		z = z0 + 1.0 / 6 * dz1 + 1.0 / 3 * dz2 + 1.0 / 3 * dz3 + 1.0 / 6 * dz4;

		y0 = y;
		z0 = z;
	}

	cout << "i: " << i << " x: " << x << " y: " << y0 << " z: " << z0 << endl;

	return { y,z };

}



int main() {

	pair<double, double> S = RK4Integral(func1, func2, 0, 2.5, 25, 0.5, 0.25);
	cout << endl;
	pair<double, double> Sl = RK4Integral(func1, func2, 0, 2.5, 25, 0.5, 0.125);
	cout << endl;
	pair<double, double> Sll = RK4Integral(func1, func2, 0, 2.5, 25, 0.5, 0.0625);
	cout << endl;

	double Qc = (Sl.second - S.second) / (Sll.second - Sl.second);
	double error = Sll.second - Sl.second;

	cout << "Qc: " << Qc << " error: " << error << endl;


	return 0;
}

