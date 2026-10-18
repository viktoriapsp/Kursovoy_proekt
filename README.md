# Мониторинг реактора: расход азота (X)

## Постановка задач

Датчик технологической установки работает непрерывно и формирует последовательность показаний расхода азота (X) в реакторе:

  * `X(1), X(2),...,X(n)`.

Для оценки текущего состояния технологического процесса каждое измерение `X(i)` преобразуется в индикатор `Q(i)` с помощью индивидуальной кусочной функции:

  * `Q(i)=F(X(i))`.

Функция преобразования `F(X)` задается следующим образом:

  * `X<20: Q(X)=((X-20)^2)/6 + 10`.
  * `20<=X<=45: Q(X)=3*(X-32.5)+50`.
  * `X>45: Q(X)=2*sqrt(X-45+1)+60`.

Для подтверждения корректности реализации алгоритма преобразования показаний (пункт 1) выполняется проверка на основе контрольного примера: При входном значении `X=32.50`, ожидаемое значение индикатора `Q` должно составлять `50.00`.

## Задание 1

## Алгоритм и блок-схема

### Алгоритм

1. Программа запускается.
2. Дальше управление передается функции start.
3. В функции start у пользователя запрашивается значение X (в пределах от 5 до 70) и считывается с клавиатуры.
4. Затем проверяется введенное число:
   * Если X в пределах от 5 до 70, вызывается функция Q(X), и результат выводится на экран.
   * Если число не входит в этот диапазон, программа выводит сообщение об ошибке.
5. Внутри функции Q(X) происходит расчет:
   * если X меньше 20, считаем по формуле `((X-20)^2)/6 + 10`;
   * если X от 20 до 45, считаем по `3*(X-32.5)+50`;
   * если X больше 45, считаем по `2*sqrt(X-45+1)+60`.
6. Функция Q возвращает готовый результат.
7. Программа заканчивает работу.

### Блок-схема
<img width="501" height="733" alt="Диаграмма без названия drawio" src="https://github.com/user-attachments/assets/54ee1913-424e-4f13-bfb8-c48a2ecc2f2e" />



![Ссылка на блок-схему](https://viewer.diagrams.net/?tags=%7B%7D&lightbox=1&highlight=0000ff&edit=_blank&layers=1&nav=1&title=%D0%94%D0%B8%D0%B0%D0%B3%D1%80%D0%B0%D0%BC%D0%BC%D0%B0%20%D0%B1%D0%B5%D0%B7%20%D0%BD%D0%B0%D0%B7%D0%B2%D0%B0%D0%BD%D0%B8%D1%8F.drawio.png&dark=auto#R%3Cmxfile%3E%3Cdiagram%20name%3D%22%D0%A1%D1%82%D1%80%D0%B0%D0%BD%D0%B8%D1%86%D0%B0-1%22%20id%3D%22ECTnMw8LokP2q105dwok%22%3E7Zpdb9sgFIZ%2FjaV20ioC%2Fkgum7bbbiZt6sW6S2pT2xoxHiFLul%2B%2Fg40DdpImzbzMrRopLhwOGL8PBwONR65mq4%2BSltlnkTDuYZSsPHLtYTzyJwT%2BaMtjbRlHuDakMk%2BMkzXc5r%2BZMSJjXeQJm7cclRBc5WXbGIuiYLFq2aiUYtl2exC8fdeSpmzDcBtTvmn9licqM0%2BBI2v%2FxPI0a%2B48Cid1yYw2zuZJ5hlNxNIxkRuPXEkhVJ2ara4Y1%2BI1utT1PuwoXXdMskIdUmGuqFSblUw7c%2FXYPDJUA3UhM11muWK3JY11yRIAgy1TMw65ESQfcs6vBBeyqkceqg%2FY50qKH8wpQdVH1xCF2mavazQCgzTTule%2FKF%2BYXnnXyJtc6%2BsUeXD7cdSk4TqtrjemEpOKrZynM3p8ZGLGlHwEl8xBFhg%2BS4t31DAzrRDf5M0gbrLUDK503bLVHxIGwXYceVEuDsIB46bUSfCinDMuUklnoFDJZA53ZbJb9sUW7Ce4Yk3Q%2FR%2Bi1XWKDT999cHrDr5njQ1Y65oBfI2DgY0idN4b8nEH%2BaiNfER6YJ6weEvYbiKXmZjdL%2BYDi0ANxcMhnelOcFW5IDCRD0dBGG%2BBEHYg4DYE3AeEUooDKYhFkTBdCw2RhE6hszOdfl%2BBgFhA77TNMZ1XzAAQCquURjZCts3nIQs3kWHURhaEHWR9zJUQN%2FhVxU3Fzg9OGDok6il0DgPxAkKHdMOF4IvgfB0lwSmjhIx7okNeCx1s6Mx%2FSrUm5Ad2ErOkwj5J7VsHBKgHUmKh3hZ%2F9eIPFnfTrUvAr2d3%2FS3u%2FA5U0oYa4h6gsiI5hOiAd1eXDoJ6pxVUgMLeOOzZV0W9cEhSZmTXyRaHbWjEQsZNtNktsksMWrk1WSFVJlJRUH5jrdP2hOowZKtc3WnzRWBy35uSAh7LKdLZ76aB3YR3kYR%2Bp8w813pjuYlHMk5V%2Fqutyd9qjY%2FT2tn%2Fvlytmw3diaQmx0ltt539Kj1ydHakvTM1rM5VWR%2FzFqf3jE9p%2FCOtOtdUKkShO6wnqDym%2FJLnaQHme6GU0G9LagwxdKl6M26SdHaF3WnRNwdNp%2BPsD4tzXxE1BM52K7n9bDFozptOBjs4GjZ%2BC%2Br9Qb2D9umDOhwW59cU1M7OdyhRHR1H23kNDRP3Iasiu709UGyzHUAXJJyEu%2FWvWruUkj46DqXICzV3bvZFG2yjUfeoBXX%2BTbbHH0dP%2B4%2FR3%2FkH46f9%2Faf9IVErYkfmWu2DB%2Bv4%2BME66LnpnwzW3kZmGA5vJEyOHwnkbSQ895QCHae2e3z4cuU252X9aw1Z%2B6uKOg7sb1PIzR8%3D%3C%2Fdiagram%3E%3C%2Fmxfile%3E)

## Реализация программы

Программа написана на языке C

```c
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
```
## Результат работы программы
```
Введите показатель X (от 5 до 70): 32.5
Итоговое значение Q = 50.00
```
## Информация о разработчике
```
Имя: Страхова Виктория Викторовна
Группа: бИЦТ-261
Вариант: 33

