#include "matrix.h"
Matrix::Matrix(const Matrix & ob)
{
	rows = ob.rows;
	cols = ob.cols;
	m = new int *[rows];
	for (int i = 0; i < rows; i++)
		m[rows] = new int[cols];
	{
		for (int j = 0; j < cols; j++)
			m[rows][cols] = ob.m[rows][cols];
	}
}
Matrix& Matrix::operator=(const Matrix & ob)
{
	if (this != &ob) 
	{
		rows = ob.rows;
		cols = ob.cols;
		m = new int *[rows];
		for (int i = 0; i < rows; i++)
			m[rows] = new int[cols];
		{
			for (int j = 0; j < cols; j++)
				m[rows][cols] = ob.m[rows][cols];
		}
	}
	return *this;
}
Matrix* citire(istream& cin)
{
	cin >> rows;
	cin >> cols;
	for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
	{
				cout << "m[i][j]: " << "\n";
			cin >> m[i][j];
	}
}
Matrix::Matrix()
{
	rows = 0;
	cols = 0;
	m = NULL;
}
Matrix::~Matrix()
{
	rows = 0;
	cols = 0;
	delete[] m;
}
Matrix* afisare(ostream& cout)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			cout << m[i][j];
		cout << "\n";
	}
}
int Matrix::GetRow()const
{
	return rows;
}
int Matrix::GetCol()const
{
	return cols;
}
Matrix& Matrix::operator+=(const Matrix& mtrix)
{
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
		{
			if (m[i] != mtrix.m[j])
				cout << "imposibil";
			else
				m[i][j] += mtrix.m[i][j];
		}
	return *this;
}
Matrix& Matrix::operator+=(const double& b)
{
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
	{
				m[i][j] += b;
	}
	return *this;
}
Matrix& Matrix::operator-=(const Matrix& mtrix)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			if (m[i] != mtrix.m[j])
				cout << "imposibil";
			else
				m[i][j] -= mtrix.m[i][j];
	}
	return *this;
}
Matrix& Matrix::operator-=(const double& b)
{
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
		{
			m[i][j] -= b;
		}
	return *this;
}
Matrix& Matrix::operator*=(const Matrix& mtrix)
{
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			if (m[i] != mtrix.m[j])
				cout << "imposibil";
			else
			{
				for (int i = 0; i < rows; i++)
				{
					for (int j = 0; j < mtrix.cols; j++)
					{
						for (int k = 0; k < mtrix.rows; k++)
						{
							m[i][j] += m[i][k] * mtrix.m[k][j];
						}
					}
				}
			}
	return *this;
}
Matrix& Matrix::operator*=(const double& b)
{
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
		{
			m[i][j] *= b;
		}
	return *this;
}
Matrix& Matrix::operator/=(const double& b)
{
	if (b == 0)
		cout << "imposibil!";
	else
	{
		for(int i=0;i<rows;i++)
			for (int j = 0; j < cols; j++)
			{
				m[i][j] /= b;
			}
		return *this;
	}
}
void operator+(Matrix mtrix)
{
	for (int i = 0; i < mtrix.rows; i++) 
	{
		for (int j = 0; j < mtrix.cols; j++)
			cout << mtrix.m[i][j] << " ";
		cout << "\n";
	}
}
void operator-(Matrix mtrix)
{
	for (int i = 0; i < mtrix.rows; i++) 
	{
		for (int j = 0; j < mtrix.cols; j++)
			cout << "-" << mtrix.m[i][j] << " ";
		cout << "\n";
	}
}
int operator+(Matrix a, Matrix b)
{
	int i, j;
	for (i = 0; i < a.rows; i++) 
	{
		for (j = 0; j < a.cols; j++)
			if (a.rows != b.cols)
				cout << "imposibil";
			else
				a.m[i][j] += b.m[i][j];
	}
	return a.m[i][j];
}
int operator+(Matrix a, double b)
{
	int i, j;
	for (i = 0; i < a.rows; i++)
	{
		for (j = 0; j < a.cols; j++)
			a.m[i][j] += b;
	}
	return a.m[i][j];
}
int operator+(double b, Matrix a)
{
	int i, j;
	for (i = 0; i < a.rows; i++)
	{
		for (j = 0; j < a.cols; j++)
			a.m[i][j] += b;
	}
	return a.m[i][j];
}
int operator-(Matrix a, Matrix b)
{
	int i, j;
	for (i = 0; i < a.rows; i++)
	{
		for (j = 0; j < a.cols; j++)
			if (a.rows != b.cols)
				cout << "imposibil";
			else
				a.m[i][j] -= b.m[i][j];
	}
	return a.m[i][j];
}
int operator-(Matrix a, double b)
{
	int i, j;
	for (i = 0; i < a.rows; i++)
	{
		for (j = 0; j < a.cols; j++)
			a.m[i][j] -= b;
	}
	return a.m[i][j];
}
int operator-(double b, Matrix a)
{
	int i, j;
	for (i = 0; i < a.rows; i++)
	{
		for (j = 0; j < a.cols; j++)
			a.m[i][j] -= b;
	}
	return a.m[i][j];
}
int operator*(Matrix a, Matrix b)
{
	int i, j, k;
	for (i = 0; i < a.rows; i++)
		for (j = 0; j < a.cols; j++)
			if (a.rows != b.cols)
				cout << "imposibil";
			else
			{
				for (i = 0; i < a.rows; i++)
				{
					for (j = 0; j < b.cols; j++)
					{
						for (k = 0; k < b.rows; k++)
						{
							a.m[i][j] += a.m[i][k] * b.m[k][j];
						}
					}
				}
			}
	return a.m[i][j];
}
int operator*(Matrix a, double b)
{
	int i, j;
	for (i = 0; i < a.rows; i++)
	{
		for (j = 0; j < a.cols; j++)
			a.m[i][j] *= b;
	}
	return a.m[i][j];
}
int operator*(double b, Matrix a)
{
	int i, j;
	for (i = 0; i < a.rows; i++)
	{
		for (j = 0; j < a.cols; j++)
			a.m[i][j] *= b;
	}
	return a.m[i][j];
}
int operator/(Matrix a, double b)
{
	int i, j;
	for (i = 0; i < a.rows; i++)
	{
		for (j = 0; j < a.cols; j++)
			a.m[i][j] /= b;
	}
	return a.m[i][j];
}
int operator/(double b, Matrix a)
{
	int i, j;
	for (i = 0; i < a.rows; i++)
	{
		for (j = 0; j < a.cols; j++)
			a.m[i][j] /= b;
	}
	return a.m[i][j];
}
int operator^(Matrix a, int b)
{
	int i, j, p = 0;
		for (i = 0; i < a.rows; i++)
		{
			for (j = 0; j < a.cols; j++)
				if (a.rows != a.cols)
					cout << "imposibil";
				else
				{
					do
					{
						a.m[i][j] *= a.m[i][j];
						p++;
					} while (p <= b);
				}
		}
		return a.m[i][j];
}
int Matrix::operator[](int poz)
{
	int ok = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (rows == 1)
			{
				while (cols <= poz)
				{
					cols++;
				}
				if (cols == poz)
				{
					ok = 1;
					if (ok == 1)
						return m[i][j];
				}
			}
			if (cols == 1)
			{
				while (rows <= poz)
				{
					rows++;
				}
				if (rows == poz)
				{
					ok = 1;
					if (ok == 1)
						return m[i][j];
				}
			}
			if (rows != 1 && cols != 1)
			{
				rows = poz;
				for (int j = 0; j < cols; j++)
					return m[poz][j];
			}
		}		
	}
}
void operator==(Matrix a, Matrix b)
{
	int i, j, ok=0;
	for (i = 0; i < a.rows; i++)
	{
		for (j = 0; j < a.cols; j++) 
		{
			if (a.m[i][j] == b.m[i][j])
				ok = 1;
		}
	}
	if (ok == 1)
		cout << "Matricile sunt egale";
}
void operator!=(Matrix a, Matrix b)
{
	int i, j, ok = 0;
	for (i = 0; i < a.rows; i++)
	{
		for (j = 0; j < a.cols; j++)
		{
			if (a.m[i][j] == b.m[i][j])
				ok = 1;
		}
	}
	if (ok == 0)
		cout << "Matricile nu sunt egale";
}
istream operator>>(istream& in, Matrix& a)
{
	in >> a.rows;
	in >> a.cols;
	for (int i = 0; i < a.rows; i++) 
	{
		for (int j = 0; j < a.cols; j++)
			in >> a.m[i][j];
	}
	return in;
}
ostream operator<<(ostream& out, Matrix a)
{
	for (int i = 0; i < a.rows; i++)
	{
		for (int j = 0; j < a.cols; j++)
			out << a.m[i][j] << " ";
		cout << "\n";
	}
	return out;
}