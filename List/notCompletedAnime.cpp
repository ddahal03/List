//
// Created by Student on 10/7/2023.
//

#include "notCompletedAnime.h"


notCompletedAnime::notCompletedAnime() : AnimeList() {
    // Constructor for CompletedList
}

void notCompletedAnime::addNotCompletedAnime(const AnimeList& anime) {
    notCompletedAnimeList.push_back(anime);
}
void notCompletedAnime::removeAnimeFromCSV(const string& animeName, const string& csvFileName) {
    ifstream inFile(csvFileName);
    if (!inFile) {
        cerr << "Failed to open CSV file for reading." << endl;
        return;
    }

    vector<std::string> lines; // To store lines without the removed anime
    string line;

    while (getline(inFile, line)) {
        string currentAnimeName;
        istringstream iss(line);
        getline(iss, currentAnimeName, ',');

        if (currentAnimeName != animeName) {
            // Add this line to the list of lines to keep
            lines.push_back(line);
        }
    }

    inFile.close();

    ofstream outFile(csvFileName); // Reopen the file for writing (overwriting)
    if (!outFile) {
        cerr << "Failed to open CSV file for writing." << endl;
        return;
    }

    // Rewrite the file with the updated lines
    for (const string& updatedLine : lines) {
        outFile << updatedLine << endl;
    }

    outFile.close();
}

void notCompletedAnime::displayNotCompletedAnimeList() const {
    cout <<"Not Completed Anime List: " << endl;
    for (const AnimeList& anime : notCompletedAnimeList) {
        cout << anime.getName() << endl; // Display the name of Not completed anime list
    }
}