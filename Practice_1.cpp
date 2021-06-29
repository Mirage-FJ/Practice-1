/**
* @file Practice_1.cpp
* @author Харченко В.В.., гр. 515-Б
* @date 21 червня 2021
* @brief Практична робота № 1
*
* Індивідуальне заняття. Завдання 27
*/
/*--------------------/ подключение заголовочных файлов стандартных библиотек языка C \--------------------*/
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <math.h>

/*--------------------/ Локальные переменные \--------------------*/
char dest[12], tr_fl;
int len;
long long src;

/*--------------------/ Функции \--------------------*/
void scan(char dest[]);
void casse(char dest[], long long src);
void one(int massive[]);
void two(int massive[]);
void three(int massive[]);
void four(int massive[]);
void five(int massive[]);
void six(int massive[]);
void seven(int massive[]);
void eight(int massive[]);
void nine(int massive[]);
void ten(int massive[]);
void eleven(int massive[]);
void function_len(int massive[]);

int main() {
	/*--------------------/ Подключение русского языка \--------------------*/
	setlocale(LC_CTYPE, "rus");
	/*--------------------/ Запрос числа \--------------------*/
	printf("Введите целое число в диапазоне 32-битного знакового числа: ");
	fgets(dest, 13, stdin);
	scan(dest);
	/*--------------------/ Перевод строки в число \--------------------*/
	src = atoll(dest);
	/*--------------------/ Пределы числа в диапазоне 32 - бит \--------------------*/
	if (src > INT_MAX || src < INT_MIN) {
		printf("Error");
		exit(0);
	}
	/*--------------------/ Вывод введёного числа \--------------------*/
	printf("%lld = ", src);
	casse(dest, src);
	printf("\n");
	/*--------------------/ Пауза \--------------------*/
	system("pause");
	return 0;
}

/*--------------------/ Функция проверяет коректность ввода числа \--------------------*/
/*
* @param dest[] - входной масив
* Функция ничего не возвращает
*/
void scan(char dest[]) {
	/*--------------------/ Цикл \--------------------*/
	for (int i = 0; i < 13; i++) {
		/*--------------------/ Условие завершения цикла \--------------------*/
		if (dest[i] == '\n') break;
		/*--------------------/ Условие проверки введёной строки \--------------------*/
		if (isdigit(dest[i]) == 0 && dest[i] != '-') {
			printf("Error");
			exit(0);
		}
	}
}

/*--------------------/ Функция обработки введёного числа \--------------------*/
/*
* @param dest[] - входной масив
* @param src - входное число
* Функция ничего не возвращает
*/
void casse(char dest[],long long src) {
	int massive[13];
	/*--------------------/ Условие если число отрицательное \--------------------*/
	if (dest[0] == '-') {
		/*--------------------/ Цикл разделения числа на массив \--------------------*/
		for (int i = 0; i < 13; i++) {
			massive[i] = fabs(src % 10);
			src /= 10;
			/*--------------------/ Длинна введёного числа \--------------------*/
			len = i + 1;
			if (src > -1)
				break;
		}
		len = len - 1;
		if (len == 0 && massive[0] == 0) {
			printf("Нуль");
			exit(0);
		}
		printf("мiнус ");
	}
	/*--------------------/ Условие положительного числа \--------------------*/
	else {
		for (int i = 0; i < 13; i++) {
			/*--------------------/ Цикл разделения числа на массив \--------------------*/
			massive[i] = src % 10;
			src /= 10;
			/*--------------------/ Длинна введёного числа \--------------------*/
			len = i;
			if (src < 1)
				break;
		}
		if (len == 0 && massive[0] == 0) {
			printf("Нуль");
			exit(0);
		}
	}
	function_len(massive);
}

/*--------------------/ Функция определяющая величену числа \--------------------*/
/*
* @param massive[] - входной массив
* Функция ничего не возвращает
*/
void function_len(int massive[]) {
	/*--------------------/ Кейс с длиной числа \--------------------*/
	switch (len) {
	case 0: one(massive); break;
	case 1: two(massive); break;
	case 2: three(massive); break;
	case 3: four(massive); break;
	case 4: five(massive); break;
	case 5: six(massive); break;
	case 6: seven(massive); break;
	case 7: eight(massive); break;
	case 8: nine(massive); break;
	case 9: ten(massive); break;
	default:
		break;
	}
}

/*--------------------/ Функция вывода едениц \--------------------*/
/*
* @param massive[] - входной массив
* Функция ничего не возвращает
*/
void one(int massive[]) {
	/*--------------------/ Кейс с массивом со значением чисел \--------------------*/
	switch (massive[len]) {
	case 1: printf("один"); break;
	case 2: printf("два"); break;
	case 3: printf("три"); break;
	case 4: printf("чотири"); break;
	case 5: printf("п'ять"); break;
	case 6: printf("шiсть"); break;
	case 7: printf("сiм"); break;
	case 8: printf("вiсiм"); break;
	case 9: printf("дев'ять"); break;
	default:
		break;
	}
}

/*--------------------/ Функция вывода десятков \--------------------*/
/*
* @param massive[] - входной массив
* Функция ничего не возвращает
*/
void two(int massive[]) {
	/*--------------------/ Кейс с массивом со значением чисел \--------------------*/
	switch (massive[len]) {
	case 0: len = len - 1; one(massive); break;
	case 1: len = len - 1; eleven(massive); break;
	case 2: printf("двадцять "); len = len - 1; one(massive); break;
	case 3: printf("тридцять "); len = len - 1; one(massive); break;
	case 4: printf("сорок "); len = len - 1; one(massive); break;
	case 5: printf("п'ятдесят "); len = len - 1; one(massive); break;
	case 6: printf("шiстдесят "); len = len - 1; one(massive); break;
	case 7: printf("сiмдесят "); len = len - 1; one(massive); break;
	case 8: printf("вiсiмдесят "); len = len - 1; one(massive); break;
	case 9: printf("дев'яносто "); len = len - 1; one(massive); break;
	default:
		break;
	}
}

/*--------------------/ Функция вывода чисел от 10 да 19 \--------------------*/
/*
* @param massive[] - входной массив
* Функция ничего не возвращает
*/
void eleven(int massive[]) {
	/*--------------------/ Кейс с массивом со значением чисел \--------------------*/
	switch (massive[len]) {
	case 0: printf("десять "); break;
	case 1: printf("одинадцять "); break;
	case 2: printf("дванадцять "); break;
	case 3: printf("тринадцять "); break;
	case 4: printf("чотрнадцять "); break;
	case 5: printf("п'ятнадцять "); break;
	case 6: printf("шiснадцать "); break;
	case 7: printf("сiмнадцять "); break;
	case 8: printf("вiсiмнадцять "); break;
	case 9: printf("дев'ятнадцять "); break;
	default:
		break;
	}
	len = len - 1;
}

/*--------------------/ Функция вывода сотен \--------------------*/
/*
* @param massive[] - входной массив
* Функция ничего не возвращает
*/
void three(int massive[]) {
	/*--------------------/ Кейс с массивом со значением чисел \--------------------*/
	switch (massive[len]) {
	case 1: printf("сто "); break;
	case 2: printf("двiстi "); break;
	case 3: printf("триста "); break;
	case 4: printf("чотириста "); break;
	case 5: printf("п'ятсот "); break;
	case 6: printf("шiстсот "); break;
	case 7: printf("сiмсот "); break;
	case 8: printf("вiсiмсот "); break;
	case 9: printf("дев'ятсот "); break;
	default:
		break;
	}
	len = len - 1;
	two(massive);
}

/*--------------------/ Функция вывода тысяч \--------------------*/
/*
* @param massive[] - входной массив
* Функция ничего не возвращает
*/
void four(int massive[]) {
	/*--------------------/ Кейс с массивом со значением чисел \--------------------*/
	switch (massive[len]) {
	case 1: printf("одна тисяча "); break;
	case 2: printf("двi тисячi ");  break;
	case 3: printf("три тисячi ");  break;
	case 4: printf("чотири тисячi ");  break;
	case 5: printf("п'ять тисяч ");  break;
	case 6: printf("шiсть тисяч ");  break;
	case 7: printf("сiм тисяч ");  break;
	case 8: printf("вiсiм тисяч ");  break;
	case 9: printf("дев'ять тисяч "); break;
	default: 
		if (massive[3] == 0 && massive[4] == 0 && massive[5] == 0);else printf("тисяч ");
		break;
	}
	len = len - 1;
	three(massive);
}

/*--------------------/ Функция вывода десятков тысяч \--------------------*/
/*
* @param massive[] - входной массив
* Функция ничего не возвращает
*/
void five(int massive[]) {
	/*--------------------/ Кейс с массивом со значением чисел \--------------------*/
	switch (massive[len]) {
	case 1:	len = len - 1; eleven(massive); printf("тисяч "); three(massive); break;
	case 2: printf("двадцять "); len = len - 1; four(massive); break;
	case 3: printf("тридцять "); len = len - 1; four(massive); break;
	case 4: printf("сорок "); len = len - 1; four(massive); break;
	case 5: printf("п'ятдесят "); len = len - 1; four(massive); break;
	case 6: printf("шiстдесят "); len = len - 1; four(massive); break;
	case 7: printf("сiмдесят "); len = len - 1; four(massive); break;
	case 8: printf("вiсiмдесят "); len = len - 1; four(massive); break;
	case 9: printf("дев'яносто "); len = len - 1; four(massive); break;
	default:
		len = len - 1; four(massive);
		break;
	}
}

/*--------------------/ Функция вывода сотен тысяч \--------------------*/
/*
* @param massive[] - входной массив
* Функция ничего не возвращает
*/
void six(int massive[]) {
	/*--------------------/ Кейс с массивом со значением чисел \--------------------*/
	switch (massive[len]) {
	case 1: printf("сто "); break;
	case 2: printf("двiстi "); break;
	case 3: printf("триста "); break;
	case 4: printf("чотириста "); break;
	case 5: printf("п'ятсот "); break;
	case 6: printf("шiстсот "); break;
	case 7: printf("сiмсот "); break;
	case 8: printf("вiсiмсот "); break;
	case 9: printf("дев'ятсот "); break;
	default:
		break;
	}
	len = len - 1;
	five(massive);
}

/*--------------------/ Функция вывода милионов \--------------------*/
/*
* @param massive[] - входной массив
* Функция ничего не возвращает
*/
void seven(int massive[]) {
	/*--------------------/ Кейс с массивом со значением чисел \--------------------*/
	switch (massive[len]) {
	case 1: printf("один мiльйон "); break;
	case 2: printf("два мiльйони "); break;
	case 3: printf("три мiльйони "); break;
	case 4: printf("чотири мiльйони "); break;
	case 5: printf("п'ять мiльйонiв "); break;
	case 6: printf("шiсть мiльйонiв "); break;
	case 7: printf("сiм мiльйонiв "); break;
	case 8: printf("вiсiм мiльйонiв "); break;
	case 9: printf("дев'ять мiльйонiв "); break;
	default:
		if (massive[6] == 0 && massive[7] == 0 && massive[8] == 0); else printf("мiльйонiв ");
		break;
	}
	len = len - 1;
	six(massive);
}

/*--------------------/ Функция вывода десятков милионов \--------------------*/
/*
* @param massive[] - входной массив
* Функция ничего не возвращает
*/
void eight(int massive[]) {
	/*--------------------/ Кейс с массивом со значением чисел \--------------------*/
	switch (massive[len]) {
	case 1:	len = len - 1; eleven(massive); printf("мiльйонiв "); six(massive); break;
	case 2: printf("двадцять "); len = len - 1; seven(massive); break;
	case 3: printf("тридцять "); len = len - 1; seven(massive); break;
	case 4: printf("сорок "); len = len - 1; seven(massive); break;
	case 5: printf("п'ятдесят "); len = len - 1; seven(massive); break;
	case 6: printf("шiстдесят "); len = len - 1; seven(massive); break;
	case 7: printf("сiмдесят "); len = len - 1; seven(massive); break;
	case 8: printf("вiсiмдесят "); len = len - 1; seven(massive); break;
	case 9: printf("дев'яносто "); len = len - 1; seven(massive); break;
	default:
		len = len - 1; seven(massive);
		break;
	}
}

/*--------------------/ Функция вывода сотен милионов \--------------------*/
/*
* @param massive[] - входной массив
* Функция ничего не возвращает
*/
void nine(int massive[]) {
	/*--------------------/ Кейс с массивом со значением чисел \--------------------*/
	switch (massive[len]) {
	case 1: printf("сто "); break;
	case 2: printf("двiстi "); break;
	case 3: printf("триста "); break;
	case 4: printf("чотириста "); break;
	case 5: printf("п'ятсот "); break;
	case 6: printf("шiстсот "); break;
	case 7: printf("сiмсот "); break;
	case 8: printf("вiсiмсот "); break;
	case 9: printf("дев'ятсот "); break;
	default:
		break;
	}
	len = len - 1;
	eight(massive);
}

/*--------------------/ Функция вывода милиардов \--------------------*/
/*
* @param massive[] - входной массив
* Функция ничего не возвращает
*/
void ten(int massive[]) {
	/*--------------------/ Кейс с массивом со значением чисел \--------------------*/
	switch (massive[len]) {
	case 1: printf("один мiльярд "); break;
	case 2: printf("два мiльярди "); break;
	default:
		break;
	}
	len = len - 1;
	nine(massive);
}