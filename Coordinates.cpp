#include "Coordinates.h"

void Coordinates::setValue(int index, double value) {
	if (index == 0) {
		x = value;
	}
	else if (index == 1) {
		y = value;
	}
	else if (index == 2) {
		z = value;
	}
	else {
		qDebug() << "The index has gone abroad";
	}
}

double Coordinates::getValue(int index) {
	if (index == 0) {
		return x;
	}
	else if (index == 1) {
		return y;
	}
	else if (index == 2) {
		return z;
	}
	return qQNaN();
}
