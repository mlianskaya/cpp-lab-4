﻿#include <iostream>
using namespace std;

int main()
{
	unsigned int n;
	cin >> n; //вводим количество чашек
	if (((n*(n + 1)) / 2) % 2 != 0) //если суммарная масса тарелок нечетная, то порции нельзя разбить поровну
	{
		cout << "NO" << endl;
	}
	else
	{
		/* (n*(n + 1)) / 2) % 2 = (n*(n + 1)) % 4
		тк суммарная масса тарелок должна быть кратна 4, то можно рассмотреть 2 случая: n % 4 == 0 и (n+1) % 4 == 0 */
		cout << "YES" << endl;
		if ((n+1) % 4 == 0) // рассмотрим случай, когда количество тарелок нечетное
		{
			cout << n / 2 + 1 << endl; //даем пете четное количество блюдец
			for (int i = 1; i <= n/2; i += 2) /* рассматриваем следующий принцип: откладываем последнюю миску, таким образом количество мисок становитсяя четное
											  первую и последнюю миску отдаем пете, вторую и предпоследнюю отдаем маше (тк первая + последняя = вторая + предпоследняя)
											  по такому алгоритму распрежеляем все тарелки до тех пор, пока они не закончатся, а потом отдаем отложенную миску маше*/
				cout << i << ' ' << n - i <<' ';
			cout << endl;
			cout << n / 2 << endl; //количество мини-порций у маши
			for (int i = 1; i <= n/2; i += 2)
				cout << i << ' ' << n - i << ' ';
			cout << n;
		}
		if (n % 4 == 0) //рассмотрим случай, когда количество мисок четное
		{
			cout << n / 2 << endl; //количество мини-порций у пети
			for (int i = 1; i <= n/2; i += 2) /* все миски распределяем между ребятами по аналогичному с 1 случаем принципу
											  но тк количество мисок четное, то у ребят будет одинаковое количество мини-порций*/
				cout << i << ' ' << n - i+1 << ' ';
			cout << endl;
			cout << n / 2 << endl; //количество мини-порций у маши
			for (int i = 2; i <= n/2; i += 2)
				cout << i << ' ' << n - i + 1 << ' ';
		}

	}
}
