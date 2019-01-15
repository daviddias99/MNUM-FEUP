#include <iostream>
#include <iomanip>

using namespace std;

double func(double x, double y) {


	return 3 * x*x - x * y + 11 * y + y * y - 8 * x;
}

double dfuncdx(double x, double y) {

	return 6 * x - y - 8;
}

double dfuncdy(double x, double y) {

	return -x + 11 +2*y;
}

void gradient(double f(double, double), double dfdx(double, double), double dfdy(double, double), double startX, double startY, double startLambda, int numIter) {

	double x0 = startX;
	double y0 = startY;
	double xn, yn;
	double lambda = startLambda;

	for (int i = 0; i <= numIter; i++) {

		cout << i << "- x0: " << x0 << " y0: " << y0 << " f(x0,y0): " << f(x0,y0) << " dfdx0: " << dfdx(x0, y0) << " dfdy0: " << dfdy(x0, y0) << endl;

		xn = x0 - lambda * dfdx(x0, y0);
		yn = y0 - lambda * dfdy(x0, y0);

		if (f(xn, yn) < f(x0, y0)) {

			lambda *= 2;
			x0 = xn;
			y0 = yn;
		}
		else {

			lambda /= 2;
		}
		
	}

}



int main() {

	gradient(func, dfuncdx, dfuncdy, 2, 2, 0.5, 1);


}