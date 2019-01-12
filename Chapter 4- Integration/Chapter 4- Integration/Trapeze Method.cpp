
#include <iostream>
#include <iomanip>

using namespace std;

double func(double x) {


	return sqrt(1 + pow(1.5*exp(1.5*x), 2));
}

double trapezeIntegral(double f(double), double limA, double limB, double step) {

	double sum = 0;
	sum += f(limA) + f(limB);

	cout << "x: " << limA << endl;

	for (double x = limA + step; x < limB; x += step) {

		sum += 2 * f(x);

		cout << "x: " << x << endl;

	}

	cout << "x: " << limB << endl;

	sum *= step / 2;
	cout << "SUM: " << sum << endl;


	return sum;
}

int main()
{
	double S = trapezeIntegral(func, 0, 1, 0.25);
	cout << endl;
	double Sl = trapezeIntegral(func, 0, 1, 0.125);
	cout << endl;
	double Sll = trapezeIntegral(func, 0, 1, 0.0625);
	cout << endl;

	double QC = (Sl - S) / (Sll - Sl);
	double error = (Sll - Sl) / 3;

	cout << "Qc: " << QC << " Error: " << error << endl;
}

