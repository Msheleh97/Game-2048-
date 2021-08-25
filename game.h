#ifndef GAME_H
#define GAME_H

/**
 * @defgroup module My module
 *
 * @brief this module have the rules for the game and it add the same values
 * together and put the in their new positions.
 *
 *
 * @{
 */
#include <stdbool.h>
#include "array.h"

/* a global pointer to the array */
Array *p;

/**
 * name : game_get_square.
 * @brief Returns integer.
 * This function get the row and the column number and find the value in the
 * position and return it.
 *
 * @param two integers.
 * @return Returns an integer.
 */
int game_get_square(int row, int column);





/**
 * name : value_set.
 * @brief Returns nothing (void).
 * This function set the value in specific place using the index
 *
 * @param two integers and a pointer to struct Array.
 * @return Returns void.
 */
void value_set(Array *arr, int index, int value);





/**
 * name : game_slide_up.
 * @brief Returns nothing (void).
 * This function runs when the player chooces to slide up it adds the equal
 * values together and put them in specific positions, and moves the other
 * values to the right positions.
 *
 * @param nothing.
 * @return nothing.
 */
void game_slide_up(void);

/**
 * name : game_slide_down.
 * @brief Returns nothing (void).
 * This function runs when the player chooces to slide down. it adds the equal
 * values together and put them in specific positions and moves the other
 * values to the right positions.
 *
 * @param nothing.
 * @return nothing.
 */
void game_slide_down(void);

/**
 * name : game_slide_left.
 * @brief Returns nothing (void).
 * This function runs when the player chooces to slide left. it adds the equal
 * values together and put them in specific positions and moves the other
 * values to the right positions.
 *
 * @param nothing.
 * @return nothing.
 */
void game_slide_left(void);

/**
 * name : game_slide_right.
 * @brief Returns nothing (void).
 * This function runs when the player chooces to slide right. it adds the equal
 * values together and put them in specific positions and moves the other
 * values to the right positions.
 *
 * @param nothing.
 * @return nothing.
 */
void game_slide_right(void);

/**
 * name : game_is_game_over.
 * @brief Returns bool.
 * This function checks if the game is over and if yes it prints "game over".
 *
 *
 * @param nothing.
 * @return true or false.
 */
bool game_is_game_over(void);

/**
 * name : is_full.
 * @brief Returns bool.
 * This function checks if the array is full.
 *
 *
 * @param nothing.
 * @return true or false.
 */
bool is_full (void);

/**
 * name : search_neighbour.
 * @brief Returns bool.
 * This function checks if there are any possible moves left.
 *
 *
 * @param nothing.
 * @return true or false.
 */
bool search_neighbour (void);

/**
 * name : array_empty.s
 * @brief Returns void.
 * This function sets the positions to 0 after the values stored in it is moved.
 *
 *
 * @param an interger and a pointer to an array.
 * @return void.
 */
void array_empty(Array *arr, int index);

#endif
