/**
 * Diwas Dahal
 * Open Ended project
 * 10/02/2023
 */


#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <cassert>
#include "AnimeList.h"

using namespace std;

AnimeCategory StrToCategory(const string &categoryStr) {
    if(categoryStr == "SHOUNEN"){
        return AnimeCategory::SHOUNEN;
    }else if (categoryStr == "ACTION"){
        return AnimeCategory::ACTION;
    }else if (categoryStr == "MYSTERY"){
        return AnimeCategory::MYSTERY;
    }else if (categoryStr == "FANTASY"){
        return AnimeCategory::FANTASY;
    }else if (categoryStr == "ISEKAI"){
        return AnimeCategory::ISEKAI;
    }else{
        return AnimeCategory:: OTHER;
    }
};

string CatToString(AnimeCategory category){
    switch(category){
        case AnimeCategory::SHOUNEN: return "SHOUNEN";
        case AnimeCategory::ACTION: return "ACTION";
        case AnimeCategory::MYSTERY: return "MYSTERY";
        case AnimeCategory::FANTASY: return "FANTASY";
        case AnimeCategory::ISEKAI: return "ISEKAI";
        case AnimeCategory::OTHER: return "OTHER";
        default: return "UNKNOWN";
    }
}

//used a class because I was Ashamed to use strut as a class even thought we can.
AnimeList::AnimeList() {

}

AnimeList::AnimeList(vector<AnimeList>& animes) {

}

AnimeList::AnimeList(string name,
              string genre,
              string type,
              string season,
              int watchedEpisodes,
              int totalEpisodes,
              int year,
              int NumberOfSeasons,
              AnimeCategory category) {
        this->name = name;
        this->genre = genre;
        this->type = type;
        this->season = season;
        this->totalEpisodes = totalEpisodes;
        this->watchedEpisodes = watchedEpisodes;
        this->year = year;
        this->NumberOfSeasons = NumberOfSeasons;
        this -> category = category;
    }

//getter
string AnimeList::getName() const {
    return name;
}

string AnimeList::getGenre() const {
    return genre;
}

string AnimeList::getType() const {
    return type;
}

string AnimeList::getSeason() const {
    return season;
}

int AnimeList::getTotalEpisodes() const {
    return totalEpisodes;
}

int AnimeList::getWatchedEpisodes() const {
    return watchedEpisodes;
}

int AnimeList::getYear() const {
    return year;
}

int AnimeList::getNumberOfSeasons() const {
    return NumberOfSeasons;
}

AnimeCategory AnimeList::getCategory() const {
    return category;
}


//setter
void AnimeList::setName(string name) {
    this->name = name;
}

void AnimeList::setGenre(string genre) {
    this->genre = genre;
}

void AnimeList::setType(string type) {
    this->type = type;
}

void AnimeList::setSeason(string season) {
    this->season = season;
}

void AnimeList::setTotalEpisodes(int totalEpisodes) {
    this->totalEpisodes = totalEpisodes;
}

void AnimeList::setWatchedEpisodes(int watchedEpisodes) {
    this->watchedEpisodes = watchedEpisodes;
}

void AnimeList::setYear(int year) {
    this->year = year;
}

void AnimeList::setNumberOfSeasons(int NumberOfSeasons) {
    this->NumberOfSeasons = NumberOfSeasons;
}

void AnimeList::setCategory(AnimeCategory category) {
    this->category = category;
}


// Overload stream insertion operator for pretty printing
ostream &operator<<(ostream &outs, const AnimeList &Animes) {
    int size;
    string name = Animes.getName();
    name = name.substr(0,15);
    //checking name to make it look good
    if(name.size() == 15)
    {
        name = name+"...";
    }
    if(name.size() < 5){
        name = name+"...          ";
    }

    outs
            << setw(size) << name
            << right
            << setw(15) << Animes.getGenre()
            << setw(5) << Animes.getType()
            << setw(5) << Animes.getSeason()
            << right
            <<"    "
            << setw(7) << Animes.getTotalEpisodes()
            << setw(20) << Animes.getWatchedEpisodes()
            << setw(15) << Animes.getYear()
            <<right
            << setw(10) << Animes.getNumberOfSeasons()
            << setw(20) << CatToString(Animes.getCategory());

    return outs;
}

bool readAnimeListFile(string fileName,
                       vector<AnimeList>& animeList){
    ifstream fIn;
    fIn.open(fileName);

    if(!fIn){   // checks if the file it being read
        return false;
    }

    string header="";
    getline(fIn, header);

    int counter = 1;
    while (fIn && fIn.peek() !=EOF){
        string name="INVALID", genre ="INVALID", type ="INVALID", season ="INVALID";
        int totalEpisodes = -1, watchedEpisodes = -1, year = -1, NumberOfSeasons= -1;
        AnimeCategory category;
        char comma =',';
        string categoryStr;

        //read the csv file with comma
        getline(fIn, name, comma) ;
        getline(fIn, genre, comma) ;
        getline(fIn, type, comma) ;
        getline(fIn, season, comma);
        fIn >> totalEpisodes;
        fIn >> comma;
        fIn >> watchedEpisodes;
        fIn >> comma;
        fIn >> year;
        fIn >> comma;
        fIn >> NumberOfSeasons;
        fIn >> comma;
        if (fIn.peek() != '\r' && fIn.peek() != '\n'){
            if (getline(fIn, categoryStr)) {
                category = StrToCategory(categoryStr);
            }
        }

        AnimeList Animes(name, genre,type,season,totalEpisodes,
                         watchedEpisodes, year, NumberOfSeasons, category);
        animeList.push_back(Animes); // sending it to vector in main


        counter += 1;

    }
    fIn.close();
    return true;
}


void verifyAllFieldsSet(vector<AnimeList>& objs) {
    int i = 0;
    //replaces any things that are empty or not valid with "INVALID" when reading form the csv file and prints out the information
    for (AnimeList &animeList: objs) {

        string name = animeList.getName();
        if (name.compare("INVALID") == 0) {
            cout << "Bad value for name at record "
                 << i << endl;
        }
        string genera = animeList.getGenre();
        if (genera.compare("INVALID") == 0) {
            cout << "Bad value for genera at record "
                 << i << endl;
        }
        string type = animeList.getType();
        if (type.compare("INVALID") == 0) {
            cout << "Bad value for type at record "
                 << i << endl;
        }
        string season = animeList.getSeason();
        if (season.compare("INVALID") == 0) {
            cout << "Bad value for season at record "
                 << i << endl;
        }
        int totalEpisodes = animeList.getTotalEpisodes();
        if (totalEpisodes == 0) {
            cout << "Bad value for year of registration at record "
                 << i << std::endl;
        }
        int watchedEpisodes = animeList.getWatchedEpisodes();
        if (watchedEpisodes == -1) {
            cout << "Bad value for episodesWatched of registration at record "
                 << i << endl;
        }
        int year = animeList.getYear();
        if (year == 0) {
            cout << "Bad value for year of registration at record "
                 << i << endl;
        }
        int NumberOfSeasons = animeList.getNumberOfSeasons();
        if (NumberOfSeasons == 0) {
            cout << "Bad value for NumberOfSeasons of registration at record "
                 << i << endl;
        }
        if (animeList.getCategory() == AnimeCategory::OTHER) {
            std::cout << "Bad value for category at record " << i << std::endl;
        }
        i += 1;
    }
}

