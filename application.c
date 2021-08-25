#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <stdlib.h>
#include "application.h"
#include "array.h"
#include "game.h"

#define RAD 4
#define COLS 4

void app_run(void){
  int val, win;
  srand(time(0));
  game_new();
  random_SpotAndValue(p);
  random_SpotAndValue(p);

  do {
    print_field(p);
    val = print_menu();
    win = game_win(p);
    if(!search_neighbour()){
      val = 0;
      printf("GAME OVER\n");
    }
    switch (val) {
      case 0:  printf("Quiting game\n"); break;

      case 1:  printf("Sliding up\n"); game_slide_up();
               random_SpotAndValue(p); break;
      case 2:  printf("Sliding right\n"); game_slide_right();
               random_SpotAndValue(p); break;
      case 3:  printf("Sliding down\n"); game_slide_down();
               random_SpotAndValue(p); break;
      case 4:  printf("Sliding left\n"); game_slide_left();
               random_SpotAndValue(p); break;
      default: printf("Wrong choice\n");
    }
  }while (val != 0 && win == false);
}

void value(Array *a, int value){
for( int i = 0; i <4 ; i++ ){
  if (*(a->data+i+value) == 0){
    printf("|        ");
  }
  else if (*(a->data+i+value) != 0){
    printf("| %4d   ",*(a->data+i+value) );
  }
}
printf("|\n");
}

void print_field(Array *p){
  int index = 0;
   for (int i = 0; i < 17;i++){
    if (i == 0 || i== 4 || i==8 || i==12 || i==16){
      printf("+--------+--------+--------+--------+\n");
    }
    else if (i == 2 || i== 6 || i==10 || i==14){
      value(p, index);
      index += 4;
    }
    else {
      printf("|        |        |        |        |\n");
    }
   }
 }

void random_SpotAndValue(Array *p){
   int spot1, spot2, index, cols_value;
   do{
   spot1 = rand() % RAD;
   spot2 = rand() % RAD;
   cols_value =game_get_square(spot1,spot2);
   index = RAD * spot1 + spot2;

   if (is_full() && cols_value > 0){
     printf("choose another move\n");
     return;
   }

 }while(cols_value != 0);

 int value = (rand() % 10) ? 2 : 4;

 value_set(p, index, value);
 }

void game_new(void){
   p = array_create(RAD,COLS);
 }

 int print_menu(void){
   int val;
   printf("SELECT ACTION\n");
   printf("0: quit\n");
   printf("1: slide up\n");
   printf("2: slide right\n");
   printf("3: slide down\n");
   printf("4: slide left\n");
   scanf("%d", &val);
   printf("? %d\n", val);
   return val;
 }

 bool game_win(Array *p){
   for(int i = 0; i > 16; i++){
     if(*(p->data+i) == 2048){
       return true;
     }
   }
   return false;
 }
