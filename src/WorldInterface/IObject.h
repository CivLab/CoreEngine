#pragma once
#include <iostream>

class IObject
{
public:
	IObject() {};
	virtual ~IObject() {};

protected:
	std::string m_name;
};

