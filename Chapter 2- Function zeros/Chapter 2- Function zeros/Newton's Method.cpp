#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double func(double x) {


	return x -2.6 + pow(cos(x+1.1),3);
}

double dfunc(double x) {


	return 1 - 3 *cos(x+1.1)*cos(x+1.1)*sin(x + 1.1);
}

void newtonsMethod(double f(double), double df(double), double guess, int numIter) {

	double x0 = guess;
	double x = x0;

	for (int i = 0; i <= numIter; i++) {

		cout << "x: " << x << " fx: " << f(x) << " dfx " << df(x) << endl;

		x = x0 - f(x0) / df(x0);

	}


}



int main() {

	newtonsMethod(func, dfunc, 1.8, 2);
	return 0;
}