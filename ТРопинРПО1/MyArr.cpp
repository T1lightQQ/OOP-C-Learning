#include "MyArr.hpp"

MyArr::MyArr(size_t size)
{
	this->arrSize = size;
	this->ptr = std::make_unique<int[]>(size);
}

MyArr::MyArr(std::initializer_list<int> list)
{
	this->arrSize = list.size();
	this->ptr = std::make_unique<int[]>(list.size());
	std::copy(std::begin(list), std::end(list), this->ptr.get());
}

MyArr::MyArr(const MyArr& originalArr)
{
	this->arrSize = originalArr.size();
	this->ptr = std::make_unique<int[]>(originalArr.size());

	const std::span<const int> source{ originalArr.ptr.get(), originalArr.size() };
	std::copy(std::begin(source), std::end(source), this->ptr.get());
}

MyArr& MyArr::operator=(const MyArr& originalArr)
{
	MyArr temp(originalArr);
	if (this != &originalArr)
	{
		swap(*this, temp);
	}

	return *this;
}

size_t MyArr::size() const noexcept
{
	return this->arrSize;
}

void MyArr::swap(MyArr& firstObj, MyArr& secondObj) noexcept
{
	std::swap(firstObj.arrSize, secondObj.arrSize);
	firstObj.ptr.swap(secondObj.ptr);
}
