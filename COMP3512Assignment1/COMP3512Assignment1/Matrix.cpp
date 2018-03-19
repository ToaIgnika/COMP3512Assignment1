#include <iostream>
#include <array>
#include "Matrix.hpp"
using namespace std;

/*
description:
default constructor for object of type Matrix.
precondition:
create an object of type Matrix.
postcondition:
create an object of size 1.
*/
Matrix::Matrix() {
	n_size = 1;
	m_grid = new double[n_size*n_size];
	m_grid[0] = 0;
}

/*
description:
constructor for object of type Matrix.
precondition:
n of type int as a size of the matrix.
postcondition:
create an matrix object of size n by n.
*/
Matrix::Matrix(int n) {
	if (n < 1) {
		cout << "wrong input. Failed to create an object with specified params. Default object was created instead" << endl;
		Matrix();
		return;
	}
	n_size = n;
	m_grid = new double[n_size*n_size];
	for (int i = 0; i < n_size*n_size; i++) {
		m_grid[i] = 0;
	}
}

/*
description:
constructor for matrix
precondition:
n[] of type int as an elements
k of type int as a size of an array
postcondition:
creates an Matrix of size k and populates with array n
*/
Matrix::Matrix(int n[], int k) {
	int n_check = (int)sqrt(k);
	//cout << n_check << endl;
	if (n_check*n_check != k) {
		cout << "wrong input. Failed to create an object with specified params. Default object was created instead" << endl;
		Matrix();
		return;
	}
	else {
		// since we are dealing w/ 1d array, need to be careful with the actual sizing
		n_size = n_check;
		m_grid = new double[n_size*n_size];
		for (int i = 0; i < n_size*n_size; i++) {
			m_grid[i] = n[i];
		}
	}

}

/*
description:
Copy constructor for Matrix class
precondition:
2 matrces
postcondition:
returns a copy of a matrix
*/
Matrix::Matrix(const Matrix &m) {
	n_size = m.n_size;
	m_grid = new double[n_size*n_size];
	for (int i = 0; i < n_size; i++) {
		for (int j = 0; j < n_size; j++) {
			set_value(i, j, m.m_grid[i*n_size + j]);
		}
	}
}

/*
description:
set value of a specific location in the matrix
precondition:
r as int for row
c as int for col
val as int for value
postcondition:
sets the value of the matrix to val
return:
void
*/
void Matrix::set_value(int r, int c, double val) {
	if (r < 0 || c < 0 || r >= n_size || c >= n_size) {
		cout << "wrong dimentions";
		return;
	}
	m_grid[(r*n_size) + c] = val;
}

/*
description:
get value at specific location
precondition:
r as int for row
c as int for col
postcondition:
return the value
return:
value of [r,c]
*/
double Matrix::get_value(int r, int c) {
	if (r < 0 || c < 0 || r >= n_size || c >= n_size) {
		cout << "wrong dimentions";
		return NULL;
	}
	return m_grid[(r*n_size) + c];
}

/*
description:
sets all values of matrix to 0
precondition:
matrix
postcondition:
clears all values of the matrix
*/
void Matrix::clear() {
	for (int i = 0; i < n_size*n_size; i++) {
		m_grid[i] = 0;
	}
}

/*
description:
returns the identity of the given matrix
precondition:
matrix
postcondition:
identity matrix
return:
return z as Matrix
*/
Matrix Matrix::identity() {

	Matrix z = Matrix(n_size);
	for (int i = 0; i < n_size; i++) {
		z.m_grid[i*n_size + i] = 1;
	}
	return z;
}

/*
description:
destructor
precondition:
matrix
postcondition:
matrix
*/
Matrix::~Matrix() {
	delete m_grid;
}

/*
description:
print out the matrix
precondition:
matrix
postcondition:
matrix
*/
void Matrix::print() {
	for (int i = 0; i < n_size; i++) {
		for (int j = 0; j < n_size; j++) {
			cout << m_grid[i*n_size + j] << " ";
		}
		cout << endl;
	}
}

/*
description:
operator <<
*/
ostream& operator<<(ostream& os, const Matrix& dt)
{
	for (int i = 0; i < dt.n_size; i++) {
		for (int j = 0; j < dt.n_size; j++) {
			os << dt.m_grid[i*dt.n_size + j] << " ";
		}
		os << endl;
	}
	return os;
}

/*
description:
operator ==
*/
bool operator== (const Matrix &m1, const Matrix &m2) {
	if (m1.n_size != m2.n_size) {
		return false;
	}
	else {
		for (int i = 0; i < m1.n_size*m1.n_size; i++) {
			if (m1.m_grid[i] != m2.m_grid[i]) {
				return false;
			}
		}
	}
	return true;
}

/*
description:
operator !=
*/
bool operator!= (const Matrix &m1, const Matrix &m2) {
	if (m1.n_size != m2.n_size) {
		return true;
	}
	else {
		for (int i = 0; i < m1.n_size*m1.n_size; i++) {
			if (m1.m_grid[i] != m2.m_grid[i]) {
				return true;
			}
		}
	}
	return false;
}

/*
description:
operator >
*/
bool operator> (const Matrix &m1, const Matrix &m2) {
	if (m1.n_size > m2.n_size) {
		return true;
	}
	return false;
}

/*
description:
operator <
*/
bool operator< (const Matrix &m1, const Matrix &m2) {
	if (m1.n_size < m2.n_size) {
		return true;
	}
	return false;
}

/*
description:
operator >=
*/
bool operator>= (const Matrix &m1, const Matrix &m2) {
	if (m1.n_size >= m2.n_size) {
		return true;
	}
	return false;
}

/*
description:
operator <=
*/
bool operator<= (const Matrix &m1, const Matrix &m2) {
	if (m1.n_size <= m2.n_size) {
		return true;
	}
	return false;
}

/*
description:
helper method to increment/decrement
*/
void Matrix::shifter(bool y) {
	if (y) {
		for (int i = 0; i < n_size*n_size; ++i) {
			++m_grid[i];
		}
	}
	else {
		for (int i = 0; i < n_size*n_size; ++i) {
			--m_grid[i];
		}
	}
}

/*
description:
operator ++ (pre)
*/
Matrix& Matrix::operator++() {
	shifter(true);
	return *this;
}

/*
description:
operator ++ (post)
*/
Matrix Matrix::operator++(int) {
	Matrix temp(*this);
	(*this).shifter(true);
	return temp;
}

/*
description:
operator -- (pre)
*/
Matrix& Matrix::operator--() {
	shifter(false);
	return *this;
}

/*
description:
operator -- (post)
*/
Matrix Matrix::operator--(int) {
	Matrix temp(*this);
	(*this).shifter(false);
	return temp;
}


/*
description:
operator =
*/
Matrix& Matrix::operator=(Matrix m) {
	swap(*this, m);
	return *this;
}

/*
description:
operator +
*/
Matrix Matrix::operator+(const Matrix& m) {
	Matrix m_ = Matrix(this->n_size);
	for (int i = 0; i < this->n_size*this->n_size; ++i) {
		m_.m_grid[i] = this->m_grid[i] + m.m_grid[i];
	}
	return m_;
}

/*
description:
operator -
*/
Matrix Matrix::operator-(const Matrix& m) {
	Matrix m_ = Matrix(this->n_size);
	for (int i = 0; i < this->n_size*this->n_size; ++i) {
		m_.m_grid[i] = this->m_grid[i] - m.m_grid[i];
	}
	return m_;
}

/*
description:
operator +=
*/
Matrix& Matrix::operator+=(const Matrix& m) {
	for (int i = 0; i < this->n_size*this->n_size; ++i) {
		this->m_grid[i] += m.m_grid[i];
	}
	return *this;
}

/*
description:
operator -=
*/
Matrix& Matrix::operator-=(const Matrix& m) {
	for (int i = 0; i < this->n_size*this->n_size; ++i) {
		this->m_grid[i] -= m.m_grid[i];
	}
	return *this;
}

/*
description:
operator *=
*/
Matrix& Matrix::operator*=(const Matrix& m) {
	double sum = 0;
	Matrix temp = *this;
	for (int r = 0; r < (*this).n_size; r++) {
		for (int c = 0; c < (*this).n_size; c++) {
			sum = 0;
			for (int r_ = 0; r_ < (*this).n_size; r_++) {
				sum += (*this).get_value(r, r_)*m.m_grid[r_*(*this).n_size + c];
			}
			temp.set_value(r, c, sum);
		}
	}
	*this = temp;
	return *this;
}

/*
description:
operator *=
*/
Matrix operator*(Matrix m1, const Matrix& m2) {
	Matrix m_ = Matrix(m1.n_size);
	// go through each row and ad
	double sum = 0;
	for (int r = 0; r < m1.n_size; r++) {
		for (int c = 0; c < m1.n_size; c++) {
			sum = 0;
			for (int r_ = 0; r_ < m1.n_size; r_++) {
				sum += m1.get_value(r, r_)*m2.m_grid[r_*m1.n_size + c];
			}
			m_.set_value(r, c, sum);
		}
	}
	return m_;
}

std::istream& operator>>(std::istream is, Matrix& matrix) {

	cin >> matrix.n_size;
	for (int i = 0; i < matrix.n_size; i++) {
		for (int j = 0; j < matrix.n_size; j++) {
			cin >> matrix.m_grid[i*matrix.n_size + j];
		}
	}
	return is;
}

// ASSIGNMENT FUNCTIONS LAMAO XOXOXO
void Matrix::get_importance() {
	Matrix i = *this;
	for (int r = 0; r < n_size; ++r) {
		for (int c = 0; c < n_size; ++c) {
			double col_sum = this->get_col_sum(c);
			if (col_sum == 0) {
				i.set_value(r, c, (double)1.0/n_size);
			}
			else {
				i.set_value(r, c, i.get_value(r,c)/col_sum);
			}
			
		}
	}
	*this = i;
}

int Matrix::get_col_sum(int c) {
	int sum = 0;
	for (int i = 0; i < n_size; ++i) {
		sum+=this->get_value(i, c);
	}
	return sum;
}

/*
description:
operator *
*/
Matrix Matrix::operator*(double m) {
	Matrix m_ = Matrix(this->n_size);
	for (int i = 0; i < this->n_size*this->n_size; ++i) {
		m_.m_grid[i] = this->m_grid[i] * m;
	}
	return m_;
}

void Matrix::set_q_matrix() {
	for (int i = 0; i < n_size*n_size; ++i) {
		m_grid[i] = (double)1 / n_size;
	}
}

double* Matrix::markov() {
	double* m = new double[n_size];
	for (int i = 0; i < n_size; ++i) {
		m[i] = 1.0;
	}
	return m;
};

void Matrix::m_process(double m[]) {
	double sum;
	double *m_ = new double[n_size];
	for (int r = 0; r < n_size; r++) {
			sum = 0;
			for (int r_ = 0; r_ < n_size; r_++) {
				sum += this->get_value(r, r_)*m[r_];
			}
			m_[r] = sum;
	}
	for (int i = 0; i < n_size; ++i) {
		m[i] = m_[i];
	}
};

void Matrix::m_copy(double m[], double m_[]) {
	for (int i = 0; i < n_size; ++i) {
		m_[i] = m[i];
	}
}

bool Matrix::m_check(double m[], double m_[]) {
	for (int i = 0; i < n_size; ++i) {
		if (fabs(m[i] - m_[i]) > 0.00001) {
			return 0;
		}
	}
	return 1;
}

void Matrix::m_scale(double m[]) {
	for (int i = 0; i < n_size; ++i) {
		m[i]/= (double) n_size;
	}
}