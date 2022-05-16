//Muhammad Ali Waris 22001037

#pragma once
#include <iostream>
#include "LotHeader.h"
#include "Car.h"
#include <string> 
using namespace std;


class ParkingSystem {

public:
	int areaSize;
	int carSize;
	int lotcounter;
	int carCounter;
	Lot* area;
	Car* cars;
	string alpha_arra[12] = { "A","B","C","D","E","F","G","H","I","J","K","L" };
	int removeCarCalled = 0;


public:
	ParkingSystem();
	~ParkingSystem();
	void createLot(int id, int rows,int columns);
	void removeLot(int id);
	void listLots();
	void lotContents(int id);
	void parkCar(int lotId, string location, string carType, int plateNumber);
	void findCar(int plateNumber);
	void removeCar(int plateNumber);

	void addLotToCollection(Lot lotObject);
	int findLotRows(int id);
	int findLotColumns(int id);
	bool checkSimilarId(int id);
	int rowPositionNumericalValue(string r);
	int convert(string s);
	void increaseCarStorageSize();
	void addCarToCollection(Car carObject);
	bool checkParkingSpace(int lotid, string location, string carType, int plateNumber);
	int getColumnsFromLocation(string location);
	int getRowsFromLocation(string location);
	int countFreeSpaces(int lotid);
	void printParkedCarsInLot(int lotid);
	int* ParkedCarsInLot(int lotid); // to do
	bool checkPlateNumber(int plateNumber);
	void increaseLotStorageSize();
	void showAllCars();
	void showAllCarsinLot(int id);
	void removeAllCarsFromLot(int id);






};