#include "ticket.cpp"

using namespace std;

void displayMainMenu() {
    cout << "\n--------------------CINEMA MANAGEMENY SYSTEM--------------------\n" << endl;
    cout << "1. Movie Management" << endl;
    cout << "2. Screening Management" << endl;
    cout << "3. Hall Management" << endl;
    cout << "4. Ticket Management" << endl;
    cout << "5. Customer Management" << endl;
    cout << "6. Exit" << endl;
    cout << "Enter your choice: ";
}

void movieManagementMenu(vector<Movie> &movies) {
    Movie m;
    cout << "\nMovie Management Menu\n" << endl;
    cout << "1. Add Movie" << endl;
    cout << "2. View Movies" << endl;
    cout << "3. Search Movie" << endl;
    cout<<"4. Delete Movie"<<endl;
    cout << "5. Back" << endl;
    cout << "Enter your choice: ";
    int choice;
    cin >> choice;
    cin.ignore();
    switch (choice) {
        case 1:
            m.addMovie();
            movies.push_back(m);
            break;
        case 2:
            Movie::viewMovie(movies);
            break;
        case 3:
            Movie::searchMovie(movies);
            break;
        case 4:
            Movie::deleteMovie(movies);    
            break;   
        case 5:
            displayMainMenu();
            break;
        default:
            cout << "Invalid choice!" << endl;
            break;
    }
}

void screeningManagementMenu(vector <Screening> &screenings) {
    Screening s;
    cout << "\nScreening Management Menu\n" << endl;
    cout << "1. Add Screening" << endl;
    cout << "2. View Screenings" << endl;
    cout << "3. Delete Screening" << endl;
    cout << "4. Back" << endl;
    cout << "\nEnter your choice: ";
    int choice;
    cin >> choice;
    switch (choice) {
        case 1:
            cin.ignore();
            s.addScreening();
            screenings.push_back(s);
            break;
        case 2:
            Screening::viewScreenings(screenings);
            break;
        case 3:
            Screening::deleteScreening(screenings);
            break;
        case 4:
            displayMainMenu();
            break;
        default:
            cout << "Invalid choice!" << endl;
            break;
    }
}

void hallManagementMenu(vector<Hall>& halls) {
    Hall h;
    cout << "\nHall Management Menu\n" << endl;
    cout << "1. Add Hall" << endl;
    cout << "2. View Halls" << endl;
    cout << "3. Edit Hall" << endl;
    cout << "4. Back" << endl;
    cout << "Enter your choice: ";
    int choice;
    cin >> choice;
    switch (choice) {
        case 1:
            cin.ignore();
            h.addHall();
            halls.push_back(h);
            break;
        case 2:
            Hall::viewHalls(halls);
            break;
        case 3:
            Hall::editHall(halls);
            break;
        case 4:
            displayMainMenu();
            break;
        default:
            cout << "Invalid choice!" << endl;
            break;
    }
}

void ticketManagementMenu(vector<Ticket> &tickets) {
    Ticket t;
    cout << "\nTicket Management Menu\n" << endl;
    cout <<"1. Sell a Ticket \n2. Refund Ticket"<<endl;
    int choice;
    cin >> choice;
    switch (choice) {
        case 1:
            t.sellTicket();
            tickets.push_back(t);
            break;
        case 2:
            Ticket::refundTicket(tickets);
            break;
        case 4:
            displayMainMenu();
            break;
        default:
            cout << "Invalid choice!" << endl;
            break;
    }
}



void customerManagementMenu() {
    Customer *c;
    int index=0;
    int size=100;
    cout << "\nCustomer Management Menu\n" << endl;
    cout << "1. Buy VIP Membership" << endl;
    cout << "2. View Customers" << endl;
    cout << "3. Search Customer Record" << endl;
    cout << "4. Back" << endl;
    cout << "Enter your choice: ";
    int choice;
    cin >> choice;
    cin.ignore();
    int opt;
    switch (choice) {
        case 1:
            c=new VIPCustomer;
            c->addCustomer();
            break;
        case 2:
            cout<<"1. View Regular Customer Record. \n2. View VIP Customer Record:\n";
            cin>>opt;
            if(opt==1){
                c=new RegularCustomer[size];
                RegularCustomer::readFile(c,index);
                RegularCustomer::viewCustomer(c,index);
            }
            else if(opt==2){
                c=new VIPCustomer[size];
                VIPCustomer::readFile(c,index);
                VIPCustomer::viewCustomer(c,index);
            }
            else{
                cout<<"Invalid option."<<endl;
            }
            break;
        case 3:
            cout<<"1. Search Regular Customer Record. \n2. Search VIP Customer Record:\n";
            cin>>opt;
            cin.ignore();
            if(opt==1){
                c=new RegularCustomer[size];
                RegularCustomer::readFile(c,index);
                RegularCustomer::searchCustomer(c,index);
            }
            else if(opt==2){
                c=new VIPCustomer[size];
                VIPCustomer::readFile(c,index);
                VIPCustomer::searchCustomer(c,index);
            }
            else{
                cout<<"Invalid option."<<endl;
            }
            break;
        case 4:
            displayMainMenu();
            break;
        default:
            cout << "Invalid choice!" << endl;
            break;
    }
}
void loadData(vector <Movie> &movies, vector <Screening> &screenings, vector <Hall> &halls, vector <Ticket> &tickets){
    Movie::readFile(movies);
    Screening::readFile(screenings);
    Hall::readFile(halls);
}
int main() {
    vector<Movie> movies;
    vector<Screening> screenings;
    vector<Hall> halls;
    vector<Ticket> tickets;
    loadData(movies, screenings, halls, tickets);
    while (true) {
        displayMainMenu();
        int choice;
        cin >> choice;
        switch (choice) {
            case 1:
                movieManagementMenu(movies);
                break;
            case 2:
                screeningManagementMenu(screenings);
                break;
            case 3:
                hallManagementMenu(halls);
                break;
            case 4:
                ticketManagementMenu(tickets);
                break;
            case 5:
                customerManagementMenu();
                break;
            case 6:
                cout << "Exiting program" << endl;
                return 0;
            default:
                cout << "Invalid choice! Please enter a number from 1 to 6." << endl;
        }
    }
    return 0;
}
