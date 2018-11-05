#ifndef MATRIX.H
#define MATRIX.H

#include <iostream>
using namespace std;

class Matrix {
	int rows, cols, **m;
public:
	Matrix(const Matrix &);
	Matrix& operator=(const Matrix &);
	Matrix();
	~Matrix();
	int GetRow()const;
	int GetCol()const;
	Matrix& operator+=(const Matrix&);
	Matrix& operator+=(const double&);
	Matrix& operator-=(const Matrix&);
	Matrix& operator-=(const double&);
	Matrix& operator*=(const Matrix&);
	Matrix& operator*=(const double&);
	Matrix& operator/=(const double&);
	friend void operator+(Matrix);
	friend void operator-(Matrix);
	friend int operator+(Matrix, Matrix);
	friend int operator+(Matrix, double);
	friend int operator+(double, Matrix);
	friend int operator-(Matrix, Matrix);
	friend int operator-(Matrix, double);
	friend int operator-(double, Matrix);
	friend int operator*(Matrix, Matrix);
	friend int operator*(Matrix, double);
	friend int operator*(double, Matrix);
	friend int operator/(Matrix, double);
	friend int operator/(double, Matrix);
	friend int operator^(Matrix, int);
	int operator[](int);
	friend void operator==(Matrix, Matrix);
	friend void operator!=(Matrix, Matrix);
	friend istream& operator>>(istream&, Matrix&);
	friend ostream& operator<<(ostream&, Matrix);
};
Matrix* citire(istream&);
Matrix* afisare(ostream&);
#endif 