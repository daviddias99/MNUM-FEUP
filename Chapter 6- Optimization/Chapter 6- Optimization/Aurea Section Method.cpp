#include <iomanip>
#include <iostream>

using namespace std;

double func(double x) {

	return 5 * cos(x) - sin(x);
}


void aureaSection(double f(double), double limA, double limB, int numIter) {

	double x1 = limA, x2 = limB, x3, x4;
	double B = (sqrt(5) - 1) / 2;
	double A = B * B;



	for (int i = 0; i <= numIter; i++) {

		x3 = x1 + A * (x2 - x1);
		x4 = x1 + B * (x2 - x1);

		cout << i << " x1: " << x1 << " x2: " << x2 << " x3: " << x3 << " x4: " << x4 << " fx1: " << f(x1) << " fx2: " << f(x2) << " fx3: " << f(x3) << " fx4: " << f(x4) << endl;

		if (f(x3) < f(x4)) {

			x2 = x4;
			x4 = x3;
		}
		else {

			x1 = x3;
			x3 = x4;
		}


	}
	



}

int main()
{
	aureaSection(func, 2, 4, 2);


}
