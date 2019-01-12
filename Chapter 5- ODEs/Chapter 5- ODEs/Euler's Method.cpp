#include <iostream>
#include <iomanip>	

double func(double x, double y) {


	return x*(x/2+1)*y*y*y+(x+5.0/2)*y*y;
}

using namespace std;

double eulerIntegral(double f(double, double), double startX, double startY, double step, double endX) {

	double y = startY;
	int i = 0;
	double x;

	for (x = startX; x < endX; x += step,i++) {

		cout << "i: " << i << " x: " << x << " y: " << y << endl;
		y = y + step * f(x, y);
	}
	cout << "i: " << i << " x: " << x << " y: " << y << endl;

	return y;
}



int main()
{
    
	double S = eulerIntegral(func, 1, 0.1, 0.08, 1.8);
	cout << endl;
	double Sl = eulerIntegral(func, 1, 0.1, 0.04, 1.8);
	cout << endl;
	double Sll = eulerIntegral(func, 1, 0.1, 0.02, 1.8);
	cout << endl;

	double Qc = (Sl - S) / (Sll - Sl);
	double error = Sll - Sl;

	cout << "Qc: " << Qc << " error: " << error << endl;

}


