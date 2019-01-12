#include <iostream>
#include <iomanip>

using namespace std;





double func1(double x, double y) {

	return x * x - y - 2;
}

double func2(double x, double y) {

	return -x + y*y - 2;
}

double dfunc1dx(double x, double y) {

	return 2 * x;
}

double dfunc1dy(double x, double y) {

	return -1;
}

double dfunc2dx(double x, double y) {

	return -1;
}

double dfunc2dy(double x, double y) {

	return 2 * y;
}


void newtonSystems(double f1(double, double), double f2(double,double), double df1dx(double,double), double df1dy(double, double ), double df2dx(double, double), double df2dy(double, double), double guessx, double guessy, int numIter) {

	double x0 = guessx;
	double y0 = guessy;
	double x = x0;
	double y = y0;

	for (int i = 0; i <= numIter; i++) {

		x = x0  - (f1(x0, y0)*df2dy(x0, y0) - f2(x0, y0)*df1dy(x0, y0)) / (df1dx(x0, y0)*df2dy(x0, y0) - df2dx(x0, y0)*df1dy(x0, y0));
		y = y0  - (f2(x0, y0)*df1dx(x0, y0) - f1(x0, y0)*df2dx(x0, y0)) / (df1dx(x0, y0)*df2dy(x0, y0) - df2dx(x0, y0)*df1dy(x0, y0));

		cout << i << "-x0: " << x0 << " y0: " << y0 << " x: " << x << " y: " << y << endl;
		x0 = x;
		y0 = y;
	}





}

int main() {


	newtonSystems(func1, func2, dfunc1dx, dfunc1dy, dfunc2dx, dfunc2dy, 1.5, 0.8, 2);



	return 0;
}