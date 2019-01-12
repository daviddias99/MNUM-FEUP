#include <iostream>
#include <iomanip>

using namespace std;

double func(double x) {

	//return sin(x) + pow(x, 5) - 0.2*x + 0.5;
	return pow(x, 7) + 0.5*x - 1;

}

void regulaFalsi(double f(double), double limA, double limB, int numIter) {

	double a = limA, b = limB, w;

	for (int i = 0; i <= numIter; i++) {

		w = (a * f(b) - b * f(a)) / (f(b) - f(a));

		cout << setprecision(10) << i + 1 << "- " << "a: " << setw(15) << a << " b: " << setw(15) << b << " w: " << setw(15) << w << " fa: " << setw(15) << f(a) << " fb: " << setw(15) << f(b) << " fw:  " << setw(15) << f(w) << endl;

		if (f(a) * f(w) < 0)
			b = w;
		else
			a = w;

	}

}

int main() {

	regulaFalsi(func, 0, 1.2, 50);



	return 0;
}