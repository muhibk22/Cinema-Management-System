#include "hall.h"

Hall::Hall() : number(0), capacity(0), is3DCapable(false), seats(nullptr) {}

Hall::Hall(int number, int capacity, bool is3DCapable)
    : number(number), capacity(capacity), is3DCapable(is3DCapable) {
        seats = new Seat[capacity];
    }

Hall:: ~Hall(){
    delete[]seats;
}
void Hall::setNumber(int number)
{
    this->number = number;
}

int Hall::getNumber() const
{
    return number;
}

void Hall::setCapacity(int capacity)
{
    this->capacity = capacity;
}

int Hall::getCapacity() const
{
    return capacity;
}

void Hall::set3DCapable(bool is3DCapable)
{
    this->is3DCapable = is3DCapable;
}

bool Hall::get3DCapable() const
{
    return is3DCapable;
}

void Hall::setSeats(int cap) {
    seats=new Seat[cap];
}

void Hall::addHall()
{
    number = count + 1;
    cout << "Enter Hall capacity: ";
    cin >> capacity;
    cout << "Is the Hall 3D capable? (1 for yes, 0 for no): ";
    cin >> is3DCapable;
    count++;
    seats = new Seat[capacity];
    if(!saveToFile()){
        cout<<"Failed to save hall record."<<endl;
    }
}

void Hall::viewHalls(const vector<Hall> &halls)
{
    cout << "All Halls: " << endl;
    for (int i = 0; i < halls.size(); i++)
    {
        cout << "\n------------" << endl;
        cout << "\nHall Number: " << halls[i].number << "\nCapacity: " << halls[i].capacity;
        cout << "\n3D Screen Availability: " << (halls[i].is3DCapable ? "Yes" : "No") << endl;
    }
}

Hall Hall::selectHall()
{
    vector<Hall> halls;
    Hall::readFile(halls);
    Hall::viewHalls(halls);
    cout << "enter the hall number you want to pick: ";
    int num;
    cin >> num;
    for (int i = 0; i < halls.size(); i++)
    {
        if (num == halls[i].number)
        {
            return halls[i];
        }
    }
    cout << "Hall number " << num << " does not exist.";
    Hall empty;
    empty.setNumber(0);
    return empty;
}

void Hall::editHall(vector<Hall> &halls)
{
    int hallNumber;
    cout << "Enter the hall number you want to edit: ";
    cin >> hallNumber;

    for (int i = 0; i < halls.size(); i++)
    {
        if (hallNumber == halls[i].number)
        {
            cout << "Enter new capacity for Hall " << hallNumber << ": ";
            cin >> halls[i].capacity;
            cout << "Is the Hall 3D capable? (1 for yes, 0 for no): ";
            cin >> halls[i].is3DCapable;
            cout << "Hall details updated successfully!" << endl;
            return;
        }
    }
    cout << "Hall with number " << hallNumber << " not found." << endl;
}

bool Hall::saveToFile()
{
    ofstream fout;
    try
    {
        fout.open("halls.txt", ios::app);
        if (fout.fail())
        {
            throw runtime_error("Error opening halls.txt for writing");
        }
    }
    catch (runtime_error &e)
    {
        cout << e.what() << endl;
        return false;
    }
    fout << number << " " << capacity << " " << is3DCapable << endl;
    fout.close();
    return true;
}

void Hall::readFile(vector<Hall> &halls)
{
    ifstream fin;
    try
    {
        fin.open("halls.txt");
        if (fin.fail())
        {
            throw runtime_error("Error opening halls.txt for reading");
        }
    }
    catch (runtime_error &e)
    {
        cout << e.what() << endl;
        return;
    }
    Hall h;
    while (fin >> h.number >> h.capacity >> h.is3DCapable)
    {
        halls.push_back(h);
        count++;
    }
    fin.close();
}

string Hall:: getHall()
{
    string line="";
    line=to_string(number)+"\n"+to_string(capacity)+to_string(is3DCapable);
    return line;
}

void Hall:: setSeat(int seatno){
    const int seatsPerRow = 20;
    if(!seats[seatno].getisTaken()){
        seats[seatno].setisTaken(true);
        int columnNumber = (seatno% seatsPerRow)+1; 
        int rowNumber = (seatno / seatsPerRow)+1; 
        cout<<"Seat# "<<seatno<<" is located at Row: "<<rowNumber<<" Column: "<<columnNumber<<endl;
    }
    else {
        cout<<"seat# "<<seatno<<" is already taken. "<<endl;
    }
}


