#include "Array.h"
#include "Algoritme_and_Functure.h"
#include "Algoritme_and_Functure.cpp"


/*Функція що приймає звичайний масив і розмір масиву як аргумент, і
повертає динамічний масив зростаючої довжини як результат*/
Array Create_Dynamic_Array(int* masuv, const int size) {
	Array dynamic_array(size);
	for (int i = 0; i < size; i++)
		dynamic_array[i] = masuv[i];

	return dynamic_array;
}

int main(void) {
	srand((unsigned)time(NULL));
	const int size = 10;
	int masuv[size];

	int start = -30;
	int end = 30;

	//Початковий масив заповнили випадковими числами в діапазоні від –50 до +50
	for (int i = 0; i < size; i++)
		masuv[i] = start + rand() % int(end - start + 1);

	Array a = Create_Dynamic_Array(masuv, size);	//вхідний контейнер
	Array v_a(4), b(4), c(4), d(4), f(4), g(4);		//результуючі контейнери
	std::cout << a;
	std::cout << "\n\n";
	system("pause");

	Search_End(&a[size], &v_a[0]);
	std::cout << v_a;
	std::cout << "\n\n";
	system("pause");

	Predicate<int>* zero = new Zero<int>();
	int n = Search_End_if(&a[size], &b[0], *zero); // продубювали нульові елементи
	for (; n < 4; n++)
		b.Pop_back();
	std::cout << b;
	delete zero;
	std::cout << "\n\n";
	system("pause");

	Predicate<int>* positive = new Positive<int>();
	n = Search_End_if(&a[size], &c[0], *positive); // продубювали нульові елементи
	for (; n < 4; n++)
		c.Pop_back();
	std::cout << c;
	delete positive;
	std::cout << "\n\n";
	system("pause");

	Predicate<int>* negative = new Negative<int>();
	n = Search_End_if(&a[size], &d[0], *negative); // продубювали нульові елементи
	for (; n < 4; n++)
		d.Pop_back();
	std::cout << d;
	delete negative;
	std::cout << "\n\n";
	system("pause");

	Predicate<int>* even = new Even<int>();
	n = Search_End_if(&a[size], &f[0], *even); // продубювали нульові елементи
	for (; n < 4; n++)
		f.Pop_back();
	std::cout << f;
	delete even;
	std::cout << "\n\n";
	system("pause");

	Predicate<int>* odd = new Odd<int>();
	n = Search_End_if(&a[size], &g[0], *odd); // продубювали нульові елементи
	for (; n < 4; n++)
		g.Pop_back();
	std::cout << g;
	delete odd;
	std::cout << "\n\n";
	system("pause");

	return 0;
}