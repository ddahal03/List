/**
 * Diwas Dahal
 * Open Ended project
 * 10/02/2023
 */


#ifndef M1OEP_DDAHAL1_ANIMELIST_H
#define M1OEP_DDAHAL1_ANIMELIST_H

#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <cassert>


using namespace std;
/**
 * Enum class that has Show category to store the shows in
 */
enum class AnimeCategory{
    SHOUNEN,
    ACTION,
    MYSTERY,
    FANTASY,
    ISEKAI,
    OTHER
};

/**
 * Converts the inputted string in a enum value
 * @param categoryStr
 * @return enum value
 */
AnimeCategory StrToCategory(const string& categoryStr);

/**
 * converts the enum value to string
 * @param category
 * @return string
 */
string CatToString(AnimeCategory category);


/**
 * AnimeList class set and gets the vector also helps when printing them out in console
 */
class AnimeList {

    //private variables
private:
    string name, genre, type, season;
    int totalEpisodes, watchedEpisodes, year, NumberOfSeasons;
    AnimeCategory category;

public:

    /**
     * Default Constructors
     */
    AnimeList();

    AnimeList(vector<AnimeList>& anime);

    /**
     * Constructors with things
     * @param name
     * @param genre
     * @param type
     * @param season
     * @param watchedEpisodes
     * @param totalEpisodes
     * @param year
     * @param NumberOfSeasons
     * @param category
     */
    AnimeList(string name,
              string genre,
              string type,
              string season,
              int watchedEpisodes,
              int totalEpisodes,
              int year,
              int NumberOfSeasons,
              AnimeCategory category);


    //getters
    string getName()const;

    string getGenre()const;

    string getType()const;

    string getSeason()const;

    int getTotalEpisodes()const;

    int getWatchedEpisodes()const;

    int getYear()const;

    int getNumberOfSeasons()const;

    AnimeCategory getCategory()const;



    //setters
    void setName(string name);

    void setGenre(string genre);

    void setType(string type);

    void setSeason(string season);

    void setTotalEpisodes(int totalEpisodes);

    void setWatchedEpisodes(int watchedEpisodes);

    void setYear(int year);

    void setNumberOfSeasons(int NumberOfSeasons);

    void setCategory(AnimeCategory category);

    /**
     *
     * @param outs
     * @param Animes
     * @return
     */
    friend ostream &operator<<(ostream &outs, const AnimeList &Animes);
};

/**
 *
 * @param fileName
 * @param animeList
 * @return
 */
bool readAnimeListFile(string fileName,
                           vector<AnimeList>& animeList);


#endif //M1OEP_DDAHAL1_ANIMELIST_H
