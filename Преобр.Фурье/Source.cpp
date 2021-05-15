#include <iostream>
#include <math.h>
//#include "Header.h"
#include "IntegralGauss.h"

using namespace std;

const int n = 100;
double w[n], l[5];
int a = 6, b = 15, alfa = 2 * a, x = 5;
double PrInt[5];

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
//
//double f(int x) {
//
//	return l[x] * l[x+1];
//}

//function
double f(double x)
{
	int y = round(x);
	double f1 = l[y] * l[y + 1];
	return f1;
}


int main() {

	wt();
	L();
	
	//IntegraL t;
	Gaus p;
	for (int i = 0; i < 4; i++)
	{
		 f(i);
		// cout << "tot " << i << " " << t.Simp(0.001, 0, 1000) << endl;
		 cout << "tot " << i << " " << p.I(0, 100, 1) << endl;

	}
	//f(0);// f(2); f(3); f(1);

	//cout << "tot = " << t.Trapize(0.001, 0, 1000) << endl;



	for (int i = 0; i < 5; i++)
	{
		cout << l[i] << endl;
	}





	return 0;

}