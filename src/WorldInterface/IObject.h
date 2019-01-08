#pragma once
#include <iostream>
#include "IElement.h"

class IObject
{
public:
	IObject() {};
	virtual ~IObject() {};

	virtual IElement* getElement() = 0;

protected:
	std::string m_name;
};

