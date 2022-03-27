#pragma once
#include <map>
#include <string>

class Property
{
public:
	Property();
	~Property();

	Property(size_t InOffset, size_t InDimension) : Offset(InOffset), Dimension(InDimension)
	{

	}

	template<typename T>
	T* Get(uint8_t* Instance)
	{

		return reinterpret_cast<T*>(Instance + Offset);
	}

	size_t Offset;
	size_t Dimension;
};

class Reflection
{
public:
	Reflection();
	~Reflection();

	std::map<std::string, Property> Properties;

private:

};