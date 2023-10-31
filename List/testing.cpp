//
// Created by Student on 10/7/2023.
//
#include <iostream>
#include "completedAnime.h"
#include "AnimeList.h"
#include "inputs.h"
#include "notCompletedAnime.h"
#include <ctime>
#include <cassert>

using namespace std;

bool test_AnimeList();
bool test_inputs();
bool test_completedAnime();
bool test_notCompletedAnime();

int main() {
    if (test_AnimeList()) {
        cout << "All AnimeList test cases passed!!!!!!!!!!!!!!!!" << endl;
    }
    if(test_completedAnime()){
        cout << "All completedAnime test cases passed!!!!!!!!!!!!!!!!" << endl;
    }
    if(test_notCompletedAnime()){
        cout << "All notCompletedAnime test cases passed!!!!!!!!!!!!!" << endl;
    }
//    if (test_inputs()) {
//        cout << "All tests passed!!!!!!!!!!!!" << std::endl;
//    }

    return 0;
}

bool test_AnimeList() {
    bool passed = true;

    // Test constructor and getters
    AnimeList anime1("Naruto", "Action", "TV", "Spring 2002", 220, 220, 2002, 5, AnimeCategory::SHOUNEN);
    assert(anime1.getName() == "Naruto");
    assert(anime1.getGenre() == "Action");
    assert(anime1.getType() == "TV");
    assert(anime1.getSeason() == "Spring 2002");
    assert(anime1.getTotalEpisodes() == 220);
    assert(anime1.getWatchedEpisodes() == 220);
    assert(anime1.getYear() == 2002);
    assert(anime1.getNumberOfSeasons() == 5);
    assert(anime1.getCategory() == AnimeCategory::SHOUNEN);

    // Test setters
    anime1.setName("Naruto Shippuden");
    anime1.setGenre("Adventure");
    anime1.setType("OVA");
    anime1.setSeason("Fall 2007");
    anime1.setTotalEpisodes(500);
    anime1.setWatchedEpisodes(300);
    anime1.setYear(2007);
    anime1.setNumberOfSeasons(10);
    anime1.setCategory(AnimeCategory::ACTION);

    assert(anime1.getName() == "Naruto Shippuden");
    assert(anime1.getGenre() == "Adventure");
    assert(anime1.getType() == "OVA");
    assert(anime1.getSeason() == "Fall 2007");
    assert(anime1.getTotalEpisodes() == 500);
    assert(anime1.getWatchedEpisodes() == 300);
    assert(anime1.getYear() == 2007);
    assert(anime1.getNumberOfSeasons() == 10);
    assert(anime1.getCategory() == AnimeCategory::ACTION);

    return passed;
}

bool test_inputs() {
    inputs input_handler;
    bool passed = true;

    // Test get_player_choice method
    char choice = input_handler.get_player_choice(cout, cin);
    assert(choice == 's' || choice == 'v' || choice == 'i' || choice == 'n' ||choice == 'r' ||choice == 'e');

    // Test get_name_from_user method
    string name = input_handler.get_name_from_user();
    assert(name == "Naruto");

    // Test get_genera_from_user method
    std::string genera = input_handler.get_genera_from_user();
    assert(genera == "Action");

    // Test get_type_from_user method
    std::string type = input_handler.get_type_from_user();
    assert(type == "Anime");

    // Test get_season_from_user method
    std::string season = input_handler.get_season_from_user();
    assert(season == "Fall");

    // Test get_totalEpisode_from_user method
    int total_episodes = input_handler.get_totalEpisode_from_user();
    assert(total_episodes == 24);

    // Test get_watchedEpisode_from_user method
    int watched_episodes = input_handler.get_watchedEpisode_from_user();
    assert(watched_episodes == 12);

    // Test get_year_from_user method
    int year = input_handler.get_year_from_user();
    assert(year == 2020);

    // Test get_numberOfSeasons_from_user method
    int num_seasons = input_handler.get_numberOfSeasons_from_user();
    assert(num_seasons == 3);

    // Test get_category_from_user method
    AnimeCategory category = input_handler.get_category_from_user();
    assert(category == AnimeCategory::SHOUNEN);

    return passed;
}

bool test_completedAnime() {
    completedAnime completed_list;

    // Create some test AnimeList objects
    AnimeList anime1("Naruto", "Action", "Anime", "Fall", 24, 24, 2020, 3, AnimeCategory::SHOUNEN);
    AnimeList anime2("One Piece", "Adventure", "Anime", "Summer", 1000, 1000, 1999, 20, AnimeCategory::ACTION);

    // Add the test AnimeList objects to the completedAnime list
    completed_list.addCompletedAnime(anime1);
    completed_list.addCompletedAnime(anime2);

    return true;
}

bool test_notCompletedAnime() {
    // Create test notCompletedAnime objects
    notCompletedAnime animeList;

    AnimeList anime1("Naruto", "Action", "Anime", "Fall", 24, 12, 2020, 3, AnimeCategory::SHOUNEN);
    AnimeList anime2("One Piece", "Adventure", "Anime", "Summer", 1000, 500, 1999, 20, AnimeCategory::ACTION);
    AnimeList anime3("Death Note", "Mystery", "Anime", "Winter", 37, 37, 2006, 1, AnimeCategory::MYSTERY);

    // Test addNotCompletedAnime and displayNotCompletedAnimeList methods
    animeList.addNotCompletedAnime(anime1);
    animeList.addNotCompletedAnime(anime2);
    animeList.addNotCompletedAnime(anime3);

    //cout << "Not Completed Anime List:" << endl;
    //animeList.displayNotCompletedAnimeList();

    // Test removeAnimeFromCSV method (assuming there's a CSV file with anime data)
    animeList.removeAnimeFromCSV("One Piece", "aniList.csv");

    //cout << "Updated Not Completed Anime List after removing 'One Piece':" << endl;
    //animeList.displayNotCompletedAnimeList();

    return true;
}






