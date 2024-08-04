#include "seat.h"

Seat::Seat() : rowNumber(0), columnNumber(0), isTaken(false) {}

Seat::Seat(int rowNumber, int columnNumber) : rowNumber(rowNumber), columnNumber(columnNumber) {}

void Seat::setRowNumber(const int row) {
    rowNumber=row;
}
void Seat::setisTaken(int taken){
    isTaken=taken;
}

bool Seat:: getisTaken() const{
    return isTaken;
}
int Seat::getRowNumber() const {
    return rowNumber;
}

void Seat::setColumnNumber( const int column) {
    columnNumber=column;
}

int Seat::getColumnNumber() const {
    return columnNumber;
}
