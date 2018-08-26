#include "element.h"

//Shape related functions
void Element::updatePosition(std::vector<Point*> speeds)
{
	for (Point* pSpeed : speeds)
	{
		update(pSpeed);
	}
}
