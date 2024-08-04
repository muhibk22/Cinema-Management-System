#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Movie {
private:
    string title;
    string genre;
    int duration;
    string releaseDate;
    int ageRating;
    static int count;
    
    static void overwriteFile(vector <Movie>& movies);
    bool saveToFile();

public:
    Movie();
    Movie(const string& title, const string& genre, int duration, const string& releaseDate, const int& ageRating, int count);

    // Getter and setter methods
    void setTitle(const string& title);
    string getTitle() const;
    void setGenre(const string& genre);
    string getGenre() const;
    void setDuration(int duration);
    int getDuration() const;
    void setReleaseDate(const string& releaseDate);
    string getReleaseDate() const;
    void setAgeRating(const int& ageRating);
    int getAgeRating() const;
    void setCount(int count);
    int getCount() const;

    // Methods
    void addMovie();
    static void viewMovie(const vector<Movie>& movies);
    static Movie searchMovie(const vector<Movie>& movies);
    static void deleteMovie(vector<Movie>& movies);
    static void readFile(vector<Movie>& movies);
    static Movie selectMovie();
    string getMovie();

    //stream operator
    friend ostream& operator<<(ostream& output, const Movie& m);
};
int Movie::count=0;
#endif
