#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

double xFunc(double y, double z, double w) {

	return (25-0.5*y - 3*z - 0.25*w) / 6;
}

double yFunc(double x, double z, double w) {


	return (10-1.2*x-0.25*z-0.2*w) / 3;
}

double zFunc(double x, double y, double w) {

	return (7 + x - 0.25*y - 2 * w) / 4;
}

double wFunc(double x, double y, double z) {

	return (-12 -2*x-4*y-z) / 8;
}



void gJacobi(double xfunc(double, double, double), double yfunc(double, double,double), double zfunc(double, double,double), double wfunc(double, double, double), int nIter, double startX, double startY, double startZ, double startW) {

	double x0 = startX, y0 = startY, z0 = startZ, w0 = startW;
	double x, y, z, w;

	for (int i = 0; i < nIter; i++) {

		cout << i << "- x: " << x0 << " y: " << y0 << " z: " << z0 << " w: " << w0  << endl;

		x = xfunc(y0, z0, w0);
		y = yfunc(x0, z0, w0);
		z = zfunc(x0, y0, w0);
		w = wfunc(x0, y0, z0);

		x0 = x;
		y0 = y;
		z0 = z;
		w0 = w;

	}



}



int main() {

	gJacobi(xFunc, yFunc, zFunc, wFunc, 3, 2.12687, 2.39858, 3.99517, -3.73040);


	return 0;
}