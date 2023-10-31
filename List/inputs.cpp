/**
 * Diwas Dahal
 * Open Ended project
 * 10/02/2023
 */


#include <iostream>
#include <string>

#include "inputs.h"
#include "AnimeList.h"

using namespace std;



inputs::inputs() {
    // Constructor implementation goes here
}

char inputs::get_player_choice(ostream &cout, istream &cin) {
    char choice;
    print_options(cout);
    cin >> choice;
    choice = tolower(choice);
    while (choice != 's' && choice != 'v' && choice != 'e' && choice != 'i' && choice != 'c' && choice != 'n' && choice != 'r') {
        cout << endl << "Invalid option. " << endl;
        print_options(cout);
        cin >> choice;
    }
    return choice;
}

void inputs::print_options(ostream &cout) {
    cout << "Press (s) to Start, (v) to view list,(i) to view Manual, (c) to view Completed List, (n) to view Not completed List, (r) to remove Anime, or (e) to exit: ";
}

void inputs::print_rules(ostream &cout) {
    cout << "Rules of How to use the program." << endl;
    cout << "The goal of this program is help a person keep track of thing they have watched." << endl;
    cout << "You simply put all the information the program ask for, and it will creat a list of all the things you have watched" << endl;
    cout << "The randomized feature is not for the person who watched the show or use this program but when someone ask `could you tell me something to watch?`" << endl;

}
string inputs::get_name_from_user() {
    // NOTE: a sentence does NOT need punctuation or syntax validation
    bool valid = false;
    string input;

    do {
        //user input
        cout << "Enter a Name: ";
        getline(cin,input);

        if (input.empty()) {   //checks if the input is empty
            cout <<"No input. ";
            valid = false;
        }
        else{
            valid = true;
        }

    }
    while (!valid); // boolean loop do while loop

    return input;
}

string inputs::get_genera_from_user() {

    bool valid = false;
    string input;

    do {
        //user input
        cout << "Enter a Genera: ";
        getline(cin, input); // don't want to  skip white space

        //checks for white space in the user input
        size_t spaceCount = count(input.begin(), input.end(), ' ');

        if (input.empty()) {     //checks if user input is empty
            cout <<"No input. ";
            valid = false;
        }
        else if (spaceCount != 0){  // checks for empty spaces in the input
            cout<<"invalid Input. ";
            valid = false;
        }
        else{
            valid = true;
        }

    }
    while (!valid); // boolean loop

    return input;
}

string inputs::get_type_from_user() {

    bool valid = false;
    string input;

    do {
        //user input
        cout << "Enter a Type (Movie, TVShow or Anime):";
        getline(cin, input); // don't want to  skip white space

        //checks for white space in the user input
        size_t spaceCount = count(input.begin(), input.end(), ' ');

        if (input.empty()) {     //checks if user input is empty
            cout <<"No input. ";
            valid = false;
        }
        else if (spaceCount != 0 || input != "Movie"&& input != "TVShow" && input != "Anime"){  // checks for empty spaces in the input
            cout<<"invalid Input. ";
            valid = false;
        }
        else{
            valid = true;
        }

    }
    while (!valid); // boolean loop

    return input;
}

string inputs::get_season_from_user() {

    bool valid = false;
    string input;

    do {
        //user input
        cout << "Enter a season (Winter, Fall, Summer, Spring): ";
        getline(cin, input); // don't want to  skip white space

        //checks for white space in the user input
        size_t spaceCount = count(input.begin(), input.end(), ' ');

        if (input.empty()) {     //checks if user input is empty
            cout <<"No input. ";
            valid = false;
        }
        else if (spaceCount != 0 || input != "Summer" && input != "Spring" && input != "Fall" && input != "Winter" ){  // checks for empty spaces in the input
            cout<<"invalid Input: ";
            valid = false;
        }
        else{
            valid = true;
        }

    }
    while (!valid); // boolean loop

    return input;
}


int inputs::get_totalEpisode_from_user() {

    //variables
    bool valid = false;
    string input;
    int num;
    bool negative = false;

    do {
        valid = true;
        //user input
        cout << "Enter Total Number Of Episodes: ";
        getline(cin, input);

        if(input.empty()){   //checks if user input it empty
            cout <<"No input. ";
            valid = false;
        }
        else {
            int i;
            // TO validate the negative integers, the if statement make it skip that sign
            if (input[0] == '-'){
                input.erase(0, 1);
                negative = true;
            }

            // the for loop runs through the input and check if each character is an integer or not
            for(i = 0; i < input.size(); i++) {
                if (!(isdigit(input[i]))) {
                    valid = false;
                }
            }

            if (!valid){  // if one those entered character is not an integer it is invalid
                cout << "Invalid input. ";
                cin.clear();
            }
            if (valid){ // if it is valid it converts the string to integer and puts the "-" back
                if(negative){
                    input= '-'+ input;
                }
                num = stoi(input); //converts the string to int
            }

        }
    }
    while (!valid); //boolean do while loop

    return num;
}

int inputs::get_watchedEpisode_from_user() {
    // TODO: Complete the function

    //variables
    bool valid = false;
    string input;
    int num;
    bool negative = false;

    do {
        valid = true;
        //user input
        cout << "Enter Total Number Of Watched Episodes: ";
        getline(cin, input);

        if(input.empty()){   //checks if user input it empty
            cout <<"No input. ";
            valid = false;
        }
        else {
            int i;
            // TO validate the negative integers, the if statement make it skip that sign
            if (input[0] == '-'){
                input.erase(0, 1);
                negative = true;
            }

            // the for loop runs through the input and check if each character is an integer or not
            for(i = 0; i < input.size(); i++) {
                if (!(isdigit(input[i]))) {
                    valid = false;
                }
            }

            if (!valid){  // if one those entered character is not an integer it is invalid
                cout << "Invalid input. ";
                cin.clear();
            }
            if (valid){ // if it is valid it converts the string to integer and puts the "-" back
                if(negative){
                    input= '-'+ input;
                }
                num = stoi(input); //converts the string to int
            }

        }
    }
    while (!valid); //boolean do while loop

    return num;
}

int inputs::get_year_from_user() {

    //variables
    bool valid = false;
    string input;
    int num;
    bool negative = false;

    do {
        valid = true;
        //user input
        cout << "What Year Did The Show Come Out: ";
        getline(cin, input);

        if(input.empty()){   //checks if user input it empty
            cout <<"No input. ";
            valid = false;
        }
        else {
            int i;
            // TO validate the negative integers, the if statement make it skip that sign
            if (input[0] == '-'){
                input.erase(0, 1);
                negative = true;
            }

            // the for loop runs through the input and check if each character is an integer or not
            for(i = 0; i < input.size(); i++) {
                if (!(isdigit(input[i]))) {
                    valid = false;
                }
            }

            if (!valid){  // if one those entered character is not an integer it is invalid
                cout << "Invalid input. ";
                cin.clear();
            }
            if (valid){ // if it is valid it converts the string to integer and puts the "-" back
                if(negative){
                    input= '-'+ input;
                }
                num = stoi(input); //converts the string to int
            }

        }
    }
    while (!valid); //boolean do while loop

    return num;
}


int inputs::get_numberOfSeasons_from_user() {

    //variables
    bool valid = false;
    string input;
    int num;
    bool negative = false;

    do {
        valid = true;
        //user input
        cout << "Enter the season of the Anime: ";
        getline(cin, input);

        if(input.empty()){   //checks if user input it empty
            cout <<"No input. ";
            valid = false;
        }
        else {
            int i;
            // TO validate the negative integers, the if statement make it skip that sign
            if (input[0] == '-'){
                input.erase(0, 1);
                negative = true;
            }

            // the for loop runs through the input and check if each character is an integer or not
            for(i = 0; i < input.size(); i++) {
                if (!(isdigit(input[i]))) {
                    valid = false;
                }
            }

            if (!valid){  // if one those entered character is not an integer it is invalid
                cout << "Invalid input. ";
                cin.clear();
            }
            if (valid){ // if it is valid it converts the string to integer and puts the "-" back
                if(negative){
                    input= '-'+ input;
                }
                num = stoi(input); //converts the string to int
            }

        }
    }
    while (!valid); //boolean do while loop

    return num;
}

AnimeCategory inputs::get_category_from_user() {
    char categoryChoice;

    do {
        cout << "Enter Category (s for Shounen, a for Action, m for Mystery, i for Isekai, f for Fantasy,o for Other): ";
        cin >> categoryChoice;
        categoryChoice = tolower(categoryChoice); // Convert to lowercase for case-insensitive input

        switch (categoryChoice) {
            case 's':
                return AnimeCategory::SHOUNEN;
            case 'a':
                return AnimeCategory::ACTION;
            case 'm':
                return AnimeCategory::MYSTERY;
            case 'o':
                return AnimeCategory::OTHER;
            case 'i':
                return AnimeCategory::ISEKAI;
            case 'f':
                return AnimeCategory::FANTASY;
            default:
                cout << "Invalid category choice. Please choose s, a, m, i, f, or o." << endl;
        }
    } while (true); // Keep prompting until a valid choice is entered
}