#include "Matrix.hpp"
#include "PageRank.hpp"
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <array>
using namespace std;

PageRank::PageRank() {

}

PageRank::PageRank(int n) {
	n_size = n;
}

double* PageRank::markov() {
	double* m = new double[n_size];
	for (int i = 0; i < n_size; ++i) {
		m[i] = 1.0;
	}
	return m;
};

void PageRank::m_process(double m[], Matrix mtrx) {
	double sum;
	double *m_ = new double[n_size];
	for (int r = 0; r < n_size; r++) {
		sum = 0;
		for (int r_ = 0; r_ < n_size; r_++) {
			sum += mtrx.get_value(r, r_)*m[r_];
		}
		m_[r] = sum;
	}
	for (int i = 0; i < n_size; ++i) {
		m[i] = m_[i];
	}
};

void PageRank::m_copy(double m[], double m_[]) {
	for (int i = 0; i < n_size; ++i) {
		m_[i] = m[i];
	}
}

bool PageRank::m_check(double m[], double m_[]) {
	for (int i = 0; i < n_size; ++i) {
		//cout << m[i] << "|" << m_[i] << "|" << fabs(m[i] - m_[i]) << "oi" << endl;
		if (fabs(m[i] - m_[i]) > 0.00001) {
			return 0;
		}
	}
	return 1;
}

void PageRank::m_scale(double m[]) {
	for (int i = 0; i < n_size; ++i) {
		m[i] /= (double)n_size;
	}
}

void PageRank::run(Matrix g) {
	
}
