#pragma once

#ifndef VECTORS_H
#define VECTORS_H
#include <vector>
#include <iostream>

using std::vector;

class VC {
private:
	double x;
	double y;
	double z;
public:
	vector<double> coord;
	VC();
	VC(const vector<double>);
	VC operator+(const VC& other);
	VC operator-(const VC& other);
	double operator*(const VC& other);
	double length();
	void printVC() const;
	double getCoordX() const;
	double getCoordY() const;
	double getCoordZ() const;
};

std::ostream& operator<<(std::ostream& os, VC& vec);

double angle(VC, VC);

#endif