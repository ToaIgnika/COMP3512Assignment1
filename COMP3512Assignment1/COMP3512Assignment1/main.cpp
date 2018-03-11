#include <iostream>
#include <stdio.h>
#include <fstream>
#include "Matrix.hpp"
using namespace std;

int main() {
	int ar[] = { 0,1,1,0,1,0,1,0,1,1,0,0,0,0,0,0 };
	
	// connectivity_matrix G
	Matrix g = Matrix(ar, 16);
	// importance_matrix
	Matrix s = g;
	s.get_importance();
	// probability factor
	double p = 0.85;

	//M= 0.85 * S+ (1 -0.85) * Q

	Matrix q(4);
	q.set_q_matrix();
	//cout << q;
	//transition matrix m
	Matrix m = s * p;
	q = q * (1.0 - p);
	//cout << q;
	m += q;
	//The Markov Process need a col 1xN

	//cout << m;
	double* mark = m.markov();
	double* mark_ = m.markov();
	
	int xxx = 0;
	do {
		m.m_copy(mark, mark_);
		m.m_process(mark);
		
	} while (!m.m_check(mark, mark_));
	//} while (++xxx < 15);
	m.m_scale(mark);
	for (int r = 0; r < 4; r++) {
		cout << mark[r];
		cout << endl;
	}

	cout << endl;

	// create special matrix and special function
	// 

	system("pause");
	return 0;
}