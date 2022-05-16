//Muhammad Ali Waris 22001037
#pragma once
#include "Car.h"

Car::Car() {
}

Car::Car(int lotID1, string location1, string carType1, int plateNumber1) {
	this->lotID = lotID1;
	this->location = location1;
	this->carType = carType1;
	this->plateNumber = plateNumber1;

}