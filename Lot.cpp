//Muhammad Ali Waris 22001037

#pragma once
#include "LotHeader.h"
using namespace std;



	// Array of Lots
	//In the array of Lots, there is an Array of Lot Parkings

	Lot::Lot() {
	column_limit = 12;
	counter = 1;
	row_limit = 12;
	input_num = 0;
	temprows = 0;
	tempcolumns = 0;
	rows = 0;
	columns = 0;
	lotID = 0;
	type_a_cars = 0;
	type_b_cars = 0;
	lotcount = 0;


	}

	Lot::~Lot() {
			
		

	}

	Lot::Lot(int id, int r, int c) {
		column_limit = 12;
		counter = 1;
		lotcount++;
		row_limit = 12;
		temprows = 0;
		tempcolumns = 0;
		this->setLotID(id);
		this->setrows(r);
		this->setcolumns(c);
		
		this->type_a_cars = 0;
		this->type_b_cars = 0;


	}

	int Lot::get_type_a_cars() {
		return this->type_a_cars;
	}

	int Lot::get_type_b_cars() {
		return this->type_b_cars;
	}

	void Lot::setLotID(int id) {
		lotID = id;
	}

	int Lot::getLotID() {
		return lotID;
	}

	void Lot::setrows(int r) {
		if (r > row_limit) {
			cout << r << "TOO LARGE";
			cout << "ERROR ! KEEP ROWS AND COLUMNS SHOULD BE < 12" << endl;
			rows = 0;
		}
		else {
			rows = r;
		}
		
	}

	int Lot::getrows() {
		return rows;
	}

	int Lot::getcolumns() {
		return columns;
	}

	void Lot::setcolumns(int c) {
		if (c > row_limit) {
			cout << c << "TOO LARGE";
			cout << "ERROR ! KEEP ROWS AND COLUMNS SHOULD BE < 12" << endl;
			columns = 0;
		}
		else {
			columns = c;
		}
		
	}


