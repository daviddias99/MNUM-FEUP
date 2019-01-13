
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

typedef vector<vector<double>> Matrix;

void rowop(Matrix& M, int a, int b, double k) {

	for (int i = 0; i < M.at(a).size(); i++)
		M[a][i] -= M[b][i] * k;
}


void gauss(Matrix& M) {

	for (int i = 0; i < M.size(); i++) {

		rowop(M, i, i, 1 - 1 / M[i][i]);

		for (int j = 0; j < M.size(); j++) {

			if (j != i)
				rowop(M, j, i, M[j][i]);
		}
	}
}

void print(Matrix& M) {

	for (int i = 0; i < M.size(); i++) {

		for (int j = 0; j < M.at(0).size(); j++) {

			cout << M[i][j] << "\t\t\t";

		}
		cout << endl;
	}

}



int main()
{
	/*
	Matrix A = { {1,1,1,3 }, {2,3,7,0 }, {1,3,-2,17 } };
	gauss(A);
	print(A);
	cout << endl << endl;
	Matrix M = { {0.1,0.5,3,0.25,0 }, {1.2,0.2,0.25,0.2,1 }, {-1,0.25,0.3,2,2},{2,0,1,0.4,3} };
	gauss(M);
	print(M);
	cout << endl << endl; */
	Matrix E = { {0.1,0.5,3,0.25,0.47242 }, {1.2,0.2,0.25,0.2,0.47242 }, {-1,0.25,0.3,2,0.47242},{2,0,1,0.4,0.47242} };
	gauss(E);
	print(E);

	return 0;
}


