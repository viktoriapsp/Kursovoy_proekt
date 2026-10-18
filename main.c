#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <math.h>
main() {
	start();
}
double calc(double num) {
	if (num < 20) {
		num = ((num - 20) * (num - 20)) / 6 + 10;
	}
	else if (num >= 20 && num <= 45) {
		num = 3 * (num - 32.5) + 50;
	}
	else if (num > 45) {
		num = 2 * sqrt(num - 45 + 1) + 60;
	}
	return num;
}
int start()
{
	setlocale(LC_ALL, "RUS");
	double num;
	printf("Введите показатель X (в интервале 5-70): ");
	scanf("%lf", &num);
	if (num >= 5 && num <= 70) {
		printf("Вычисленное значение: %.2lf\n", calc(num));
	}
	else {
		printf("Ошибка: значение вне допустимых границ (5-70)!\n");
	}
}
