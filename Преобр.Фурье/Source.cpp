#include <iostream>
#include <math.h>
//#include "Header.h"
#include "IntegralGauss.h"

using namespace std;

const int n = 100;
double w[n], l[5];
int a = 6, b = 15, alfa = 2 * a, x = 5;
double Cn[5], w3[3], w4[4], w5[5], Eps3[3], Eps4[4], Eps5[5], E3[3], E4[4], E5[5], delta3[3], delta4[4], delta5[5];

double Factorial(double n) {
	return (n == 0) ? 1 : n * Factorial(n - 1);
};

void wt() {

	for (int i = 0; i < n; i++)
	{
		w[i] = (exp(-a * i) / (b - a)) + (sin(-b * i) / (a - b));
	}


}
void L() {

	for (int i = 0; i < x; i++)
	{
		l[i] = sqrt(2 * alfa) * exp(-alfa * i) * pow(-1, i) * (Factorial(i) / (Factorial(x) * Factorial(x - i))) / Factorial(i) * pow(2 * alfa * i, i);
	}

	/*l[0] = sqrt(2 * alfa) * exp(-alfa * 0);
	l[1] = sqrt(2 * alfa) * exp(-alfa * 1) * (1.0 - 2.0 * alfa * 1);
	l[2] = sqrt(2 * alfa) * exp(-alfa * 2) * (1.0 - 4 * alfa * 2 + 2 * pow(alfa,2) * pow(2,2));
	l[3] = sqrt(2 * alfa) * exp(-alfa * 3) * (1.0 - 6 * alfa * 3 + 6 * pow(alfa, 2) * pow(3, 2) - 4 * pow(alfa, 3) * pow(3, 3) / 3);
	l[4] = sqrt(2 * alfa) * exp(-alfa * 4) * (1.0 - 8 * alfa * 4 + 12 * pow(alfa, 2) * pow(4, 2) - 16 * pow(alfa, 3) * pow(4, 3) / 3 + 2 * pow(alfa, 4) * pow(4, 4) / 3);*/
}


//function
double f(double x)
{
	int y = round(x);
	double f1 = l[y] * l[y + 1];
	return f1;
}
double f1(double x) {
	int y = round(x);
	return pow(Eps3[y],2);
}
double f2(double x) {
	int y = round(x);
	return pow(Eps4[y],2);
}
double f3(double x) {
	int y = round(x);
	return pow(Eps4[y],2);
}


int main() {

	wt();//  w(t)
	L(); // first 5 elements of Laplass
	
	//IntegraL and cn ;
	Gaus p;
	for (int i = 0; i < 4; i++)
	{
		 f(i);
		// cout << "tot " << i << " " << t.Simp(0.001, 0, 1000) << endl;
		 cout << "tot " << i << " " << p.I(0, 100, 1) << endl;
		 Cn[i] = p.I(0, 100, 1);

	}


	// w*N (t)
	for (int i = 0; i < 2; i++)
	{
		w3[i] += pow(l[i], 2);
	}
	for (int i = 0; i < 3; i++)
	{
		w4[i] += pow(l[i], 2);
	}
	for (int i = 0; i < 4; i++)
	{
		w5[i] += pow(l[i], 2);
	}

	// error of approximation
	for (int i = 0; i < 2; i++)
	{
		Eps3[i] +=	w[0] - w3[i];
	}
	for (int i = 0; i < 3; i++)
	{
		Eps4[i] += w[0] - w4[i];
	}
	for (int i = 0; i < 4; i++)
	{
		Eps5[i] += w[0] - w5[i];
	}
	
	//part of the energy
	for (int i = 0; i < 2; i++)
	{
		E3[i] += pow(l[i], 2);
	}
	for (int i = 0; i < 3; i++)
	{
		E4[i] += pow(l[i], 2);
	}
	for (int i = 0; i < 4; i++)
	{
		E5[i] += pow(l[i], 2);
	}
	//middle kvadrat error
	f1(3);
	for (int i = 0; i < 3; i++)
	{
		delta3[i] = p.I(0, 100, 1);

	}
	f2(4);
	for (int i = 0; i < 3; i++)
	{
		delta4[i] = p.I(0, 100, 1);

	}
	f3(5);
	for (int i = 0; i < 3; i++)
	{
		delta5[i] = p.I(0, 100, 1);

	}


	/*for (int i = 0; i < 5; i++)
	{
		cout << l[i] << endl;
	}*/





	return 0;

}