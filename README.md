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
<img width="490" height="732" alt="Диаграмма без названия drawio" src="https://github.com/user-attachments/assets/12915bcc-6369-462d-952b-79b5f92827b2" />


![Ссылка на блок-схему](https://viewer.diagrams.net/?tags=%7B%7D&lightbox=1&highlight=0000ff&edit=_blank&layers=1&nav=1&title=%D0%94%D0%B8%D0%B0%D0%B3%D1%80%D0%B0%D0%BC%D0%BC%D0%B0%20%D0%B1%D0%B5%D0%B7%20%D0%BD%D0%B0%D0%B7%D0%B2%D0%B0%D0%BD%D0%B8%D1%8F.drawio.png&dark=auto#R%3Cmxfile%3E%3Cdiagram%20name%3D%22%D0%A1%D1%82%D1%80%D0%B0%D0%BD%D0%B8%D1%86%D0%B0-1%22%20id%3D%22Mkn4KjVn3nEORs4h2L9A%22%3E7Zpfb9sqFMA%2FjaV20iKM%2F%2BZxabvdlytt6sPtHllMbWvYeIQsyT79BYNj7DhL6rDMnRapDhwOGJ%2FfOcdA43h3xfYDQ1X2L00wcSBIto5370DoQt8VX1KyU5IIBkqQsjzRSq3gMf%2BBtRBo6TpP8KqjyCklPK%2B6wiUtS7zkHRlijG66as%2BUdO9aoRQfCB6XiBxK%2F8sTnilpDKNW%2Fg%2FO06y5sxvOVUuBGmX9JKsMJXRjiLwHx7tjlHJVKrZ3mEjjNXZR%2Fd4fad1PjOGSn9NhxRHjh530OCu%2Bax5ZdBPWFZXFJss5fqzQUrZsBGAhy3hBRM0VxeeckDtKKKv7ec%2F1R8hXnNGv2GgB9Uf2oCUfkqsejYGFaRZqVt8RWetZOffAmd%2FL6wI44vZx1JTFdVFfH3QnzDjeGk%2Bn7fEB0wJzthMqmYEs0Hw2LV63YaZH8Rod7cS%2BriLtXOl%2B5Nb%2BoqARDOPIy2p9Fg7hN5UsCi1ECCY0ZagQFqowy8VdMeu3fWwbThPc4ibofg%2FR%2BrqAmp%2B8%2BkLrSfzdNDLBWvYUeQNoBQ0bRODWGvK4hxx2kbs2mCd4ORC2h8hZRosv69XEIlBCcWCICjkJwmsVIETe%2B1EQ4gEIfg%2BC34VgJfAqRs%2BkQNdlgmUvMEUSsgRubmT5bQ1CxAJ4I2WG6LZmJgCBsC5JZC5ox3wZsvB03ARxD1lgJ27gHxU3NTs%2FuGLoeLGl0DkPxCsIHa8fLh6cBbf7KAmuGSXe3BId70%2BhAzWd1TfG94T8oE1iLanwV5LqrwMCYIEUXfO%2Fiz%2B1%2BBOLu8XgEvDTzZO9xd2J5BhCC1BxmZxDdMK7q3cGArXTCmpAoTUOJ%2FZVkRUOSYq12WWxw2EIDV2zZRNt7RbZJCZGedRVynhGU1oi8tBKF92EajDE25w%2FSfEs0LXPTUspHstoktXPeoDjhI%2BRFPNOsX6u%2FcbyEA%2FDBPH8e9cml9oajrO1sf99vbZuNnRXMrU3ztTtttOupV3DzoZplaUB8Du2noVBaCl7EfQFkwVafk3rKQ4lyfq%2B91s9d1XbmTXjPamE4jlafVlp1Idzpa9Pn86Hr3PeWzBzQeAdd4h6uHeMoZ2hUNG85CvTX4rtRylrB%2Fb7O6%2Bol0yVS%2BhePxlILE5nEeyNNZ%2FFUXc4FQcHw9V%2BvLfF2a7tT8u1bSURq049mH%2FgsH%2Ba7294xRQVjOYIr52iuukp%2BJ0cjY315YnmUoThtBC%2BklA0dt9TicVoHEjjgHSaJM9ZmbVb7Je9nsHMC4Jw9Nt5%2BI0ahb3jHtD7V90J%2FeZVfkw%2FBpfpN8dRR5cW7k%2F1RUFZ5JIFQDzeWSeddn6Js1rzzDCanifMx3uC99cTXnpSAsZZ2zzCfL3m1md29m0tqu0vO1QctL%2BP8R7%2BBw%3D%3D%3C%2Fdiagram%3E%3C%2Fmxfile%3E)

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
```
