//Muhammad Ali Waris 22001037

#pragma once
#include <iostream>
using namespace std;




class Lot {

public:

	int rows;
	int columns;
	int column_limit;
	int counter;
	int row_limit;
	int input_num;
	int** lotContents;
	string alpha_arra[12] = { "A","B","C","D","E","F","G","H","I","J","K","L" };
	int temprows;
	int tempcolumns;
	int lotID;
	int type_a_cars;
	int type_b_cars;
	int lotcount;

public:
	Lot();
	~Lot();
	Lot(int id, int r, int c);
	void setLotID(int id);
	int getLotID();
	void setrows(int r);
	void setcolumns(int c);
	int getrows();
	int getcolumns();
	int get_type_a_cars();
	int get_type_b_cars();

};