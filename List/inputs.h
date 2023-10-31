/**
 * Diwas Dahal
 * Open Ended project
 * 10/02/2023
 */

#ifndef M1OEP_DDAHAL1_INPUTS_H
#define M1OEP_DDAHAL1_INPUTS_H


#include <ctype.h>
#include <iostream>
#include <sstream>
#include <string>
#include <limits>
#include <algorithm>
#include <string.h>


#include "AnimeList.h"

using namespace std;

class inputs{

public:

    /**
     * Default Constructor
     */
    inputs();

    /**
     * Gets player's choice
     * @param cout
     * @param cin
     * @return
     */
    char get_player_choice(ostream &cout, istream &cin);

    /**
     * Prints out options
     * @param cout
     */
    void print_options(ostream &cout);

    /**
     * Prints out rules
     * @param cout
     */
    void print_rules(ostream &cout);

    /**
     * Ask for Name and validate that
     * @return string
     */
    string get_name_from_user();

    /**
     * Ask for Genera and validate that
     * @return string
     */
    string get_genera_from_user();

    /**
     * Ask for Type and validate that
     * @return string
     */
    string get_type_from_user();

    /**
     * Ask for one of the four season and validate that
     * @return string
     */
    string get_season_from_user();

    /**
     * Ask for and total episodes the show has and validates that as an integer
     * @return integer
     */
    int get_totalEpisode_from_user();

    /**
     * Ask for and total episodes watched and validates that as an integer
     * @return integer
     */
    int get_watchedEpisode_from_user();

    /**
     * Ask for what year the show came out and validates that as an integer
     * @return integer
     */
    int get_year_from_user();

    /**
     * Ask for and total number of season the show has and validates that as an integer
     * @return integer
     */
    int get_numberOfSeasons_from_user();

    /**
     * Ask to choose one of category and sets the show as one of category
     * @return enum value
     */
    AnimeCategory get_category_from_user();

};
#endif //M1OEP_DDAHAL1_INPUTS_H
