#include <iostream>
#include <cmath>
#include <fstream>
#define M_PI       3.14159265358979323846 
using namespace std;
double func(double x)
{
	return sin(x*x);
}


int main()
{
	setlocale(0, "");
	ofstream fout("ans1.dat");
	cout << "Интеграл от ф-ии sin(x^2) с интервалом от 0 до pi/4" << endl;

	cout << "Метод серединных прямоугольников:" << endl;
	cout << "Введите число шагов: ";
	int n;
	double a = 0;
	double b = M_PI/4;
	cin >> n;
	double h = (b - a) / n;
	double I = 0;
	double I_buff = 0;
	double buff = 0;
	double x;
	double E = 0.0001;
	double index = 0;
	
	cout << "Интеграл    Погрешность" << endl;
	do
	{
		buff = 0;
		for (int i = 0; i < n; i++)
		{
			x = a + (h * i);
			I += h * func(x + h / 2);
		}
		cout << I << "    ";
		fout << I << "    ";
		if (index != 0)
			buff = (1.0 / 3) * abs(I - I_buff);//метод Рунге
		else
			buff = 100000;
		if (index > 0)
		{
			cout << buff;
			fout << buff;
		}
		cout << endl;
		fout << endl;

		I_buff = I;
		I = 0;
		h /= 2;
		n *= 2;
		index++;
	} while (abs(buff > E));

	fout.close();
	system("pause");
	return 0;
}
