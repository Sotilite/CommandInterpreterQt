#include "Coordinates.h"

Coordinates::Coordinates(QObject *parent)
	: QObject(parent)
{
	x = y = z = 0;
}

Coordinates::~Coordinates()
{}
