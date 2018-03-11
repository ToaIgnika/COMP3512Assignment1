#pragma once
#include <iostream>
class Matrix {
private:
	int n_size;
	double *m_grid;
	void shifter(bool y);
public:
	Matrix();
	Matrix(int n);
	Matrix(int n[], int k);
	Matrix(const Matrix &m);
	void set_value(int r, int c, double val);
	double get_value(int r, int c);
	void clear();
	Matrix identity();
	~Matrix();
	void print();
	friend std::ostream& operator<<(std::ostream& os, const Matrix& dt);
	// == != < > <= >=
	friend bool operator== (const Matrix &m1, const Matrix &m2);
	friend bool operator!= (const Matrix &m1, const Matrix &m2);
	friend bool operator> (const Matrix &m1, const Matrix &m2);
	friend bool operator< (const Matrix &m1, const Matrix &m2);
	friend bool operator>= (const Matrix &m1, const Matrix &m2);
	friend bool operator<= (const Matrix &m1, const Matrix &m2);
	// pre/post ++|--
	Matrix& operator++();
	Matrix operator++(int);
	Matrix& operator--();
	Matrix operator--(int);
	// assignment operator
	friend void swap(Matrix& m1, Matrix& m2);
	Matrix& operator=(Matrix m);
	// +- += -= operator overloads pls kill me 
	Matrix operator+(const Matrix& m);
	Matrix operator-(const Matrix& m);
	Matrix& operator+=(const Matrix& m);
	Matrix& operator-=(const Matrix& m);
	friend Matrix operator*(Matrix m1, const Matrix& m2);
	Matrix& operator*=(const Matrix& m);
	friend std::istream& operator>>(std::istream is, Matrix& matrix);
	friend void swap(Matrix& first, Matrix& second)
	{
		std::swap(first.n_size, second.n_size);
		std::swap(first.m_grid, second.m_grid);
	}
	// assignment helpers
	void get_importance();
	int get_col_sum(int c);
	Matrix operator*(double m);
	void set_q_matrix();
	double* markov();
	void m_process(double m[]);
	void m_copy(double m[], double m_[]);
	bool m_check(double m[], double m_[]);
	void m_scale(double m[]);
};
