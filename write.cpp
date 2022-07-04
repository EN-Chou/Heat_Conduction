#include "write.h"
#include <fstream>
#include <iostream>
using namespace std;


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