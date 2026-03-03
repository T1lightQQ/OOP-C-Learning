//#include "test.hpp"
#include "MyArr.hpp";

enum MyEnum
{

};

enum class MyEnumClass
{

};

union MyUnion
{

};


class Animal
{
public:
	void Print()
	{
		std::cout << "Имя: " << GetName() << "\nВозраст: " << GetAge() << "\nВес: " << GetWeight();
		std::cout << std::endl;
			}

	std::string GetName() { return name; }

	int GetAge() { return age; }

	int GetWeight() { return weight; }

	void SetName()
	{
		std::cout << "Введите имя животного: ";
		std::cin >> name;
	}

	void SetAge()
	{
		std::cout << "Введите возраст животного: ";
		std::cin >> age;
	}

	void SetWeight()
	{
		std::cout << "Введите вес животного: ";
		std::cin >> weight;
	}

private:
	std::string name;
	int age;
	int weight;
};

class Cat : public Animal
{
public:
	using Animal::Animal;
private:

};

class Dog : public Animal
{
public:
	using Animal::Animal;
private:

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

//class Drobi
//{
//public:
//	
//	void Fill()
//	{
//		int choose;
//		std::cout << "Выберете способ создания дроби: 1. Десятичной 2. Ввод числителя и знаменателя\n";
//		std::cin >> choose;
//		
//		if (choose == 1)
//		{
//			FillChooseOne();
//		}
//		else if (choose == 2)
//		{
//			FillChooseTwo();
//		}
//	}
//
//	void chooseOperation(Drobi oneDrob, Drobi twoDrob, Drobi res)
//	{
//		int choose;
//
//		std::cout << "Выберите дейсвтие: \n1. Плюс\n2. Минус\n3. Умножить\n4. Деление\n";
//		std::cin >> choose;
//		
//		switch (choose)
//		{
//		case 1:
//			Plus(oneDrob,twoDrob, res);
//			break;
//		case 2:
//			Minus(oneDrob, twoDrob, res);
//			break;
//		case 3:
//			Umnosh(oneDrob, twoDrob, res);
//			break;
//		case 4:
//			Delenie(oneDrob, twoDrob, res);
//			break;
//		default:
//			break;
//		}
//	}
//
//
//
//	double chisl, znam;
//	int celChast = 0;
//private:
//	
//	void Print(Drobi res)
//	{
//		system("cls");
//		std::cout << "\n\nРезультат: \n" << "Целая часть: " << res.celChast << "\n" << "Дробная часть\n" << res.chisl << "\n____\n" << res.znam;
//	}
//
//	Drobi Plus(Drobi oneDrob, Drobi twoDrob)
//	{
//		if (celChast != 0) { oneDrob.chisl = oneDrob.celChast * oneDrob.znam + oneDrob.chisl; }
//
//		res.znam = oneDrob.znam * twoDrob.znam;
//
//		res.chisl = (oneDrob.chisl * twoDrob.znam) + (twoDrob.chisl * twoDrob.znam);
//		
//		return res;
//	}
//
//	Drobi Minus(Drobi oneDrob, Drobi twoDrob)
//	{
//		if (celChast != 0) { oneDrob.chisl = oneDrob.celChast * oneDrob.znam + oneDrob.chisl; }
//
//		res.znam = oneDrob.znam * twoDrob.znam;
//
//		res.chisl = (oneDrob.chisl * twoDrob.znam) - (twoDrob.chisl * twoDrob.znam);
//		
//		return res;
//	}
//
//	Drobi Umnosh(Drobi oneDrob, Drobi twoDrob)
//	{
//		res.chisl = oneDrob.chisl * twoDrob.znam;
//		res.znam = oneDrob.znam * twoDrob.chisl;
//		
//		return res;
//	}
//
//	Drobi Delenie(Drobi oneDrob, Drobi twoDrob)
//	{
//		double temp;
//
//		temp = twoDrob.chisl;
//		twoDrob.chisl = twoDrob.znam;
//		twoDrob.znam = temp;
//
//		res.chisl = oneDrob.chisl * twoDrob.znam;
//		res.znam = oneDrob.znam * twoDrob.chisl;
//		
//		return res;
//	}
//
//	void FillChooseTwo()
//	{
//		std::cout << "Введите числитель: \n";
//		std::cin >> chisl;
//		std::cout << "Введите целую часть: \n";
//		std::cin >> celChast;
//		std::cout << "Введите знаменатель: \n";
//		std::cin >> znam;
//	}
//
//	void FillChooseOne()
//	{
//		double num;
//		std::cout << "Введите десятичную дробь: ";
//		std::cin >> num;
//
//		
//	}
//
//	
//};


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

	/*Drobi oneDrob, twoDrob, res;
	int choose;

	res.znam = 1;
	res.chisl = 0;

	oneDrob.Fill();
	twoDrob.Fill();

	oneDrob.chooseOperation(oneDrob, twoDrob, res);*/
	/*PrintHello();*/
	
	Cat cat1;
	Dog dog1;

	cat1.SetName();
	cat1.SetAge();
	cat1.SetWeight();

	dog1.SetName();
	dog1.SetAge();
	dog1.SetWeight();

	cat1.Print();
	dog1.Print();
	
	

	
	/*MyArr arr(4);

	std::cin >> arr;

	std::cout << arr;*/
	
	return 0;
}
