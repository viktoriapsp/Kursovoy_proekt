# Мониторинг реактора: расход азота (X)

## Постановка задач

Датчик технологической установки работает непрерывно и формирует последовательность показаний расхода азота (X) в реакторе:

  * `X(1), X(2),...,X(n)`.

Для оценки текущего состояния технологического процесса каждое измерение `X(i)` преобразуется в индикатор `Q(i)` с помощью индивидуальной кусочной функции `F`:

  * `Q(i)=F(X(i))`.

Функция преобразования `F(X)` задается следующим образом:

  * `X<20: Q(i)=((X-20)^2)/6 + 10`.
  * `20<=X<=45: Q(i)=3*(X-32.5)+50`.
  * `X>45: Q(i)=2*sqrt(X-45+1)+60`.

**Входные и выходные данные:**
* Входные данные: вещественное число `X` (расход азота в л/мин), лежащее в диапазоне от 5 до 70.
* Выходные данные: вещественное число `Q` (индикатор состояния).

**Обоснование типов данных:**
Для хранения входных и выходных значений выбран тип `double`. Это обусловлено тем, что значения могут быть дробными, а также для обеспечения высокой точности вычислений при работе с вещественными числами и использования математических функций (например, `sqrt` из библиотеки `<math.h>`).

Для подтверждения корректности реализации алгоритма преобразования показаний (пункт 1) выполняется проверка на основе контрольного примера: При входном значении `X=32.50`, ожидаемое значение индикатора `Q` должно составлять `50.00`.

## Задание 1

## Алгоритм и блок-схема

### Алгоритм

  1. Начало
  2. Функция Q(X) для вычисления значения индикатора, которая принимает число `X`:

  * Если `X<20`, то возвращает значение, вычисленное по формуле : `((X-20)^2)/6 + 10`.
  * Если `20<=X<=45`, то возвращает значение, вычисленное по формуле : `3*(X-32.5)+50`.
  * Если `X>45`, то возвращает значение, вычисленное по формуле : `2*sqrt(X-45+1)+60`.

  3. Главная программа F:

  * Объявление переменной `X` типа `double`.
  * Просит пользователя ввести число `X` в диапазоне `[5,70]`.
  * Cчитывание введенного значения.
  * Проверка, входит ли введенное число в допустимый диапазон: 
    * Если да: то программа вызывает функцию `Q(X)` и выводит результат на экран.
    * Если нет: то программа выводит сообщение об ошибке.

  4. Конец

### Блок-схема
<img width="422" height="722" alt="Диаграмма без названия drawio" src="https://github.com/user-attachments/assets/56d41382-d6d9-476a-9195-55e7fa2c986f" />

[Ссылка на блок-схему](https://viewer.diagrams.net/?tags=%7B%7D&lightbox=1&highlight=0000ff&edit=_blank&layers=1&nav=1&title=%D0%94%D0%B8%D0%B0%D0%B3%D1%80%D0%B0%D0%BC%D0%BC%D0%B0%20%D0%B1%D0%B5%D0%B7%20%D0%BD%D0%B0%D0%B7%D0%B2%D0%B0%D0%BD%D0%B8%D1%8F.drawio.png&dark=auto#R%3Cmxfile%3E%3Cdiagram%20name%3D%22%D0%A1%D1%82%D1%80%D0%B0%D0%BD%D0%B8%D1%86%D0%B0-1%22%20id%3D%22Mkn4KjVn3nEORs4h2L9A%22%3E7ZnRbpswFIafBqmttApsIOSySdPuZlKrXKy99IILaICZcZpkT79jMMGQdE0pZcm2RKL28bHB3%2F9DbWLgabK%2B5SQLvzCfxgYy%2FbWBrw2ELBOb8EdGNmXENVEZCHjkq6Q6MI9%2B0qqnii4jn%2BaNRMFYLKKsGVywNKUL0YgRztmqmfbE4uZZMxLQncB8QeLd6NfIF2EZ9dCojn%2BmURBWZ7bccdmSkCpZzSQPic9WWgjPDDzljImylKynNJbwKi5lv5sXWrcXxmkqDumQC8LFbic1Ti421ZShG9CFymQVRoLOM7KQLSsQGGKhSGKoWVB8iuJ4ymLGi374yZFfiOeCs%2B9Uayk%2F0FKe65nES3Uu49o0xtfyODENGNQbVWU4TorjTHWiXNC1ds1qlreUJVTwDaSEmhCOor6qRbMqJdQouMpR1rRVlSjLBNuRa6pQUGD3Q47SbHkQZHBDJouQReKYxizgJAFCGeURnJXydttd3fC6Lmta3Up96lQcJ0ipIo82ZD30po%2Fd0sdu6mP1IZBPF3vunF19eMiSb8t8kJsACMLMXJLIoWNRpJgQwjed0HpvR9uL9zPODmTLlqlPZS9zEL73kq8smWdnD5%2BQeW5MEfj4HCbkFugl7%2BofTg8%2BdpuwHa8F23F68TE6AR8X1G1nQCtjrycrH4b3j1kZX4CXMbp0zrcWdgazMB73YGEJGR83ZHSR%2F%2BACQIOF0cSqUbv9ofZafkZN1I7Vg5%2FZUvzd6xJYOU72rk7uh1qduH3oRFP%2FEJEGX6FfaVTL1bpTMHd7o%2FvK2nzUC10%2FoAqmLDbo7gPOlnxR3Rb15knXAUaZqyrjImQBS0k8q6OT5qNLU4auI%2FEgw5eOqj1WLSlMS2uS1Uc1wGu6wVUGVM1iuxXZFYPTmIjouUngvWRRN7LajulUyFZ7iIHA4m5g651Ov1wtjaoG8kH1qKleHvKk0blqG4j2A8hWrwWGo24fF%2FUPdTPaD11%2F0qMB0Tud0aPTM%2FwL7Ic3vHtc1D%2FO8Nq%2B41gcP%2BrGXntgngr8eifyDrRF1yvOyUZLyFiUilwb%2BU4G6iWl67Y2Vl7rfXkr37Z%2Bmw%2BF8gpqkbdTOVh3r7vuJ3bT%2Fddd133cXXf8D%2Br%2Bpg2e2Y2t%2ForkVOCq1wX9k4Vq%2FcNk6fH65108%2BwU%3D%3C%2Fdiagram%3E%3C%2Fmxfile%3E)

## Реализация программы

Программа написана на языке C

```c
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
```
## Результат работы программы
```
Введите X в диапазоне [5,70]:32,5
Вывод Q(X): 50,00
```
## Информация о разработчике
```
Имя: Страхова Виктория Викторовна
Группа: бИЦТ-261
Вариант: 33
```
