#include<iostream>
#include<functional>

using Operation = float (*)(float, float);

float Summ(float a, float b) { return a + b; }
float Multiply(float a, float b) { return a * b; }
// вычитание
float Subtraction(float a, float b) { return a - b; }
// деление
float Division(float a, float b) { return a / b; }


void Calc(float a, float b, Operation alg, char x) {
	std::cout << "\n" << a << " " << x << " " << b << " = " << alg(a, b) << "\n\n";
}

int main() {
	setlocale(LC_ALL, "RU");

	int n;
	std::cout << "Чтобы остаться введите 0, иначе - любое число: ";
	std::cin >> n;
	while(n==0)
	{
		float a, b;
		char x;
		std::cout << "\nПервое число: ";
		std::cin >> a;
		std::cout << "Второе число: ";
		std::cin >> b;
		std::cout << "Операция( +, -, *, / ): ";
		std::cin >> x;

		float (*function)(float, float) = Summ;

		if (x == '-') function = Subtraction;
		else if (x == '*') function = Multiply;
		else if (x == '/') function = Division;

		if (x == '/' && b == 0)std::cout << "\nДелить на 0 нельзя\n\n";
		else Calc(a, b, function, x);
		std::cout << "Чтобы остаться введите 0, иначе - любое число: ";
		std::cin >> n;
	}

	return 0;
}
