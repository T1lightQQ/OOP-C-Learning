#include <iostream>
#include <Windows.h>
#include <string>

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
	std::string selfName;

	static constexpr int friendSize = 4;
	std::string friendsName[friendSize];

	void SayHello()
	{
		std::cout << "Меня зовут " << selfName;
	}

	void ChangeName()
	{
		std::string choose;
		while (true)
		{
			std::cout << "Выберете друга по ид для смены имени, либо же введите 0 для смены своего имени: ";
			std::getline(std::cin, choose, '\n');

			std::cout << "Введите новое имя ";

			if (std::stoi(choose)!= 0)
			{
				
				std::getline(std::cin, friendsName[std::stoi(choose)], '\n');
			}
			else
			{
				std::getline(std::cin, selfName, '\n');
			}
		}


	}
};


void Fill(People &one, static int friendSize)
{
	std::cout << "Введите свое имя: ";
	std::getline(std::cin, one.selfName, '\n');

	for (int i = 0; i < friendSize; i++)
	{
		std::cout << "Введите имя друга номер " << i + 1;
		std::getline(std::cin, one.friendsName[i], '\n');
	}
}

void Print(People& one, static int friendSize)
{
	for (int i = 0; i < friendSize; i++)
	{
		std::cout << "Id: " << i + 1 << "Имя: " << one.friendsName[i];
	}
}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	People one;
	const int friendSize = one.friendSize;
	Fill(one, friendSize);
	Print(one,friendSize);
	
	std::cout << "\n\n\n";
	one.SayHello();

	return 0;
}