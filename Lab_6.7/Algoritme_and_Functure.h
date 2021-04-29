#pragma once

// інтерфейс, що описує функтори - унарні предикати
template<class T>
class Predicate {
public:
	virtual bool operator () (T x) = 0;		//чистий віртуальний метод(абстрактний метод)
};

// реалізуємо інтерфейс функтором - перевірка, чи значення дорівнює нулю
template<class T>
class Zero : public Predicate<T> {	//клас-функтор - інтерфейс
public:
	virtual bool operator () (T x) {	//віртуальне перевантаження операції ()
		T zero = T();
		return x == zero;
	}
};

// реалізуємо інтерфейс функтором - перевірка, чи значення додатне
template<class T>
class Positive : public Predicate<T> {	//клас-функтор - успадкований від класу(інтерфейсу) "Predicate" - реалізація
public:
	virtual bool operator () (T x) {	//віртуальне перевантаження операції ()
		return x > 0;
	}
};

// реалізуємо інтерфейс функтором - перевірка, чи значення від'ємне
template<class T>
class Negative : public Predicate<T> {	//клас-функтор - успадкований від класу(інтерфейсу) "Predicate" - реалізація
public:
	virtual bool operator () (T x) {	//віртуальне перевантаження операції ()
		return x < 0;
	}
};

// реалізуємо інтерфейс функтором - перевірка, чи значення парне
template<class T>
class Even : public Predicate<T> {	//клас-функтор - успадкований від класу(інтерфейсу) "Predicate" - реалізація
public:
	virtual bool operator () (T x) {	//віртуальне перевантаження операції ()
		return x % 2 == 0;
	}
};

// реалізуємо інтерфейс функтором - перевірка, чи значення не парне
template<class T>
class Odd : public Predicate<T> {	//клас-функтор - успадкований від класу(інтерфейсу) "Predicate" - реалізація
public:
	virtual bool operator () (T x) {	//віртуальне перевантаження операції ()
		return x % 2 != 0;
	}
};