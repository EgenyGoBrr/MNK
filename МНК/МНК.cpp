#include <iostream>
using namespace std;

//https://prog-cpp.ru/mnk/

double** getData(int);
void getApprox(double** f, double* a, double* b, int n);

int main()
{
    setlocale(LC_ALL, "rus");
    double** f;//матрица изначальных значений
    double a, b;//коэффициенты прямой
    int n;//количество точек
    cout << "Введите количество точек: ";
    cin >> n;
    f = getData(n);
    for (int i = 0; i < n; i++)
        cout << i << " - " << f[1][i] << endl;
    getApprox(f, &a, &b, n);
    cout << "a = " << a << endl << "b = " << b << endl;
    return 0;
}

double** getData(int n)//задаем начальный набор значений для 16х-2
{
    double** f;//матрица изначальных значений
    f = new double* [2];
    f[0] = new double[n];//значение Х
    f[1] = new double[n];//значение У
    for (int i = 0; i < n; i++)
    {
        f[0][i] = (double)i;
        //f[1][i] = 16 * (double)i - 2;
        //добавление случайной составляющей
        f[1][i] = 16 * (double)i - 2 + ((rand() % 100) - 50) * 0.005;
    }
    return f;
}

void getApprox(double** f, double* a, double* b, int n)
{//вычисление коэффициентов аппроксимирующей прямой
    double sumX = 0;
    double sumY = 0;
    double sumX2 = 0;
    double sumXY = 0;
    for (int i = 0; i < n; i++)
    {
        sumX += f[0][i];
        sumY += f[1][i];
        sumX2 += f[0][i] * f[0][i];
        sumXY += f[0][i] * f[1][i];
    }
    *a = (n * sumXY - (sumX * sumY)) / (n * sumX2 - sumX * sumX);
    *b = (sumY - *a * sumX) / n;
}