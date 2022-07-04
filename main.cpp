#include <iostream>
#include <math.h>
#include <fstream>
#define PI 3.1415926
#define N 41 //mesh size
using namespace std;

void write(double* a, int x, int y);
int main() {
	/*Implementation*/

	//Problem Description
	int m_no = N;
	double m_grid[N][N] = { 0 };
	int i = 0, j = 0;
	double residual = 1;
	double residual_after = 1;
	double tol = pow(10, -7);
	double temp = 0;
	int iterations = 0;

	//Initialization
	for (i = 0; i < m_no; i++) {
		m_grid[i][0] = 0;
		m_grid[i][m_no - 1] = 0;
		m_grid[m_no - 1][i] = 0;
		m_grid[0][i] = sin(PI * i / (m_no - 1));
	}

	//main
	while (residual > tol) {
		iterations++;
		residual = 0;
		for (i = 1; i < m_no - 1; i++) {
			for (j = 1; j < m_no - 1; j++) {
				if (i == 0)
					break;
				temp = m_grid[i][j];
				m_grid[i][j] = (m_grid[i - 1][j] + m_grid[i + 1][j] + m_grid[i][j - 1] + m_grid[i][j + 1]) * 0.25;
				residual = residual + abs(m_grid[i][j] - temp);
			}
		}
	
		cout << "iterations:	" << iterations ;
		cout << "	residual:	" << residual << endl;

	}
	
    write(&m_grid[0][0], m_no, m_no);
	return 0;
}


void write(double* a, int x, int y) {
	ofstream myfile("result.csv");
	int i, j;
	for (i = 0; i < y; i++) {
		for (j = 0; j < x; j++) {
			myfile << *(a + i * x + j) << ",";
		}
		myfile << endl;
	}

	myfile.close();
	return;
}