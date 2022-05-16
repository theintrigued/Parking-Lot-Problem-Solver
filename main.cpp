#pragma once
#include <iostream>
using namespace std;
#include "ParkingSystem.h"









int main() {
		


	int* arr2 = new int[5]; 

	for (int i = 0; i < 5; i++) {
		arr2[i] = i + 6;
	}

	for (int i = 0; i < 5; i++) {
		cout << arr2[i]<<endl;
	}

	int* ptr = arr2 ;
	cout << " ptr " << *(ptr + 1);
	cout << " ptr "  << ptr - arr2;











	return 0;
}



