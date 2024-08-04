#ifndef SCREENING_H
#define SCREENING_H

#include<iomanip>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "movie.cpp"
#include "hall.cpp"

using namespace std;

class Screening {
private:
    int id;
    string startTime;
    string endTime;
    string date;
    Hall hallNumber;
    bool is3d;
    Movie movies;
    static int count;

    bool saveToFile();
    static bool overwriteFile(vector<Screening> s);
public:
    Screening();
    Screening(const int& id, const string& startTime, const string& endTime, const string& date, Hall hallNumber, const bool& is3d, const Movie& movies);

    // Getter and setter methods
    void setId(const int& id);
    void setStartTime(const string& startTime);
    void setEndTime(const string& endTime);
    void setDate(const string& date);
    void setHallNumber(Hall hallNumber);
    void setIs3d(const bool& is3d);
    void setMovie(const Movie& movies);
    int getId() const;
    string getStartTime() const;
    string getEndTime() const;
    string getDate() const;
    Hall getHallNumber() const;
    bool getIs3d() const;
    Movie getMovie() const;

    // Methods
    void addScreening();
    static Screening selectScreening();
    static void viewScreenings(const vector<Screening>& screenings);
    static void deleteScreening(vector<Screening>& screenings);
    static void readFile(vector<Screening>& screenings);
    void allotHall(Hall &h);
    string getScreening();

    //stream operator overloading
    friend ostream &operator<<(ostream& output, const Screening& s);
};
int Screening::count=0;
#endif 