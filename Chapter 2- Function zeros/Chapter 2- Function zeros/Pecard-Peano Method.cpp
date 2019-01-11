#include <iostream>
#include <iomanip>

using namespace std;


double func(double x) {


	//return 1.0 / 2 * sqrt(exp(x));
	return 2*log(2*x);
}


void pecardPeano(double f(double), double guess, int numIter) {

	double x0 = guess;
	double x;

	for (int i = 0; i <= numIter; i++) {

		cout << "x: " << x0 << endl;;

		x = f(x0);

		x0 = x;
	}


}

int main() {

	pecardPeano(func, 1.1, 2);
}