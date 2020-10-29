#include <feed.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	double x1, x0;
	double e = 0.0001;

	cout << "�������� �������� ������ ����� ������� �� �." << endl;
	double a = GetDouble("������� ����� a:", "����� ������� �����������!");

	if (a <= 1)
		x0 = Minimum(2. * a, 0.95);
	else if (a > 1. && a < 25.)
		x0 = a / 5.;
	else
		x0 = a / 25.;
	
	x1 = (4. * x0 / 5.) + (a / (5. * pow(x0, 4)));

	while (abs(x1 - x0) > e)
	{
		x0 = x1;
		x1 = (4. * x0 / 5.) + (a / (5. * pow(x0, 4)));
		cout << "x =" << setw(12) << setprecision(8) << fixed << x1 << endl;
	}

	cout << "������ ����� ������� �� a �������� ����� " << x1 << endl;

	system("pause");
	return 0;
}