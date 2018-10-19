#pragma once
#include <iostream>

class IObject
{
public:
	IObject() {};
	virtual ~IObject() {};

private:
	std::string m_name;
};

