#include <iostream>
#include "matrix.h"

using namespace std;

int main()
{
	cout << "Meniu: \n";
	cout << "0 - STOP" << "\n";
	cout << "1 - Citire matrice si afisare" << "\n";
	cout << "2 - Suma celor 2 matrici" << "\n";
	cout << "3 - Suma cu un scalar" << "\n";
	cout << "4 - Diferenta celor 2 matrici" << "\n";
	cout << "5 - Diferenta cu un scalar" << "\n";
	cout << "6 - Produsul celor doua matrici" << "\n";
	cout << "7 - Produs cu un scalar" << "\n";
	cout << "8 - Impartire cu un scalar" << "\n";
	cout << "9 - Suma celor 2 matrici(friend)" << "\n";
	cout << "10 - Suma cu un scalar(friend)" << "\n";
	cout << "11 - Suma cu un scalar(friend)" << "\n";
	cout << "12 - Diferenta celor 2 matrici(friend)" << "\n";
	cout << "13 - Diferenta cu un scalar(friend)" << "\n";
	cout << "14 - Diferenta celor 2 matrici(friend)" << "\n";
	cout << "15 - Produsul celor 2 matrici(friend)" << "\n";
	cout << "16 - Produs cu un scalar(friend)" << "\n";
	cout << "17 - Produs cu un scalar(friend)" << "\n";
	cout << "18 - Impartire cu un scalar(friend)" << "\n";
	cout << "19 - Impartire cu un scalar(friend)" << "\n";
	cout << "20 - Ridicare la putere" << "\n";
	cout << "21 - Pozitie" << "\n";
	cout << "22 - Verifica egalitatea" << "\n";
	cout << "23 - Verifica inegalitatea" << "\n";
	int c, s, p, poz;
	Matrix m, m2;
	cin >> s;
	cin >> p;
	cin >> poz;
	cin >> m2;
	while (true) 
	{
		cin >> c;
		if (c == 0)
			break;
		switch (c) 
		{
		case 1: citire(cin);
				afisare(cout);
			break;
		case 2:
			cout << m += m2 << "\n";
			break;
		case 3:
			cout << m += s << "\n";
			break;
		case 4: 
			cout << m -= m2 << "\n";
			break;
		case 5:
			cout << m -= s << "\n";
			break;
		case 6:
			cout << m *= m2 << "\n";
			break;
		case 7:
			cout << m *= s << "\n";
			break;
		case 8:
			cout << m /= s << "\n";
			break;
		case 9:
			cout << m + m2 << "\n";
			break;
		case 10:
			cout << m + s << "\n";
			break;
		case 11:
			cout << s + m << "\n";
			break;
		case 12: 
			cout << m - m2 << "\n";
			break;
		case 13:
			cout << m - s << "\n";
			break;
		case 14:
			cout << s - m << "\n";
			break;
		case 15:
			cout << m * m2 << "\n";
			break;
		case 16:
			cout << m * s << "\n";
			break;
		case 17:
			cout << s * m << "\n";
			break;
		case 18:
			cout << m / s << "\n";
			break;
		case 19:
			cout << s / m << "n";
			break;
		case 20:
			cout << m ^ p << "\n";
			break;
		case 21:
			cout << m[]poz << "\n";
			break;
		case 22:
			cout << m == m2 << "\n";
			break;
		case 23:
			cout << m != m2 << "\n";
			break;
		}
	}
	return 0;
}