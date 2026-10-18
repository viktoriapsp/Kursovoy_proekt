#include <stdio.h>
#include <locale.h>
#include <math.h>

main() {
	start();
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

int start()
{
	setlocale(LC_ALL, "RUS");
	double X;
	printf("Введите показатель X (от 5 до 70): ");
	scanf("%lf", &X);
	if (X >= 5 && X <= 70) {
		printf("Итоговое значение Q = %.2lf\n", Q(X));
	}
	else {
		printf("Ошибка! Значение должно быть от 5 до 70.\n");
	}
}
