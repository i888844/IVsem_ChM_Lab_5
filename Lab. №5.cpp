#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

#define _PI 3.141592653589793
#define _BEGINNING _PI / 4
#define _ENDING _PI / 2
#define _N 8
#define _H fabs(_ENDING - _BEGINNING) / _N

long double y(const long double x)
{
    return cos(x) / sqrt(pow(sin(x), 3));
}

long double first_derivative(const long double x)
{
    return -sin(x) / (2 * pow(sin(x), 5.0 / 2.0));
}

int main()
{
    unsigned long int i = 0;
    unsigned long int j = 0;

    long double** A;
    A = new long double* [_N + 1];
    for (i = 0; i < _N + 1; i++)
    {
        A[i] = new long double[4];
    }

    long double Xi = 0.0;
    long double Yi = 0.0;
    long double Xi_1 = 0.0;
    long double Yi_1 = 0.0;

    for (i = 0; i < _N + 1; i++)
    {
        Xi = _BEGINNING + i * _H;
        Yi = y(Xi);

        A[i][0] = Xi;
        A[i][1] = Yi;

        if (i == 0)
        {
            A[i][2] = 0.0;
            A[i][3] = 0.0;
        }
        else
        {
            Xi_1 = Xi - _H;
            Yi_1 = y(Xi_1);
            A[i][2] = Xi_1;
            A[i][3] = Yi_1;
        }
    }

    cout << "i\txi\tyi\txi-1\tyi-1" << endl;
    for (i = 0; i < _N + 1; i++)
    {
        cout << fixed << setprecision(4);
        cout << i << "\t";
        for (j = 0; j < 4; j++)
        {
            if (i == 0 && (j == 2 || j == 3))
            {
                cout << "\t" << "\t";
            }
            else
            {
                cout << A[i][j] << "\t";
            }
        }
        cout << endl;
    }

    long double I = 0.0;
    long double term = 0.0;
    for (i = 0; i < _N; i++)
    {
        term += A[3][i];
    }
    I = -(_H * term);

    cout << "I = " << I << endl;

    long double R = ((_ENDING - _BEGINNING) * (_ENDING - _BEGINNING)) / (2 * _N * _N) * fabs(first_derivative((_BEGINNING + _ENDING) / 2));

	cout << "R = " << R << endl;

    for (i = 0; i < _N + 1; i++)
    {
        delete[] A[i];
    }
    delete[] A;

    return 0;
}
