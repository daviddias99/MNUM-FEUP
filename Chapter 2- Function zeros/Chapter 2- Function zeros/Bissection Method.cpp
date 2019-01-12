
#include <iostream>
#include <iomanip>

using namespace std;

double func(double x ){

	return -10*sin(x) + pow(x, 3) +3.4;

}

void bissection(double f(double), double limA, double limB, double nIter ) {

	double a = limA, b = limB, m;

	for (int i = 0; i <= nIter; i++) {

		m = (a + b) / 2;

		cout << setprecision(10) << i+1 << "- " << "a: " << setw(15) << a << " b: " << setw(15) << b << " m: " << setw(15) << m << " fa: " << setw(15) << f(a) << " fb: " << setw(15) << f(b) << " fm:  " << setw(15) << f(m) << endl;
		
		if (f(a)*f(m) < 0)
			b = m;
		else
			a = m;

	}

}



int main()
{
	bissection(func, 1.5, 5.9, 6);
}

