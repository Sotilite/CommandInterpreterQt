#pragma once

#include <QObject>

class Coordinates : public QObject
{
	Q_OBJECT

public:
	Coordinates(QObject* parent);
	~Coordinates();

private:
	double x;
	double y;
	double z;

public:
	Coordinates() : Coordinates(0, 0, 0) {}

	Coordinates(double x, double y, double z) 
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	Coordinates(const Coordinates& coords)
	{
		x = coords.x;
		y = coords.y;
		z = coords.z;
	}

	Coordinates &operator=(const Coordinates)
	{
		return *this;
	}

	double get_x() { return x; }
	double get_y() { return y; }
	double get_z() { return z; }

	void setValue(int index, double value) {
		if (index == 0) x = value;
		else if (index == 1) y = value;
		else if (index == 2) z = value;
		else qDebug("The index has gone abroad");
	}
};
