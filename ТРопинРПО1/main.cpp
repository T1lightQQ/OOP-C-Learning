#include <iostream>
#include <Windows.h>

enum MyEnum
{

};

enum class MyEnumClass
{

};

union MyUnion
{

};





class MyClass
{
public:
	MyClass();
	~MyClass();

private:

};

MyClass::MyClass()
{

}

MyClass::~MyClass()
{

}


struct People
{
	int age = 0;
	double height = 0;
	int sizeLeg = 0;
	std::string name;
	bool eyes[2]{1, 1};
};


void Fill(People &one)
{
	std::cout << "Введите возраст" << "\n";
	std::cin >> one.age;

	std::cout << "Введите рост" << "\n";
	std::cin >> one.height;

	std::cout << "Введите размер ноги" << "\n";
	std::cin >> one.sizeLeg;

	std::cout << "Введите имя" << "\n";
	std::cin >> one.name;

	std::cout << "Введите наличие левого глаза(1 Есть, 0 Нету)" << "\n";
	std::cin >> one.eyes[0];

	std::cout << "Введите наличие правого глаза(1 Есть, 0 Нету)" << "\n";
	std::cin >> one.eyes[1];
}

void Print(People one)
{
	std::cout << "Результаты:" << "\n";
	std::cout << "Возраст: " << one.age << "\n";
	std::cout << "Рост: " << one.height << "\n";
	std::cout << "Размер ноги: " << one.sizeLeg << "\n";
	std::cout << "Имя:" << one.name << "\n";
	std::cout << "Наличие левого глаза:" << one.eyes[0] << "\n";
	std::cout << "Наличие правого глаза:" << one.eyes[1] << "\n";
}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	People one;
	Fill(one);
	Print(one);

	return 0;
}