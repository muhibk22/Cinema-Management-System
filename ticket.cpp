#include "Ticket.h"

Ticket::Ticket() : ID(count+1), price(800.0), customer {nullptr} {}

Ticket::Ticket(int ID, float price, const Screening& screening, const Hall& seat, const Customer& customer)
    : ID(ID), price(price), screening(screening), seat(seat) {}

Ticket::~Ticket(){
    delete customer;
}
void Ticket::setID(int ID) {
    this->ID = ID;
}

int Ticket::getID() const {
    return ID;
}

void Ticket::setPrice(float price) {
    this->price = price;
}

float Ticket::getPrice() const {
    return price;
}

void Ticket::setScreening(const Screening& screening) {
    this->screening = screening;
}

Screening Ticket::getScreening() const {
    return screening;
}

void Ticket::setSeat(const Hall& seat) {
    this->seat = seat;
}

Hall Ticket::getSeat() const {
    return seat;
}


void Ticket::sellTicket() {
    ID=count+1;
    screening=Screening::selectScreening();
    if (screening.getId()==0){
        sellTicket();
    }
    int option;
    do { 
        cout<<"\n1.Regular Customer \n2.VIP Customer \n";
        cin>>option;
        cin.ignore();
        if (option==1){
            customer = new RegularCustomer;
            customer->addCustomer();
        }
        else if(option==2){
            customer = new VIPCustomer;
            customer->selectCustomer();
            price-=price*customer->calculateDiscount(); //calculating the discounted price for the customer
        }
        else {
            cout<<"Invalid option";
        } 
    }while(option!=1 && option!=2);

    int seatno;
    cout<<"\nEnter seat no: ";
    cin>>seatno;
    screening.allotHall(seat); //alloting the same values to hall as in screening
    seat.setSeat(seatno); //setting row and col number
    cout<<"\nTicket price: "<<price<<endl;
    cout<<"Confirm purchase? \n1.Yes \n2.No\n";
    int opt;
    do{

    cin>>opt;
    switch (opt)
    {
    case 1:
    cout << "Selling ticket. Seat: " << seatno << endl;
        saveToFile();
        count++;
        break;
    case 2:    
        cout<<"Transaction Discarded."<<endl;
        break;
    default:
        cout<<"Invalid option! ";
        break;
    }
    }while (opt!=1 && opt!=2);
}

void Ticket:: refundTicket(vector<Ticket>& tickets){
    cout<<"Enter the id of the Ticket you want to refund: ";
    int refundId,opt;
    cin>>refundId;
    bool found=false;
    for (int i=0; i<tickets.size(); i++){
        if (refundId==tickets[i].ID){
            cout<<"The ticket cost RS: "<<tickets[i].price<<endl;
            cout<<"Press 1 to confirm refund. "<<endl;;
            found=true;
            cin>>opt;
            if (opt==1){
                tickets.erase(tickets.begin()+i);
                cout<<"Ticket Refunded. "<<endl;
                return;
            }
            else{
                cout<<"Refund Cancelled. Enjoy your show!"<<endl;
                return;
            }
        }
    }
    if (!found){
        cout<<"No ticket found with ID: "<<refundId<<endl;
    }
}
void Ticket::saveToFile() {
    ofstream fout;
    try{
    fout.open("tickets.txt",ios::app);
    if (fout.fail()){
        throw runtime_error("Error opening screenings.txt for writing");
    }
    }
    catch(runtime_error &e){
        cout<<e.what()<<endl;
        return;
    }
    fout<<ID<<endl;
    fout<<price<<endl;
    fout<<getScreening()<<endl;
    fout.close();
    cout << "Transaction Saved!" << endl;
}
