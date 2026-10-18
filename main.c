#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <math.h>
main() {
	F();
}
double Q(double X) {
	if (X < 20) {
		X = ((X - 20) * (X - 20)) / 6 + 10;
	}
	else if (X >= 20 && X <= 45) {
		X = 3 * (X - 32.5) + 50;
	}
	else if (X > 45) {
		X = 2 * sqrt(X - 45 + 1) + 60;
	}
	return X;
}
int F()
{
	setlocale(LC_ALL, "RUS");
	double X;
	printf("Введите X в диапазоне [5,70]:");
	scanf("%lf", &X);
	if (X >= 5 && X <= 70) {
		printf("Вывод Q(X): %.2lf", Q(X));
	}
	else {
		printf("Ошибка, введенное число лежит не в заданном диапазоне.");
	}
}