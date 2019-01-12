#include <iostream>
#include <iomanip>

using namespace std;



double RK2Integral(double f(double, double), double startX, double startY, double step, double endX) {

	double y = startY;
	int i = 0;

	for (double x = startX; x < endX; x += step,i++) {

		cout << "i: " << i << " x: " << x << " y: " << y << endl;
		y = y + step * f(x + step / 2, y + step / 2 * f(x, y));

	}


	return y;
}

int main() {




	return 0;
}