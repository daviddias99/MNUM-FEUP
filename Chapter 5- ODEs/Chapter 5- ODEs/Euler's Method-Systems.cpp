#include <iostream>
#include <iomanip>

using namespace std;

double func1(double x, double y, double z) {

	return -exp(-0.5 / (z + 273))*y;
}

double func2(double x, double y, double z) {

	return 30 * exp(-0.5 / (z + 273))*y - 0.5 * (z - 20);
}

pair<double,double> eulerIntegral(double f(double, double, double), double g(double, double, double), double startX, double startY, double startZ, double endX, double step) {

	double x ;
	double y0 = startY;
	double z0 = startZ;
	double y;
	double z;
	int i = 0;

	for (x = startX; x < endX; x += step,i++) {

		cout << "i: " << i << " x: " << x << " y: " << y0 << " z: " << z0 << endl;

		y = y0 + step * f(x, y0, z0);
		z = z0 + step * g(x, y0, z0);

		y0 = y;
		z0 = z;
	}

	cout << "i: " << i << " x: " << x << " y: " << y << " z: " << z << endl;

	return { y,z };
}



int main() {

	

	pair<double,double> S = eulerIntegral(func1, func2, 0, 2.5, 25, 0.5, 0.25);
	cout << endl;
	pair<double, double> Sl = eulerIntegral(func1, func2, 0, 2.5, 25, 0.5, 0.125);
	cout << endl;
	pair<double, double> Sll = eulerIntegral(func1, func2, 0, 2.5, 25, 0.5, 0.0625);
	cout << endl;

	double Qc = (Sl.second - S.second) / (Sll.second - Sl.second);
	double error = Sll.second - Sl.second;

	cout << "Qc: " << Qc << " error: " << error << endl;	

	return 0;
}