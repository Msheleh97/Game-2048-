#ifndef APPLICATION_H
#define APPLICATION_H

/**
 * @defgroup module My module
 *
 * @brief controlling and running the game by the players choices
 *
 * controlling and running the game by the players choices. Checks if the game
 * is over and if the player win.
 *
 * @{
 */
#include "game.h"

#include <stdbool.h>

/**
 * name : app_run.
 * @brief Returns nothing (void).
 * This function is the main function of this game it run all the other
 * functions and its tell you when the game is over.
 *
 * @param void.
 * @return Returns nothing .
 */
void app_run(void);


/**
 * name : print_field.
 * @brief Returns nothing (void).
 * This function is responsable to print the games filed after every move.
 *
 *
 * @param it takes a pointer to the Array struct.
 * @return Returns nothing .
 */
void print_field(Array *p);

/**
 * name : print_menue.
 * @brief Returns an integer (void).
 * This function is responsable to print the games menue after every move and
 * give the player the available choices.
 *
 * @param nothing.
 * @return Returns an integer .
 */
int print_menu(void);


/**
 * name : game_new.
 * @brief Returns nothing (void).
 * This function is responsable to create a new game.
 *
 *
 * @param nothing.
 * @return Returns nothing .
 */
void game_new(void);

/**
 * name : value.
 * @brief Returns nothing (void).
 * This function fills the array with values.
 *
 *
 * @param it takes a pointer to the Array struct and an integer.
 * @return Returns nothing .
 */
void value(Array *a, int value);

/**
 * name : random_SpotAndValue.
 * @brief Returns nothing (void).
 * This function is responsable to fills the array with 2 random value in a
 * random spots;
 *
 * @param it takes a pointer to the Array struct.
 * @return Returns nothing .
 */
void random_SpotAndValue(Array *p);

/**
 * name : game_win.
 * @brief Returns a bool also a true or false value.
 * This function is responsable to Check if the player win.
 *
 *
 * @param it takes a pointer to the Array struct.
 * @return a bool .
 */
bool game_win(Array *p);

/**
 * @}
 */

#endif /* APPLICATION_H*/
