//Muhammad Ali Waris 22001037

#pragma once
#include "ParkingSystem.h"
#include <string> 
using namespace std;

ParkingSystem::ParkingSystem() {
	areaSize = 2;
	carSize = 2;
	lotcounter = 0;
	carCounter = 0;
	area = new Lot[areaSize];
	cars = new Car[carSize];
}
ParkingSystem::~ParkingSystem() {

	
	for (int i = 0; i < lotcounter; i++) {
		int rows = area[i].rows;
		int cols = area[i].columns;


		for (int x = 0; x < rows; x++) {
			delete[] area[i].lotContents[x];
		}
		delete[] area[i].lotContents;
	}
	delete[] area;

	delete[] cars;


}

void ParkingSystem::createLot(int id, int rows, int columns) {

	if ((rows > 12 || rows < 0) || (columns > 12 || columns < 0)) {
		cout << "Cannot create the parking lot with ID "<< id << " dimensions increase acceptable bounds" << endl;
	}
	else if (checkSimilarId(id)) {
		cout << "Cannot create the parking lot " << id << " a lot with this ID already exists" << endl;
	}
	else {
		Lot newLot(id, rows, columns);
		newLot.lotContents = new int* [rows];
		for (int i = 0; i < rows; i++) {
			newLot.lotContents[i] = new int[columns];
		}


		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				newLot.lotContents[i][j] = 0;
			}
		}

		if (this->areaSize == this->lotcounter) {
			increaseLotStorageSize();
		}

		addLotToCollection(newLot);
		lotcounter++;
		cout << "PARKING LOT CREATED WITH ID :" << id << " Dimensions " << rows  << " x " << columns  << endl;
	}
	

}

void ParkingSystem::increaseCarStorageSize() {
	if (this->carSize == this->carCounter) {
		this->carSize++;
		Car* temp = new Car[carSize];
		for (int i = 0; i < carSize-1; i++) {
			if (i < carSize-1) {
				temp[i] = this->cars[i];
			}
		};
		cars = new Car[carSize];
		for (int i = 0; i < carSize; i++) {
			cars[i] = temp[i];
		}

		delete[] temp;

	}


}

void ParkingSystem::increaseLotStorageSize() {
	if (this->areaSize == this->lotcounter) {
		this->areaSize++;
		Lot* temp = new Lot[areaSize];
		for (int i = 0; i < areaSize - 1; i++) {
			if (i < areaSize - 1) {
				temp[i] = this->area[i];
			}
		}
		area = new Lot[areaSize];
		for (int i = 0; i < areaSize; i++) {
			area[i] = temp[i];
		}
		delete[] temp;
	}

}

 

void ParkingSystem::listLots() {
	if (lotcounter != 0) {
		cout << "" << endl;
		cout << "Lots in the System Are : " << endl;
		for (int i = 0; i < lotcounter; i++) {
	
			cout << "Lot with ID: " << area[i].getLotID() << " Size : " << area[i].getrows() << "x" << area[i].getcolumns() << " Free Spaces: " << countFreeSpaces(area[i].lotID) << endl;
		}
	}
	else if (lotcounter == 0) {
		cout << "No Lots Available to Show Please Add Some " << endl;
	}

}

bool ParkingSystem::checkPlateNumber(int plateNumber2) {
	int found = -1;
	for (int i = 0; i < carCounter; i++) {
		if (cars[i].plateNumber == plateNumber2) {
			found = 1;
			return false;
		}
	}
	if (found == -1) {
		return true;
	}
}

void ParkingSystem::parkCar(int lotId, string location, string carType, int plateNumber) {
	int index = -1;
	for (int i = 0; i < lotcounter; i++) {
		if (area[i].lotID == lotId) {
			index = i;
		}
	}

	if (index == -1) {
		cout << "Lot " << lotId  << " Not Found, Please Write Correct ID" << endl;
	}
	else if( index != -1) {
		if (!checkPlateNumber(plateNumber)) {
			cout << "Car with Plate " << plateNumber << " Already Exists in System " << endl;
		}
		if (checkParkingSpace(lotId,location,carType, plateNumber) && checkPlateNumber(plateNumber)){
			Car newCar(lotId, location, carType, plateNumber);
			int rows; 
			int columns;
			rows = getRowsFromLocation(location);
			columns = getColumnsFromLocation(location)-1 ;

			if (carType == "a") {
				area[index].lotContents[rows][columns] = 1;
				cout << "LIGHT DUTY CAR PARKED WITH PLATE " << plateNumber << " AT " << location << " IN LOT " << lotId << endl;
			};
			if (carType == "b") {
				area[index].lotContents[rows][columns] = 2;
				area[index].lotContents[rows - 1][columns] = 2;
				cout << "HEAVY DUTY CAR PARKED WITH PLATE " << plateNumber << " AT " << location << " IN LOT " << lotId << endl;
			}; 
				increaseCarStorageSize();
				addCarToCollection(newCar);
			
			}

	}

	
}

int ParkingSystem::convert(string s) {
	// Initialize a variable 
	int num = 0;
	int n = s.length();

	// Iterate till length of the string 
	for (int i = 0; i < n; i++)

		// Subtract 48 from the current digit 
		num = num * 10 + (int(s[i]) - 48);

	// Print the answer 
	return num;
}


int ParkingSystem::getColumnsFromLocation(string location) {

	int locationSize = location.size();
	string col;
	bool rightAplhabet;


	if (locationSize == 3) {
		col = location.substr(1,2);
	}
	else if (locationSize == 2) {
		col = location.substr(1, 1);
	}
	return convert(col);
	

}



int ParkingSystem::getRowsFromLocation(string location) {

		string row ="";
		int r;

		row = location.substr(0, 1);
		return rowPositionNumericalValue(row);

}

bool ParkingSystem::checkParkingSpace(int lotid, string location,string carType, int plateNumber) {
	int index = -1 ;
	int rows = getRowsFromLocation(location);
	int col = getColumnsFromLocation(location) -1;
	for (int i = 0; i < lotcounter; i++) {
		if (area[i].lotID == lotid) {
			index = i;
		
		}
	}
	if (index == -1) {
		cout << "Lot " << lotid  << " Not Found" << endl;
		return false;
	}
	else {
		if (rows == 0 && (carType == "b")) {
			cout << "Cannot Place HEAVY DUTY TYPE plateNumber " << plateNumber << " at " << location << " There is no space" << endl;
			return false;
		} //0 - Empty ... 1 - Type a  ... 2 - Type b
		else if (carType == "a") {
			if (area[index].lotContents[rows][col] == 0) {
				return true;
				//area[index].lotContents[rows][col] = 1;
			}
			else if (area[index].lotContents[rows][col] != 0) {
				cout << location << " Is Not Free for Light Duty Car " << plateNumber << endl;
				return false;
			}
		}
		else if (carType == "b") {
			if ((area[index].lotContents[rows][col] == 0) && (area[index].lotContents[rows-1][col] == 0)) {
				return true;
				//area[index].lotContents[rows][col] = 1;
			}
			else  {
				cout << location << " Is Not Free for Heavy Duty Car " << endl;
				return false;
			}
		}


	}
}

void ParkingSystem::findCar(int plateNumber2) {
	int index = -1;
	string type;
	for (int i = 0; i < carCounter; i++) {
		if (cars[i].plateNumber == plateNumber2) {
			index = i;
		}
	}
	if (index != -1) {
		if (cars[index].carType == "a") {
			type = " LIGHT DUTY";
		}
		if (cars[index].carType == "b") {
			type = " HEAVY DUTY";
		}
		cout << "Car " << plateNumber2 << " is in Lot " << cars[index].lotID << " at location " << cars[index].location << " and its Type is  " << type /*cars[index].carType*/ << endl;
	}
	else  {
		cout << "Car Plate Number " << plateNumber2 << " Not Found In System " << endl;
	}
}

void ParkingSystem::addCarToCollection(Car carObject) {
	cars[carCounter] = carObject;
	carCounter++;
}

void ParkingSystem::removeAllCarsFromLot(int id) {
	int index = -1;
	for (int i = 0; i < lotcounter; i++) {
		if (area[i].lotID == id) {
			index = i;
		}
	}



}

int ParkingSystem::rowPositionNumericalValue(string r) {
		if (r.compare("A") == 0) { return 0; }
	else if (r.compare("B") == 0) { return 1; }
	else if (r.compare("C") == 0) { return 2; }
	else if (r.compare("D") == 0) { return 3; }
	else if (r.compare("E") == 0) { return 4; }
	else if (r.compare("F") == 0) { return 5; }
	else if (r.compare("G") == 0) { return 6; }
	else if (r.compare("H") == 0) { return 7; }
	else if (r.compare("I") == 0) { return 8; }
	else if (r.compare("J") == 0) { return 9; }
	else if (r.compare("K") == 0) { return 10; }
	else if (r.compare("L") == 0) { return 11; }
}

void ParkingSystem::removeLot(int id) {
	int found = 0;
	int indexToRemove = -1;
	for (int i = 0; i < lotcounter; i++) {
		if (area[i].lotID == id) {
			found = 1;
			indexToRemove = i;
		}

	}
	if (found == 1 && indexToRemove != -1) {
		
		int lastLotLoc = lotcounter - 1;
		int traverseMore = lastLotLoc - indexToRemove;
		int counter = indexToRemove;
		int numOfCarsInLot = 0;
		for (int i = 0; i < carCounter; i++) {
			if (cars[i].lotID == id) {
			
				numOfCarsInLot++;
				//removeCar(cars[i].plateNumber);
			
				//cout << cars[i].plateNumber << ", ";
			}

		}
		int rows = area[counter].rows;
			for (int i = 0; i < numOfCarsInLot; i++) {
				if (cars[i].lotID == id) {
					removeCarCalled++;
					removeCar(cars[i].plateNumber);
				}
			}		

		for (int i = 0; i < traverseMore; i++) {
				area[counter] = area[counter + 1];
				counter++;
		}

		
		
		lotcounter--;
		cout  << "... ... ... ALL CARS REMOVED FROM LOT " << id << "  EVEN THOUGH IT DOES NOT OUTPUT IT... ...  " << endl;
		cout << "Lot " << id << " has been removed successfully " << endl;
	}
	if (found == 0) {
		cout << "Lot with ID: " << id << " Not found! " << endl;
	}
}

void ParkingSystem::removeCar(int plateNumber) {
	int found = 0;
	int indexToRemove = -1;
	for (int i = 0; i < carCounter; i++) {
		if (cars[i].plateNumber == plateNumber) {
			found = 1;
			indexToRemove = i;
		}

	}

	if (found == 1) {
		int lotidCar = cars[indexToRemove].lotID;
		string lotidLoc = cars[indexToRemove].location;
		int lastLotLoc = carCounter - 1;
		int traverseMore = lastLotLoc - indexToRemove;
		int counter = indexToRemove;

		for (int i = 0; i < traverseMore; i++) {
			cars[counter] = cars[counter + 1];
			counter++;
		}
		carCounter--;
		cout << "Car with " << plateNumber << " has been removed successfully at " << lotidLoc <<" from Lot " << lotidCar << endl;
	}
	if (found == 0) {
		cout << "Car with ID: " << plateNumber << " Not found! " << endl;
	}


}

bool ParkingSystem::checkSimilarId(int id) {
	int found = 0;
	for (int i = 0; i < lotcounter; i++) {
		if (area[i].lotID == id) {
			found = 1;
			return true;
		}

	}
	if (found == 0) {
		return false;
	}
}

void ParkingSystem::addLotToCollection(Lot lotObject) {
	area[lotcounter] = lotObject;
	
}

int ParkingSystem::findLotRows(int id) {
	int found = 0;
	for (int i = 0; i < lotcounter; i++) {
		if (area[i].getLotID() == id) {
			found = 1;
			return area[i].getrows();
			
		}
	}
	if (found == 0) {
		return -1;
	}
}

int ParkingSystem::findLotColumns(int id) {
	int found = 0;
	for (int i = 0; i < lotcounter; i++) {
		if (area[i].getLotID() == id) {
			found = 1;
			return area[i].getcolumns();
		}
	}
	if (found == 0) {
		return -1;
	}
}

void ParkingSystem::lotContents(int id) {
	//Output array

	if (findLotRows(id) == -1 || findLotColumns(id) == -1) {
		cout << "Lot with ID " << id  << " Does Not EXIST" << endl;
	}

	else {
		int colcounter;
		int index;

		for (int i = 0; i < lotcounter; i++) {

			if (area[i].lotID == id) {
				int lot_id = area[i].lotID;
				index = i;

				cout << "LOT with ID : " << id << " Size " << area[index].rows << "x" << area[index].columns << " Empty Slots " << countFreeSpaces(id) << " ";
				cout << " Parked Cars : ";
				printParkedCarsInLot(id);
				cout << "" << endl;

				//make columns
				cout << " " << " " << " ";
				for (int c = 0; c < (findLotColumns(lot_id)); c++) {
					cout << c + 1 << " " << " ";
				}

			

				cout << ""  << endl;
				for (int i2 = 0; i2 < findLotRows(lot_id); i2++) {
					colcounter = findLotColumns(lot_id);
					cout << alpha_arra[i2];
					//cout << i + 1 << " --> " << " ";
					for (int j = 0; j < findLotColumns(lot_id); j++) {
						
						if (j == 10 || j == 11) {
							cout << " ";
						}

						if (colcounter != 1) {
							cout << " " << " ";
							if (area[index].lotContents[i2][j] == 0) {
								cout << "+";
							}
							else {
								if (area[index].lotContents[i2][j] == 1) {
									cout << "a";
								}
								else if (area[index].lotContents[i2][j] == 2) {
									cout << "b";
								}
							}
							colcounter--;

						}
						else {
							cout << " " << " "; 
							if (area[index].lotContents[i2][j] == 0) {
								cout << "+";
							}
							else {
								if (area[index].lotContents[i2][j] == 0) {
									cout << "+";
								}
								else {
									if (area[index].lotContents[i2][j] == 1) {
										cout << "a";
									}
									else if (area[index].lotContents[i2][j] == 2) {
										cout << "b";
									}
								}
							}
							cout << " " << endl;
						}

					}
				}
				cout << "" << endl;

			}
	
		}
	}

}

int ParkingSystem::countFreeSpaces(int id) {
	int found = -1;
	int index;
	int rows;
	int cols;
	int freeSpaceCounter;
	for (int i = 0; i < lotcounter; i++) {
		if (area[i].lotID == id) {
			found = 1;
			index = i;
		}
	}

	if (found == -1) {
		cout << id << "Invalid Lot Id" << endl;
		return -1;
	}
	else {
		freeSpaceCounter = 0;
		rows = findLotRows(id);
		cols = findLotColumns(id);
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				if (area[index].lotContents[i][j] == 0) {
					freeSpaceCounter++;
				}
			
			}
		}
		return freeSpaceCounter;
	}
}

void ParkingSystem::printParkedCarsInLot(int id) {
	int counter = 0;
	for (int i = 0; i < carCounter; i++) {
		if (cars[i].lotID == id) {
			cout << cars[i].plateNumber << ", ";
			counter++;
		}
	}

	if (counter == 0) {
		cout << " No Cars Yet ";
	}
}

void ParkingSystem::showAllCars() {
	for (int i = 0; i < carCounter; i++) {
		cout << cars[i].plateNumber << ", ";
	}
	cout << "" << endl;
}

void ParkingSystem::showAllCarsinLot(int id) {
	for (int i = 0; i < carCounter; i++) {
		if (cars[i].lotID == id) {
			cout << cars[i].plateNumber << ", ";
		}
	
	}
	cout << "" << endl;
}