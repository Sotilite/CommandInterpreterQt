#pragma once

#include <QDebug>
#include <QList>

class Coordinates {
public:
	Coordinates() : Coordinates(0, 0, 0) {}

	Coordinates(double x, double y, double z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}

	Coordinates(const Coordinates& coords) {
		this->x = coords.x;
		this->y = coords.y;
		this->z = coords.z;
	}

	const double get_x() const { 
		return x; 
	}

	const double get_y() const {
		return y; 
	}

	const double get_z() const { 
		return z; 
	}

	void setValue(int index, double value);

	double getValue(int index);

private:
	double x;
	double y;
	double z;
};
