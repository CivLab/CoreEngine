#pragma once
#include <iostream>

class IObject
{
public:
	IObject() {};
	virtual ~IObject() {};

	virtual void isStatutCoherent() = 0;

private:
	std::string m_ID;
	std::string m_name;
};

