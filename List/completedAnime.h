//
// Created by Student on 10/4/2023.
//

#ifndef M2OEP_DDAHAL1_COMPLETEDANIME_H
#define M2OEP_DDAHAL1_COMPLETEDANIME_H


#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <iostream>
#include "AnimeList.h"

using namespace std;


class completedAnime : public AnimeList {
private:
    vector<AnimeList> completedAnimeList;

public:
    completedAnime();

    // Add anime by name to the completed anime list based on the entire AnimeList object
    void addCompletedAnime(const AnimeList& anime);

    // Display the list of completed anime by name
    void displayCompletedAnimeList() const;

};



#endif //M2OEP_DDAHAL1_COMPLETEDANIME_H
