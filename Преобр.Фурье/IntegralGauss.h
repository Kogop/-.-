#pragma once
#include <iostream>
#include <math.h>
#include <vector>
#include <fstream>

using namespace std;

double f(double x);
double f1(double x, double y);

class Gaus
{
public:
    long double I(long double a, long double b, long double N);
    long double function(long double f);
private:
    vector <long double> Xi;
    vector <long double> Ci;

    long double Gauss(long double a, long double b);
   

    void file_out();
};
long double Gaus::function(long double f)
{
    return f;
}
void Gaus::file_out()
{
    long double ld;
    fstream f;
    f.open("96.txt");
    for (size_t i = 0; i < 192; i++)
    {
        if (i % 2 == 0)
        {
            f >> ld;
            Xi.push_back(ld);
        }
        else
        {
            f >> ld;
            Ci.push_back(ld);
        }
    }
    f.close();
}
long double Gaus::Gauss(long double a, long double b)
{
    long double ra = (double)(b - a) / 2;
    long double su = (double)(a + b) / 2;
    long double Q, S = 0;
    for (size_t i = 0; i < Xi.size(); i++)
    {
        Q = (double)su + ra * Xi[i];
        S += (double)Ci[i] * function(Q);
    }
    return ra * S;
}
long double Gaus::I(long double a, long double b, long double N)
{
    file_out();
    long double s = 0;
    for (size_t i = 0; i < N; ++i)
    {
        s += Gauss((a + i * (double)(b - a) / N), (a + (i + 1) * (double)(b - a) / N));
    }
    return s;
}
