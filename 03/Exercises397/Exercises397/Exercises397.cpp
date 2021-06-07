// Exercises397.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
//#include <boost\math\distributions\normal.hpp>
//#include <random>
using namespace std;

double normcdf(double x);
double norminv(double x);
double hornerFunction(double x, double a0);
double hornerFunction(double x, double a0, double a1);
double hornerFunction(double x, double a0, double a1, double a2);
double hornerFunction(double x, double a0, double a1, double a2, double a3);
double hornerFunction(double x, double a0, double a1, double a2, double a3, double a4);
double hornerFunction(double x, double a0, double a1, double a2, double a3, double a4, double a5);
double hornerFunction(double x, double a0, double a1, double a2, double a3, double a4, double a5, double a6);
double hornerFunction(double x, double a0, double a1, double a2, double a3, double a4, double a5, double a6, double a7);
double hornerFunction(double x, double a0, double a1, double a2, double a3, double a4, double a5, double a6, double a7, double a8);

int main()
{
    cout << "Test norminv(normcdf(x)) == x" << endl;
    //cout << normcdf(1) << endl;
    cout << norminv(normcdf(1)) << endl;
    //cout << normcdf(2) << endl;
    cout << norminv(normcdf(2)) << endl;
    //cout << normcdf(3) << endl;
    cout << norminv(normcdf(3)) << endl;
    cout << endl;

    cout << "Test normcdf(norminv(x)) == x" << endl;
    //cout << norminv(0.3) << endl;
    cout << normcdf(norminv(0.3)) << endl;
    //cout << norminv(0.5) << endl;
    cout << normcdf(norminv(0.5)) << endl;
    //cout << norminv(0.8) << endl;
    cout << normcdf(norminv(0.8)) << endl;
    cout << endl;


    cout << "Test norminv(x)" << endl;
    cout << norminv(0.1) << endl;
    cout << norminv(0.2) << endl;
    cout << norminv(0.3) << endl;
    cout << norminv(0.4) << endl;
    cout << norminv(0.5) << endl;
    cout << norminv(0.6) << endl;
    cout << norminv(0.7) << endl;
    cout << norminv(0.8) << endl;
    cout << norminv(0.9) << endl;

    return 0;
}

const double a0 = 2.50662823884;
const double a1 = -18.61500062529;
const double a2 = 41.39119773534;
const double a3 = -25.44106049637;
const double b1 = -8.47351093090;
const double b2 = 23.08336743743;
const double b3 = -21.06224101826;
const double b4 = 3.13082909833;
const double c0 = 0.3374754822726147;
const double c1 = 0.9761690190917186;
const double c2 = 0.1607979714918209;
const double c3 = 0.0276438810333863;
const double c4 = 0.0038405729373609;
const double c5 = 0.0003951896511919;
const double c6 = 0.0000321767881768;
const double c7 = 0.0000002888167364;
const double c8 = 0.0000003960315187;

const double Pi = 3.141592653589793;
const double root2Pi = sqrt(2.0 * Pi);

double normcdf(double x)
{
    if (x < 0)
        return 1 - normcdf(-x);
    double k = 1 / (1 + 0.2316419 * x);
    //double poly = k * (0.319381530 + k * (-0.356563782 + k * (1.781477937 + k * (-1.821255978 + 1.330274429 * k))));
    double poly = hornerFunction(k, 0.0, 0.319381530, -0.356563782, 1.781477937, -1.821255978, 1.330274429);
    double approx = 1.0 - 1.0 / root2Pi * exp(-0.5 * x * x) * poly;
    return approx;
}

double norminv(double x)
{
    double r;
    double s;
    double t;

    double y = x - 0.5;
    if (y <0.42 && y >-0.42)
    {
        r = y * y;
        return y * hornerFunction(r, a0, a1, a2, a3) / hornerFunction(r, 1.0, b1, b2, b3, b4);
    }
    else
    {
        if (y < 0)
            r = x;
        else
            r = 1 - x;
        s = log(-log(r));
        t = hornerFunction(s, c0, c1, c2, c3, c4, c5, c6, c7, c8);
        if (x > 0.5)
            return t;
        else
            return -t;
    }
    
}

double hornerFunction(double x, double a0)
{
    return a0;
}

double hornerFunction(double x, double a0, double a1)
{
    return a0 + x * hornerFunction(x, a1);
}

double hornerFunction(double x, double a0, double a1, double a2)
{
    return a0 + x * hornerFunction(x, a1, a2);
}

double hornerFunction(double x, double a0, double a1, double a2, double a3)
{
    return a0 + x * hornerFunction(x, a1, a2, a3);
}

double hornerFunction(double x, double a0, double a1, double a2, double a3, double a4)
{
    return a0 + x * hornerFunction(x, a1, a2, a3, a4);
}

double hornerFunction(double x, double a0, double a1, double a2, double a3, double a4, double a5)
{
    return a0 + x * hornerFunction(x, a1, a2, a3, a4, a5);
}

double hornerFunction(double x, double a0, double a1, double a2, double a3, double a4, double a5, double a6)
{
    return a0 + x * hornerFunction(x, a1, a2, a3, a4, a5, a6);
}

double hornerFunction(double x, double a0, double a1, double a2, double a3, double a4, double a5, double a6, double a7)
{
    return a0 + x * hornerFunction(x, a1, a2, a3, a4, a5, a6, a7);
}

double hornerFunction(double x, double a0, double a1, double a2, double a3, double a4, double a5, double a6, double a7, double a8)
{
    return a0 + x * hornerFunction(x, a1, a2, a3, a4, a5, a6, a7, a8);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
