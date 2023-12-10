#pragma once
#include "vectors.h"
#include <iostream>;
#include <cmath>


VC::VC() = default;
VC::VC(const vector<double> coord) : coord(coord) {
	try {
		if (coord.size() < 2 || coord.size() > 3) {
			throw std::runtime_error("coords must be 2 or 3");
		}
		else {
			if (coord.size() == 2) {
				x = coord[0];
				y = coord[1];
			}
			else if (coord.size() == 3) {
				x = coord[0];
				y = coord[1];
				z = coord[2];
			}
		}
	}
	catch (const std::runtime_error& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

double VC::getCoordX() const { return x; }
double VC::getCoordY() const { return y; }
double VC::getCoordZ() const { 
	if (coord.size() != 3) {
		throw std::runtime_error("undefine Z");
		return -1.0;
	}
}

VC VC::operator+(const VC& other) {
	try {
		if (coord.size() != other.coord.size()) {
			throw std::runtime_error("count cords not equal");
		}
		VC temp;
		for (int i = 0; i < coord.size(); ++i) {
			temp.coord.push_back(coord.at(i) + other.coord.at(i));
		}
		return temp;
	}
	catch (const std::runtime_error& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

VC VC::operator-(const VC& other) {
	try {
		if (coord.size() != other.coord.size()) {
			throw std::runtime_error("count cords not equal");
		}
		VC temp;
		for (int i = 0; i < coord.size(); ++i) {
			temp.coord.push_back(coord.at(i) - other.coord.at(i));
		}
		return temp;
	}
	catch (const std::runtime_error& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
}
std::ostream& operator<<(std::ostream& os, VC& vec) {
	if (vec.coord.size() == 2 || vec.coord.size() == 3) {
		for (int i = 0; i < vec.coord.size(); ++i) {
			os << vec.coord.at(i) << " ";
		}
		return os;
	}
	else {
		throw std::runtime_error("error");
	}
}


double VC::operator*(const VC& other) {
	try {
		double result = 0;
		for (int i = 0; i < coord.size(); ++i) {
			result += coord.at(i) * other.coord.at(i);
		}
		return result;

	}
	catch (const std::runtime_error& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
}
// длина вектора 
double VC::length() {
	try {
		if (coord.size() == 2) {
			return sqrt(pow(coord.at(0), 2) + pow(coord.at(1), 2));
		}
		else if (coord.size() == 3) {
			return sqrt(pow(coord.at(0), 2) + pow(coord.at(1), 2) + pow(coord.at(2), 2));
		}
	}
	catch (const std::runtime_error& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

void VC::printVC() const {
	try {
		for (int i = 0; i < coord.size(); ++i) {
			std::cout << coord.at(i) << " ";
		}
	}
	catch (const std::runtime_error& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
}
// угол между векторами 
double angle(VC v1, VC v2) {
	try {
		return (v1 * v2) / (v1.length() * v2.length());
	}
	catch (const std::runtime_error& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
}



