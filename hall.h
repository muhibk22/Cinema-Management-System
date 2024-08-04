#ifndef HALL_H
#define HALL_H

#include <iostream>
#include <vector>
#include<fstream>
#include "seat.cpp"

using namespace std;

class Hall {
private:
    int number;
    int capacity;
    bool is3DCapable;
    static int count;
    Seat *seats;

    bool saveToFile();
public:
    Hall();
    Hall(int number, int capacity, bool is3DCapable);
    ~Hall();

    // Getter and setter methods
    void setNumber(int number);
    int getNumber() const;
    void setCapacity(int capacity);
    int getCapacity() const;
    void set3DCapable(bool is3DCapable);
    bool get3DCapable() const;
    void setSeats(int cap);

    // Methods
    void addHall();
    static Hall selectHall();
    static void viewHalls(const vector<Hall>& halls);
    static void editHall(vector<Hall>& halls);
    static void readFile(vector<Hall>&halls);
    string getHall();
    void setSeat(int seatno);

};
int Hall::count=0;
#endif
