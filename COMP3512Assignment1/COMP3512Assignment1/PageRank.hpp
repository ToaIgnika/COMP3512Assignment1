#pragma once
#include "Matrix.hpp"

class PageRank {
private:
	int n_size;
public:
	PageRank();
	PageRank(int n);
	double* markov();
	void m_process(double m[], Matrix mtrx);
	void m_copy(double m[], double m_[]);
	bool m_check(double m[], double m_[]);
	void m_scale(double m[]);
	void run(Matrix k);
};
