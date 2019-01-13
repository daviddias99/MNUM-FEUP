#include <iostream>
#include <iomanip>

using namespace std;

double func(double x, double y) {

	//return y * y - 2 * x*y - 6 * y + 2 * x*x + 12;
	return sin(y) + y * y / 4 + cos(x) + x * x / 4 - 1;
}

double dfuncdx(double x, double y) {

	//return -2 * y + 4 * x;
	return -sin(x) + x / 2;
}

double dfuncdy(double x, double y) {

	//return 2 * y - 2 * x - 6;
	return cos(y) + y / 2;
}

double invHessian00(double x, double y) {

	return 1 / (1.0 / 2.0 - cos(x));
}

double invHessian01(double x, double y) {

	return 0;
}

double invHessian10(double x, double y) {

	return 0;
}

double invHessian11(double x, double y) {

	return 1 / (1.0 / 2.0 - sin(y));
}



void quadric(double f(double, double), double dfdx(double, double), double dfdy(double, double), double iH00(double, double), double iH01(double, double), double iH10(double, double), double iH11(double, double), double startX, double startY, int numIter) {

	double x0 = startX, y0 = startY;
	double xn, yn;

	for (int i = 0; i <= numIter; i++) {

		cout << i << "- x0: " << x0 << " y0: " << y0 << endl;

		xn = x0 - (iH00(x0, y0)*dfdx(x0, y0) + iH01(x0,y0) * dfdy(x0, y0));
		yn = y0 - (iH10(x0, y0)*dfdx(x0, y0) + iH11(x0,y0) * dfdy(x0, y0));

		x0 = xn;
		y0 = yn;
	}

}

int main() {


	quadric(func, dfuncdx, dfuncdy, invHessian00, invHessian01, invHessian10, invHessian11, 0, 0, 30);

}

