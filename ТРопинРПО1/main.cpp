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




//struct People
//{
//	std::string selfName;
//
//	static constexpr int friendSize = 4;
//	std::string friendsName[friendSize];
//
//	void SayHello()
//	{
//		std::cout << "Меня зовут " << selfName;
//	}
//
//	void setName()
//	{
//		std::string choose;
//		while (true)
//		{
//			std::cout << "Выберете друга по ид для смены имени, либо же введите 0 для смены своего имени: ";
//			std::getline(std::cin, choose, '\n');
//
//			std::cout << "Введите новое имя ";
//
//			if (std::stoi(choose)!= 0)
//			{
//				
//				std::getline(std::cin, friendsName[std::stoi(choose) - 1], '\n');
//				break;
//			}
//			else
//			{
//				std::getline(std::cin, selfName, '\n');
//				break;
//			}
//		}
//
//	}
//};
//
//void Fill(People &one, static int friendSize)
//{
//	std::cout << "Введите свое имя: ";
//	std::getline(std::cin, one.selfName, '\n');
//
//	for (int i = 0; i < friendSize; i++)
//	{
//		std::cout << "Введите имя друга номер " << i + 1 << ": ";
//		std::getline(std::cin, one.friendsName[i], '\n');
//	}
//}
//
//void Print(People& one, static int friendSize)
//{
//	for (int i = 0; i < friendSize; i++)
//	{
//		std::cout << "Id: " << i + 1 << "| Имя: " << one.friendsName[i] << " | ";
//	}
//}

//class NewHuman
//{
//public:
//	NewHuman(int one)
//	{
//		a = one;
//		b = one + 100;
//	}
//	NewHuman()
//	{
//		a = 10;
//		b = 20;
//		std::cout << "Я родился\n";
//		this->age = age;
//	}
//	NewHuman(int one, int two) : a(one), b(two) {}
//
//	~NewHuman()
//	{	
//		delete[]p;
//
//		std::cout << "dead";
//	}
//
//	int a;
//	int b;
//	int age;
//
//	int* p = new int[10];
//private:
//	
//
//
//};



class Drobi
{
public:
	
	void Fill()
	{
		std::cout << "Введите числитель: ";
		std::cin >> chisl;
		std::cout << "Введите знаменатель: ";
		std::cin >> znam;
	}

	void Plus(Drobi oneDrob, Drobi twoDrob, Drobi res)
	{
		res.znam = oneDrob.znam * twoDrob.znam;
		res.chisl = oneDrob.chisl + twoDrob.chisl;
		Print(res);
	}

	void Minus(Drobi oneDrob, Drobi twoDrob, Drobi res)
	{
		res.znam = oneDrob.znam * twoDrob.znam;
		res.chisl = oneDrob.chisl - twoDrob.chisl;
		Print(res);
	}

	void Umnosh(Drobi oneDrob, Drobi twoDrob, Drobi res)
	{
		res.chisl = oneDrob.chisl * twoDrob.znam;
		res.znam = oneDrob.znam * twoDrob.chisl;
		Print(res);
	}

	void Delenie(Drobi oneDrob, Drobi twoDrob, Drobi res)
	{
		double temp;

		temp = twoDrob.chisl;
		twoDrob.chisl = twoDrob.znam;
		twoDrob.znam = temp;

		res.chisl = oneDrob.chisl * twoDrob.znam;
		res.znam = oneDrob.znam * twoDrob.chisl;
		Print(res);
	}



	double chisl, znam;
private:
	
	void Print(Drobi res)
	{
		std::cout << "Результат: \n" << res.chisl << "\n____\n" << res.znam;
	}
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	/*People one;
	const int friendSize = one.friendSize;
	Fill(one, friendSize);
	Print(one,friendSize);
	
	std::cout << "\n\n\n";
	one.setName();
	Print(one, friendSize);*/

	Drobi oneDrob, twoDrob, res;
	int choose;

	res.znam = 1;
	res.chisl = 0;

	oneDrob.Fill();
	twoDrob.Fill();

	std::cout << "Выберите действие\n1.+\n2.-\n3.*\n4./:5. Неправильную в правильную\n ";
	std::cin >> choose;

	switch (choose)
	{
	case 1:
		oneDrob.Plus(oneDrob, twoDrob, res);
		break;
	case 2:
		oneDrob.Minus(oneDrob, twoDrob, res);
		break;
	case 3:
		oneDrob.Umnosh(oneDrob, twoDrob, res);
		break;
	case 4:
		oneDrob.Delenie(oneDrob, twoDrob, res);
		break;
	default:
		std::cout << "Error";
	}
	
	

	return 0;
}