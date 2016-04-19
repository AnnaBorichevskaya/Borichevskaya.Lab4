#include <iostream>
using namespace std;

bool IsDataValid(int, int, int, double);
double Formula(double);
int TheNumberOfPartitionsInRightRectangle(int, int, int, double);
int TheNumberOfPartitionsInMediumRectangle(int, int, int, double);
double RightRectangle(int, int, int);
double MediumRectangle(double, double, int);


int main()
{
	int a, b, n;
	double eps;
	while (true)
	{
		cout << "Enter lower limit : " << endl;
		cin >> a;
		cout << "Enter upper limit : " << endl;
		cin >> b;
		cout << "Enter number of partitions: " << endl;
		cin >> n;
		cout << "Enter epsilon:" << endl;
		cin >> eps;
		system("cls");
		if (IsDataValid(a, b, n, eps)) 
			break;
		cout << "Invalid Data, Try Again!" << endl;
	}

	n = TheNumberOfPartitionsInRightRectangle(a, b, n, eps);
	cout << endl << "According to the formula of right triangles the integral is = ";
	cout << RightRectangle(a, b, n);
	n = TheNumberOfPartitionsInMediumRectangle(a, b, n, eps);
	cout << endl << "According to the formula of medium triangles the integral is = ";
	cout << MediumRectangle(a, b, n);


	/*cout << endl << "According to the formula of right triangles the integral is = ";
	cout << TheNumberOfPartitionsInRightRectangle(a, b, n, eps);
	cout << endl << "According to the formula of medium triangles the integral is = ";
	cout << TheNumberOfPartitionsInMediumRectangle(a, b, n, eps);*/

	system("pause");
	return 0;
}

double Formula(double x)
{
	return sin(x) / x;
}

bool IsDataValid(int a, int b, int n, double eps)
{
	if (eps < 0 || eps >= 1) return false;
	if (a > b) return false;
	if (n < 0) return false;
	return true;
}

int TheNumberOfPartitionsInRightRectangle(int a, int b, int n, double eps)
{
	double Prev=0, Next=1;
	while (fabs(Prev - Next) > eps)
	{
		Prev = RightRectangle(a, b, n);
		Next = RightRectangle(a, b, 2 * n);
		n = 2 * n;
	}
	return n;
}

int TheNumberOfPartitionsInMediumRectangle(int a, int b, int n, double eps)
{
	double Prev=0, Next=1;
	while (fabs(Prev - Next) > eps)
	{
		Prev = MediumRectangle(a, b, n);
		Next = MediumRectangle(a, b, 2 * n);
		n = 2 * n;
	}
	return n;
}

double RightRectangle(int a, int b, int n)
{
	double step = (b - a) / n;
	double Integral = 0;
	double t = a;
	while (t < b)
	{
		Integral += Formula(t);
		t += step;
	}
	Integral = step * Integral;
	return Integral;
}

double MediumRectangle(double LowLimit, double UpLimit, int k)
{
	double Step = (UpLimit - LowLimit) / k;
	double integral = 0;
	double t = LowLimit;
	while (t <= UpLimit)
	{
		integral += Formula(t);
		t += 1.5*Step;
	}
	integral = Step * integral;
	return integral;
}
