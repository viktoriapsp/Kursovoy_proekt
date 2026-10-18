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
<img width="480" height="732" alt="Диаграмма без названия drawio" src="https://github.com/user-attachments/assets/de141c36-bcb7-4a8d-aacd-73c99fd6f951" />

![Ссылка на блок-схему](https://viewer.diagrams.net/?tags=%7B%7D&lightbox=1&highlight=0000ff&edit=_blank&layers=1&nav=1&title=%D0%94%D0%B8%D0%B0%D0%B3%D1%80%D0%B0%D0%BC%D0%BC%D0%B0%20%D0%B1%D0%B5%D0%B7%20%D0%BD%D0%B0%D0%B7%D0%B2%D0%B0%D0%BD%D0%B8%D1%8F.drawio.png&dark=auto#R%3Cmxfile%3E%3Cdiagram%20name%3D%22%D0%A1%D1%82%D1%80%D0%B0%D0%BD%D0%B8%D1%86%D0%B0-1%22%20id%3D%22Mkn4KjVn3nEORs4h2L9A%22%3E5Zldb5swFIZ%2FDVJbaRHYQMhlk6bdzaRWuVh6yYILaICZcZpkv37HYILJR0MpZcnWKtQ%2BPjbwvC%2BuTTQ8idcPzE2Db9QjkYZ0b63hOw0hwxxh%2BCMimyLiDFER8FnoyaQqMAt%2FExnUZXQZeiSrJXJKIx6m9eCCJglZ8FrMZYyu6mkvNKqfNXV9sheYLdxoP%2Fo99Hgg7wINq%2FhXEvpBeWbDHhUtsVsmyzvJAtejKyWEpxqeMEp5UYrXExIJeCWXot%2F9kdbthTGS8CYdMu4yvt9JjpPxTXnL0A3oQmW8CkJOZqm7EC0rEBhiAY8jqBlQfAmjaEIjyvJ%2B%2BMUSvxDPOKM%2FidJS%2FEBLca5XN1rKc2l3uja6E8exrsGgzrAsw3GcH6eyE2GcrJVrlnf5QGhMONtASqAIYUnqq0o0o1RCjoLLHGlNU1ZdaRl%2FO3JFFQoS7GHIYZIuG0EGN6SiCFluFJGI%2BsyNgVBKWAhnJWy37bFqOK3LmpSPUpc65ccxkqqIowlZc%2FhclTFQUPS04CMTpIT6UL%2FuTEhnR0hUF9LoQkmPLA48YvtCsoDGP5ZZL0%2BLQK0h243F0BHPU3QI4ftWaJ0DaM0dtGYdbScPScpoQ7Z0mXhE9NJ74fsk%2BIqSfnU1%2F4LAsRMEhgfj3ts5esG7%2FM%2FUgY%2FtOmzL2YFtWZ34GF2Aj3PqptWjlbHTkZWb4f1rVsY34GWMBtb11sJWbxbGow4sLCDj84aMbrJfjANosDAaGxVquzvUJ%2FxsoQ78TJf8317AwAJlfHAZ89SXTnYXOpHEayJS70v5W4Vqsay3cuZ2Z3RPLOKHndD1fCJhimKN7iHgdMkW5WNR7bJUHWCUmaxSxgPq08SNplV0XJ%2B6FGXIOuRzER5YsvZctiRwW0qTqD7LAU7pBlfpE3kX2z3LvhiMRC4PX%2BsEPkoWtSOrbK0uhWy5h%2BgJLG4HttrpdMvVUKgqIOeyR0V10GSmUbkqG4jdCciU7w%2F6o26eF%2FVPdTM6DF2d6VGP6K3W6NHlGf4I%2B%2F4Nb58X9c8zvLLvOBfHD9uxVybMS4Ff7UQaopULQn2gWw4%2BTjsf7ZYxd6MkpDRMeKac7FEEqkGHu%2B8OdEtV7mR%2B%2BX7iaP7oY%2FnW6O1803gzHwoFkcqHW9qNrem0t%2BaFzQvvtmZnPrTt89N91F53%2FB%2Fq%2Fq49qN6OrfoW51Lgyjca3ZOFavUla%2BHx6qtqPP0D%3C%2Fdiagram%3E%3C%2Fmxfile%3E)

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
