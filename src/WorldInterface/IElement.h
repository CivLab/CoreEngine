#pragma once

class IElement
{
public:
	IElement() {};
	virtual ~IElement() {};

	//display the shape on screen
	virtual void display() = 0;

	virtual double distance(IElement &) = 0;
	virtual bool collideWith(IElement &) = 0;
	virtual bool touch(IElement &) = 0;

	virtual void updatePosition() = 0;
	virtual void updateDirection() = 0;

	int getID() { return m_ID; }

protected:
	int m_ID;
};

