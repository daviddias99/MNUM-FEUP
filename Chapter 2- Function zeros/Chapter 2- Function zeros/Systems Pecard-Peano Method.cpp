#include <iostream>
#include <iomanip>

using namespace std;

double func1(double x, double y)
{
	return sqrt((x*y + 5 * x - 1) / 2);
}

double func2(double x, double y)
{
	return sqrt(x + 3 * log(x));
}

void peanoSystems(double f1(double,double),double f2(double,double),double guessX, double guessY, int numIter){

	double x0 = guessX, y0 = guessY;
	double x, y;


	for (int i = 0; i <= numIter; i++) {

		cout<< i  << "- x: " << x0 << " y: " << y0 << endl;

		x = f1(x0, y0);
		y = f2(x0, y0);
		x0 = x;
		y0 = y;
	}



}


int main() {

	peanoSystems(func1, func2, 4, 4, 50);


	return 0;
}