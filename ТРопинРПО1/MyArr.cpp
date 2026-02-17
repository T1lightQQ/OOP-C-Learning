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

MyArr::MyArr(MyArr&& originalArr) noexcept
{
	this->arrSize = std::exchange(originalArr.arrSize, 0);
	this->ptr = std::move(originalArr.ptr);
}

MyArr& MyArr::operator=(MyArr&& originalArr) noexcept
{
	if (this != &originalArr)
	{
		this->arrSize = std::exchange(originalArr.arrSize, 0);
		this->ptr = std::move(originalArr.ptr);
	}
	return *this;
}

bool MyArr::operator==(const MyArr& originalArr) const noexcept
{
	const std::span <const int> leftArr{ this->ptr.get(), this->arrSize };
	const std::span <const int> rightArr{ originalArr.ptr.get(), originalArr.size() };

	return std::equal(std::begin(leftArr), std::end(leftArr), std::begin(rightArr), std::end(rightArr));
}

int& MyArr::operator[](size_t index)
{
	if (index >= this->arrSize)
	{
		throw std::out_of_range("OutRange");
	}
	return this->ptr[index];
}

const int& MyArr::operator[](size_t index) const
{
	if (index >= this->arrSize)
	{
		throw std::out_of_range("OutRange");
	}
	return this->ptr[index];
}

std::string MyArr::toString() const
{
	const std::span<const int> items = { this->ptr.get(), this->size() };
	std::ostringstream output;

	for (size_t i = 0; auto& item : items)
	{
		i++;
		output << item << (i < this->arrSize ? ", " : "");
	}
	return output.str();
}

MyArr::operator bool() const noexcept
{
	return size() != 0;
}

MyArr& MyArr::operator++()
{
	const std::span<int> items{ this->ptr.get(), this->arrSize };
	std::for_each(std::begin(items), std::end(items), [](auto& item) {++item; });
	return *this;
}

MyArr MyArr::operator++(int)
{
	MyArr temp(*this);
	++(*this);
	return temp;

}

MyArr& MyArr::operator+=(int value)
{
	const std::span<int> items{ this->ptr.get(), this->arrSize };
	std::for_each(std::begin(items), std::end(items), [value](auto& item) {item += value; });
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
