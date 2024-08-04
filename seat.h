#ifndef SEAT_H 
#define SEAT_H 

#include <iostream>

using namespace std;

class Seat {
private:
    int rowNumber;
    int columnNumber;
    bool isTaken;

public:
    Seat();
    Seat(int rowNumber, int columnNumber);

    // Getter and setter methods
    void setisTaken(int taken);
    bool getisTaken() const;
    void setRowNumber(const int row);
    int getRowNumber() const;
    void setColumnNumber(const int column);
    int getColumnNumber() const;
    

};

#endif 
