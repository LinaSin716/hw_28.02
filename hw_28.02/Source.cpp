#include<iostream>
#include<functional>

using Operation = float (*)(float, float);

float Summ(float a, float b) { return a + b; }
float Multiply(float a, float b) { return a * b; }
// ���������
float Subtraction(float a, float b) { return a - b; }
// �������
float Division(float a, float b) { return a / b; }


void Calc(float a, float b, Operation alg, char x) {
	std::cout << "\n" << a << " " << x << " " << b << " = " << alg(a, b) << "\n\n";
}

int main() {
	setlocale(LC_ALL, "RU");

	int n;
	std::cout << "����� �������� ������� 0, ����� - ����� �����: ";
	std::cin >> n;
	while(n==0)
	{
		float a, b;
		char x;
		std::cout << "\n������ �����: ";
		std::cin >> a;
		std::cout << "������ �����: ";
		std::cin >> b;
		std::cout << "��������( +, -, *, / ): ";
		std::cin >> x;

		float (*function)(float, float) = Summ;

		if (x == '-') function = Subtraction;
		else if (x == '*') function = Multiply;
		else if (x == '/') function = Division;

		if (x == '/' && b == 0)std::cout << "\n������ �� 0 ������\n\n";
		else Calc(a, b, function, x);
		std::cout << "����� �������� ������� 0, ����� - ����� �����: ";
		std::cin >> n;
	}

	return 0;
}
