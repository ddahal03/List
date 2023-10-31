//
// Created by Student on 10/7/2023.
//

#ifndef M2OEP_DDAHAL1_NOTCOMPLETEDANIME_H
#define M2OEP_DDAHAL1_NOTCOMPLETEDANIME_H

#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <iostream>
#include "AnimeList.h"

using namespace std;


class notCompletedAnime : public AnimeList {
private:
    vector<AnimeList> notCompletedAnimeList;
public:
    notCompletedAnime();

    // Add anime by name to the completed anime list based on the entire AnimeList object
    void addNotCompletedAnime(const AnimeList& anime);

    // Display the list of completed anime by name
    void displayNotCompletedAnimeList() const;

    void removeAnimeFromCSV(const string& animeName, const string& csvFileName);

};


#endif //M2OEP_DDAHAL1_NOTCOMPLETEDANIME_H
