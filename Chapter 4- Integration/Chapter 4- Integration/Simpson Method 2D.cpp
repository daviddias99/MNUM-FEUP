#include <iostream>
#include <iomanip>

using namespace std;

//function to be integrated
double function(double x, double y)
{
	return pow(exp(1), y - x);
}

int simpsonDoubleCoef(double limAX, double  limBX, double limAY, double limBY, double x, double y) {

	if (((x == limAX) || (x == limBX)) && ((y == limAY) || (y == limBY)))
		return 1;
	else if ((x == limAX) || (x == limBX) || (y == limAY) || (y == limBY))
		return 4;
	else
		return 16;

}

double simpsonIntegral(double limAX, double  limBX, double limAY, double limBY, int nIntervals, double function1(double, double)) {

	double stepX = (limBX - limAX) / 2;
	double stepY = (limBY - limAY) / 2;

	double intResultSimp = 0;


	double xValue = limAX;

	while (xValue <= limBX)
	{
		double yValue = limAY;

		while (yValue <= limBY)
		{
			double fValue = function1(xValue, yValue);

			int coef = simpsonDoubleCoef(limAX, limBX, limAY, limBY, xValue, yValue);

			intResultSimp += coef * fValue;

			yValue += stepY;
		}

		xValue += stepX;
	}

	return stepX * stepY / 9 * intResultSimp;

}

int main() {

	//Lower bound
	double limAX = 0;
	double limAY = 0;

	//Upper bound
	double limBX = 0.5;
	double limBY = 0.5;

	int nIntervals = 4;

	double intResult1 = simpsonIntegral(limAX, limBX, limAY, limBY, nIntervals, function);

	return 0;
}

