# Parking-Lot-Problem-Solver

This program does the following things:
- Parks a car in a free place
- It can park a long car and a short car (A long car takes 2 parking spaces, a short car takes 1 parking space)
- It can remove a car too
- It can find a car parked given its number plate

Has the following main functions:
	void createLot(int id, int rows,int columns);
	void removeLot(int id);
	void listLots();
	void lotContents(int id);
	void parkCar(int lotId, string location, string carType, int plateNumber);
	void findCar(int plateNumber);
	void removeCar(int plateNumber);
