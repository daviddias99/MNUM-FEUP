#include <iostream>
#include <iomanip>

using namespace std;

double func(double x) {


	//return sqrt(1 + pow(1.5*exp(1.5*x), 2));
	return exp(1.5*x);
}

double simpsonIntegral(double f(double), double limA, double limB, double step) {

	double sum = 0;
	double coef = 0;
	int exponent = 2;
	sum += f(limA) + f(limB);

	cout << "x: " << limA << endl;

	for (double x = limA + step; x < limB; x += step) {

		coef = pow(2, exponent);
		sum += coef * f(x);
		exponent = exponent % 2 + 1;

		cout << "x: " << x << endl;

	}

	cout << "x: " << limB << endl;

	sum *= step / 3;
	cout << setprecision(15) << "SUM: " << sum << endl;


	return sum;
}

int main()
{
	double S = simpsonIntegral(func, 2.5, 3, 0.125);
	cout << endl;
	double Sl = simpsonIntegral(func, 2.5, 3, 0.0625);
	cout << endl;
	double Sll = simpsonIntegral(func, 2.5, 3, 0.03125);
	cout << endl;

	double QC = (Sl - S) / (Sll - Sl);
	double error = (Sll - Sl) / 15;

	cout << "Qc: " << QC << " Error: " << error << endl;
}
