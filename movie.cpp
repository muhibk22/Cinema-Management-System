#include "movie.h"

Movie::Movie() : duration(0) {
}

Movie::Movie(const string& title, const string& genre, int duration, const string& releaseDate, const int& ageRating, int count)
    : title(title), genre(genre), duration(duration), releaseDate(releaseDate), ageRating(ageRating) {}

void Movie::setTitle(const string& title) {
    this->title = title;
}

string Movie::getTitle() const {
    return title;
}

void Movie::setGenre(const string& genre) {
    this->genre = genre;
}

string Movie::getGenre() const {
    return genre;
}

void Movie::setDuration(int duration) {
    this->duration = duration;
}

int Movie::getDuration() const {
    return duration;
}

void Movie::setReleaseDate(const string& releaseDate) {
    this->releaseDate = releaseDate;
}

string Movie::getReleaseDate() const {
    return releaseDate;
}

void Movie::setAgeRating(const int& ageRating) {
    this->ageRating = ageRating;
}

int Movie::getAgeRating() const {
    return ageRating;
}

void Movie::setCount(int count) {
    this->count = count;
}

int Movie::getCount() const {
    return count;
}

void Movie::addMovie() {
    cout<<"Enter the movie title: \n";
    getline(cin,title);
    cout<<"Enter the movie genre: \n";
    getline(cin,genre);
    cout<<"Enter its duration in minutes: \n";
    cin>>duration;
    cin.get();
    cout<<"Enter the release date: \n";
    getline(cin,releaseDate);
    cout<<"Enter its age rating: \n";
    cin>>ageRating;
    cin.get();
    count++;
    if (saveToFile()){
        cout<<"Movie added to record successfully. "<<endl;
    }
}


void Movie::viewMovie(const vector<Movie>& movies) {
    if (movies.empty()) {
        cout << "No movies to display." << std::endl;
        return;
    }

    cout << "List of Movies:" << endl;
    cout<<setw(20)<<left<<"Title"<<setw(20)<<left<<"Genre"<<setw(20)<<left<<"Duration"<<setw(20)<<left<<"Release Date"<<setw(20)<<left<<"Age Rating"<<endl;
    cout<<"----------------------------------------------------------------------------------------------------"<<endl;
    for (int i = 0; i < movies.size(); i++) {
        cout << movies[i]<<endl; 
    }
}

Movie Movie::searchMovie(const vector<Movie>& movies) {
    bool found = false;
    cout<<"Enter the name of movie you want to search: ";
    string searchTerm;
    getline(cin,searchTerm);
    cout << "Search Results:" << endl;
    cout<<setw(20)<<left<<"Title"<<setw(20)<<left<<"Genre"<<setw(20)<<left<<"Duration"<<setw(20)<<left<<"Release Date"<<setw(20)<<left<<"Age Rating"<<endl;
    cout<<"----------------------------------------------------------------------------------------------------"<<endl;

    for (int i=0; i< movies.size(); i++) {    
        string title = movies[i].getTitle();
        for (int j=0; j<title.length(); j++){
            title[j]=tolower(title[j]);
        }      
        for (int j=0; j<searchTerm.length(); j++){
            searchTerm[j]=tolower(searchTerm[j]);
        }
        if (searchTerm==title) {
            cout << movies[i];
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "No movies found matching the search term \"" << searchTerm << "\"." << endl;
    }
}

Movie Movie::selectMovie(){
    vector<Movie> movies;
    Movie::readFile(movies);
    Movie::viewMovie(movies);
    cout<<"Which movie do you want to add a screening for?\n";
    string pick;
    getline(cin,pick);
    for (int i=0; i< movies.size(); i++) {    
        string title = movies[i].getTitle();
        for (int j=0; j<title.length(); j++){
            title[j]=tolower(title[j]);
        }      
        for (int j=0; j<pick.length(); j++){
            pick[j]=tolower(pick[j]);
        }
        if (pick==title) {
            return movies[i];
        }
    }
   
    cout << "No movies with title \"" << pick<< "\"." << endl;
    Movie empty;
    return empty;
}

void Movie::deleteMovie(vector<Movie>& movies) {
    cout<<"\nEnter the name of the movie you want to delete: "<<endl;
    bool deleted=false;
    string searchTerm;
    getline(cin,searchTerm);
    for (int i=0; i< movies.size(); i++) {    
        string title = movies[i].getTitle();
        for (int j=0; j<title.length(); j++){
            title[j]=tolower(title[j]);
        }      
        for (int j=0; j<searchTerm.length(); j++){
            searchTerm[j]=tolower(searchTerm[j]);
        }
         if (searchTerm==title) {
            movies.erase(movies.begin()+i);
            deleted= true;
            cout << "Movie titled '" << searchTerm << "' has been deleted." << endl;  
            overwriteFile(movies);   
            count--; 
            break;
        }
    }
    if(!deleted) {
        cout << "No movie found with the title '" << searchTerm << "'." << endl;
    }
}

void Movie::overwriteFile(vector<Movie>& movies){
    ofstream fout;
    try{
    fout.open("movies.txt");
    if (fout.fail()){
        throw runtime_error("Error opening movies.txt for writing");
    }
    }
    catch(runtime_error &e){
        cout<<e.what()<<endl;
        return;
    }
     for (int i = 0; i < movies.size(); i++) {
        fout<<movies[i].title<<endl;
        fout<<movies[i].genre<<endl;
        fout<<movies[i].duration<<endl;
        fout<<movies[i].releaseDate<<endl;
        fout<<movies[i].ageRating<<endl;
    }
    fout.close();

}

bool Movie::saveToFile() {
    ofstream fout;
    try{
    fout.open("movies.txt",ios::app);
    if (fout.fail()){
        throw runtime_error("Error opening movies.txt for writing");
    }
    }
    catch(runtime_error &e){
        cout<<e.what()<<endl;
        return false;
    }
    fout<<title<<endl;
    fout<<genre<<endl;
    fout<<duration<<endl;
    fout<<releaseDate<<endl;
    fout<<ageRating<<endl;
    fout.close();
    return true;
}

void Movie::readFile(vector<Movie>& movies) {
    ifstream fin;
    Movie m;
    try{
    fin.open("movies.txt");
    if (fin.fail()){
        throw runtime_error("Error opening movies.txt for reading");
    }
    }
    catch(runtime_error &e){
        cout<<e.what()<<endl;
        return;
    }
    while( getline(fin,m.title)){
        getline(fin,m.genre);
        fin>>m.duration;
        fin.get();
        getline(fin,m.releaseDate);
        fin>>m.ageRating;
        fin.get();
        movies.push_back(m);
        count++;
    }
}

ostream& operator<<(ostream& output, const Movie& movie) {
    output<<setw(20)<<left<<movie.title<<setw(20)<<left<<movie.genre<<setw(20)<<left<<movie.duration<<setw(20)<<left<<movie.releaseDate<<movie.ageRating;
    return output;
}


string Movie:: getMovie(){
    string line="";
    line+=title+"\n"+genre+"\n"+to_string(duration)+"\n"+releaseDate+"\n"+to_string(ageRating);
    return line;
}
