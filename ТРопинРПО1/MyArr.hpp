#ifndef _MY_ARR_HPP_
#define _MY_ARR_HPP_
#include <memory>
#include <initializer_list>
#include <iostream>
#include <Windows.h>
#include <span>

class MyArr
{
public:
	explicit MyArr(size_t size);
	explicit MyArr(std::initializer_list<int> list);

	MyArr(const MyArr& originalArr);

	MyArr& operator= (const MyArr& originalArr);


	size_t size() const noexcept;


private:
	std::unique_ptr<int[]> ptr;
	size_t arrSize{0};

	void swap(MyArr& firstObj, MyArr& secondObj) noexcept;
};

#endif
