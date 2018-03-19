#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "Matrix.hpp"
using namespace std;

void algo(Matrix g, int size, ostream& myfile) {
	// get importance_matrix
	Matrix s = g;
	s.get_importance();
	// set probability factor
	double p = 0.85;
	// get M from the formula: M= 0.85 * S+ (1 -0.85) * Q
	// create Q
	Matrix q(size);
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
	

	
	

	char val = 'A';
	// print the results
	for (int r = 0; r < size; r++) {
		cout << val << "="<< mark[r] << endl;
		myfile << val << "=" << mark[r] << endl;
		++val;
	}
	cout << endl << "BOI";
	myfile<< endl << "BOI";

}

/*
Void
*/
void file_parser(string name, ostream& myfile) {
	ifstream infile;
	infile.open(name);
	vector<int> numbers;
	int counter = 0;
	if (infile.is_open())
	{
		int num;
		while (infile >> num)
		{
			numbers.push_back(num);
		}
	}
	infile.close();
	int * a = &numbers[0];
	Matrix test = Matrix(a, ((int)numbers.size()));
	algo(test, (int)sqrt(numbers.size()), myfile);
}



int main() {
	// write to file :D :D :D
	ofstream myfile;
	myfile.open("results.txt");


	// get connectivity_matrix G
	//Matrix g = Matrix(ar, 16);
	/*
	[ 0, 0, 0, 1, 1, 0, 0, 0, 0, 0;
	1, 0, 0, 0, 0, 0, 1, 0, 1, 0;
	0, 0, 0, 0, 0, 0, 0, 1, 0, 0;
	0, 0, 0, 0, 0, 0, 1, 1, 0, 0;
	0, 1, 0, 0, 0, 1, 0, 1, 0, 0;
	0, 0, 0, 0, 0, 0, 0, 1, 0, 1;
	0, 1, 0, 1, 0, 1, 0, 0, 0, 0;
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0;
	0, 1, 1, 0, 0, 0, 1, 0, 0, 0;
	0, 1, 0, 0, 0, 0, 0, 0, 0, 0 ]
	A = 0.130816
	B = 0.268108
	C = 0.018188
	D = 0.054727
	E = 0.108890
	F = 0.079365
	G = 0.128962
	H = 0.015000
	I = 0.123972
	J = 0.071973
	*/
	cout << "-----------------------------------------------------" << endl;
	cout << "test 1" << endl;
	myfile << "-----------------------------------------------------" << endl;
	myfile << "test 1" << endl;

	
	file_parser("tester1.txt", myfile);
	/*
	[ 0, 1, 1, 1, 1, 0, 1, 1, 0, 1;
	1, 0, 1, 1, 1, 1, 1, 1, 1, 1;
	1, 1, 0, 1, 1, 1, 1, 1, 1, 1;
	1, 1, 1, 0, 1, 0, 0, 1, 1, 1;
	0, 1, 1, 0, 0, 1, 1, 1, 1, 1;
	1, 1, 0, 0, 1, 0, 1, 1, 1, 1;
	1, 1, 0, 1, 0, 1, 0, 1, 1, 1;
	1, 0, 1, 1, 0, 1, 0, 0, 1, 1;
	0, 1, 1, 1, 1, 1, 0, 1, 0, 1;
	1, 1, 1, 1, 1, 1, 1, 1, 1, 0 ] should generate a PageRank file that looks like this:
	A = 0.096501
	B = 0.117129
	C = 0.115544
	D = 0.093980
	E = 0.094919
	F = 0.092857
	G = 0.091111
	H = 0.084697
	I = 0.094869
	J = 0.118393
	*/
	cout << "-----------------------------------------------------" << endl;
	cout << "test 2" << endl;
	myfile << "-----------------------------------------------------" << endl;
	myfile << "test 2" << endl;
	file_parser("tester2.txt", myfile);
	/*
	[ 0, 1, 1, 1, 1, 1, 1;
	0, 0, 0, 1, 0, 1, 1;
	0, 1, 0, 1, 1, 1, 1;
	1, 1, 1, 0, 0, 1, 1;
	1, 1, 0, 0, 0, 1, 1;
	0, 0, 1, 0, 1, 0, 1;
	1, 1, 0, 1, 0, 1, 0 ] should generate a PageRank file that looks like this:
	A = 0.190277
	B = 0.095439
	C = 0.148268
	D = 0.171204
	E = 0.129194
	F = 0.120589
	G = 0.145029
	*/
	cout << "-----------------------------------------------------" << endl;
	cout << "test 3" << endl;
	myfile << "-----------------------------------------------------" << endl;
	myfile << "test 3" << endl;
	file_parser("tester3.txt", myfile);
	/*
	0 1 1 0
	1 0 1 0
	1 1 0 0
	0 0 0 0
	rank = 1.2698 / 3.999 = 0.3175
	1.2698 / 3.999 0.3175
	1.2698 / 3.999 0.3175
	0.1905 / 3.999 0.0476
	*/
	cout << "-----------------------------------------------------" << endl;
	myfile.close();

	system("pause");
	return 0;
}