/**
 * Diwas Dahal
 * Open Ended project
 * 10/02/2023
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <string>
#include "AnimeList.h"
#include "inputs.h"
#include "completedAnime.h"
#include "notCompletedAnime.h"
using namespace std;

// created a struct that holds all my data type that being recorded and read
struct entry{
    string name;
    string genre;
    string type;
    string season;
    int watchedEpisodes;
    int totalEpisodes;
    int year;
    int NumberOfSeasons;
    AnimeCategory category;
};


int main(){

    //initialized strut
    entry e1;

    inputs animeInput; // initialized inputs
    fstream myFile; //initialized file
    string filename = "aniList.csv"; //initialized a string

    //prints out the rules  and options
    animeInput.print_rules(cout);
    //animeInput.print_options(cout);

    char choice = 's'; //initialized choice

    vector<AnimeList> animes; //initialized vector
    completedAnime myCompletedAnimeList;
    notCompletedAnime myNotCompletedAnimeList;

    while (choice != 'e') {

        choice = animeInput.get_player_choice(cout, cin); //gets player choice

        switch(choice) {
            case 'i':
                animeInput.print_rules(cout);
                break;

            case 'v':
                if (readAnimeListFile(filename,  animes)){

                } else {
                    cout << "Something went wrong." << endl;
                }
                cout << "Your Watch List" << endl;
                // Print the data form the file
                cout << right
                     << setw(7) << "Name"
                     << right
                     << setw(25) << "Genre"
                     << setw(6) << "Type"
                     << right
                     << setw(8) << "Season"
                     << right
                     << setw(15) << "TotalEpisodes"
                     << right
                     << setw(20) << "WatchedEpisodes"
                     << right
                     << setw(8) << "Year"
                     << right
                     << setw(15) << "NumOfSeasons"
                     << setw(15)<< "Category"
                     <<endl;
                //this acutely prints the data
                cout << string(120, '-') << endl;
                for (int i = 0; i != animes.size(); i++) {
                    cout << animes.at(i) << endl;
                }
                animes.clear();
                break;

            case 's':
                cout << "################# Now You Can Start Adding #############" << endl;
                //ask user for input by getting methods form input file
                e1.name = animeInput.get_name_from_user();
                e1.genre = animeInput.get_genera_from_user();
                e1.type = animeInput.get_type_from_user();
                e1.season = animeInput.get_season_from_user();
                e1.totalEpisodes = animeInput.get_totalEpisode_from_user();
                e1.watchedEpisodes = animeInput.get_watchedEpisode_from_user();

                //check if total Episodes is less than watched episodes which can never happen
                while(e1.totalEpisodes < e1.watchedEpisodes){
                    cout <<"You can't watch more then total!!"<< endl;
                    e1.watchedEpisodes = animeInput.get_watchedEpisode_from_user();
                }
                e1.year = animeInput.get_year_from_user();
                e1.NumberOfSeasons = animeInput.get_numberOfSeasons_from_user();
                e1.category = animeInput.get_category_from_user();

                // opens an existing csv file or creates a new file.
                myFile.open("aniList.csv", ios::out | ios::app);

                // Read the input and Insert the data to file
                myFile << e1.name << ", "
                       << e1.genre << ", "
                       << e1.type << ", "
                       << e1.season << ","
                       << e1.totalEpisodes << ","
                       << e1.watchedEpisodes << ","
                       << e1.year << ","
                       << e1.NumberOfSeasons << ","
                       << CatToString(e1.category)
                       << "\n";

                myFile.flush();
                myFile.close();

                cout << "You added a: " << e1.name << " to the list" << endl;
                break;
            case 'c':
                if (readAnimeListFile(filename,  animes)){

                } else {
                    cout << "Something went wrong." << endl;
                }


                for (int i = 0; i != animes.size(); i++) {
                    //cout << animes.at(i) << endl;
                    if(animes.at(i).getTotalEpisodes() == animes.at(i).getWatchedEpisodes()) {
                        myCompletedAnimeList.addCompletedAnime(animes.at(i));
                    }
                }
                myCompletedAnimeList.displayCompletedAnimeList();

                break;

            case 'n':
                if (readAnimeListFile(filename,  animes)){

                } else {
                    cout << "Something went wrong." << endl;
                }

                for (int i = 0; i != animes.size(); i++) {
                    //cout << animes.at(i) << endl;
                    if(animes.at(i).getTotalEpisodes() != animes.at(i).getWatchedEpisodes()) {
                        myNotCompletedAnimeList.addNotCompletedAnime(animes.at(i));
                    }
                }
                myNotCompletedAnimeList.displayNotCompletedAnimeList();
                animes.clear();

                break;
            case 'r':
                bool valid = false;
                string input;

                while (!valid) {
                    // User input
                    cout << "Enter a Name: ";
                    getline(cin, input);
                    cin.clear();
                    if (input.empty()) {   // Check if the input is empty
                        cout << "No input. ";
                    } else {
                        valid = true;
                    }
                }
                 // boolean loop do while loop

                myNotCompletedAnimeList.removeAnimeFromCSV(input,filename );
                break;
        }
    }

    return 0;
}

