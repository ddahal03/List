//
// Created by Student on 10/7/2023.
//
#include "completedAnime.h"

completedAnime::completedAnime() : AnimeList() {
    // Constructor for CompletedList
}

void completedAnime::addCompletedAnime(const AnimeList& anime) {
    completedAnimeList.push_back(anime);
}

void completedAnime::displayCompletedAnimeList() const {
    cout <<"Completed Anime List: " << endl;
    for (const AnimeList& anime : completedAnimeList) {
        cout << anime.getName() << endl; // Display the name of completed anime
    }

}
