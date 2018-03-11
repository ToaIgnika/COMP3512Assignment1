#include <iostream>
#include <stdio.h>
#include <fstream>
#include "Matrix.hpp"
using namespace std;

int main() {
	int ar[] = { 0,1,1,0,1,0,1,0,1,1,0,0,0,0,0,0 };
	
	// get connectivity_matrix G
	Matrix g = Matrix(ar, 16);

	// get importance_matrix
	Matrix s = g;
	s.get_importance();
	// set probability factor
	double p = 0.85;
	// get M from the formula: M= 0.85 * S+ (1 -0.85) * Q
	// create Q
	Matrix q(4);
	q.set_q_matrix();
	// get transition matrix m
	Matrix m = s * p;
	q = q * (1.0 - p);
	m += q;
	// create Markov arrays
	double* mark = m.markov();
	double* mark_ = m.markov();
	
	// process Markov stuff until it gets done
	do {
		m.m_copy(mark, mark_);
		m.m_process(mark);
		
	} while (!m.m_check(mark, mark_));
	
	// final step - scale the markov matrix
	m.m_scale(mark);

	// print the results
	for (int r = 0; r < 4; r++) {
		cout << mark[r];
		cout << endl;
	}
	cout << endl << "BOI";

	system("pause");
	return 0;
}