#ifndef _MY_ARR_HPP_
#define _MY_ARR_HPP_
#include <memory>
#include <initializer_list>
#include <iostream>
#include <Windows.h>
#include <span>
#include <utility>
#include <sstream>
#include <algorithm>

class MyArr 
{
public:
	explicit MyArr(size_t size);
	explicit MyArr(std::initializer_list<int> list);

	MyArr(const MyArr& originalArr);

	MyArr& operator= (const MyArr& originalArr);

	MyArr(MyArr&& originalArr) noexcept;
	MyArr& operator= (MyArr&& originalArr) noexcept;
	
	bool operator== (const MyArr& originalArr) const noexcept;

	int& operator[](size_t index);
	const int& operator[](size_t index) const;

	std::string toString() const;

	explicit operator bool() const noexcept;

	MyArr& operator++();
	MyArr operator++(int);

	MyArr& operator+=(int value);
	MyArr operator/ (const MyArr& name) const;

	size_t size() const noexcept;

private:
	std::unique_ptr<int[]> ptr;
	size_t arrSize{0};
	void swap(MyArr& firstObj, MyArr& secondObj) noexcept;

	friend std::istream& operator >> (std::istream& in, MyArr& obj);
};

std::ostream& operator << (std::ostream& out, const MyArr& obj);

#endif
