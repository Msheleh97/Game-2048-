#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "game.h"
#include "application.h"

#define RAD 4
#define COLS 4

static int get_quantity_numbers (int i,char direction){
  int quantity_numbers=0;
  for (int c = 0; c<4; c++){
    if (direction == 1){
      int value = game_get_square (i,c);
      if (value > 0){
         quantity_numbers++;
      }
    }
    else if(direction == 2){
      int value = game_get_square (c,i);
      if (value > 0){
         quantity_numbers++;
      }
    }
  }
  return quantity_numbers;
}

static void empty_your_cols_up_dows(int plats2,int plats3,int plats4, int num, int i){
  if (num == 3){
    array_empty(p,(plats2+i));
    array_empty(p,(plats3+i));
    array_empty(p,(plats4+i));
  }
  if (num == 2){
    array_empty(p,(plats3+i));
    array_empty(p,(plats4+i));
  }
  if (num == 1){
    array_empty(p,(plats4+i));
  }
}

void value_set(Array *arr, int index, int value)
{
  *(arr -> data + index) = value;
}

static void rule_up_down(int value1,int value2,int value3, int value4,int       plats1,int plats2, int plats3, int plats4, int number,int i){
  if(number==1){
      value_set(p,plats1+i,value1);
      empty_your_cols_up_dows (plats2,plats3,plats4,3,i);
  }
  if(number==2){
    if (value1 == value2){
      value_set(p,(plats1+i),(value1+value2));
      empty_your_cols_up_dows(plats2,plats3,plats4,3,i);
    }
    else{
        value_set (p,(plats1+i),value1);
        value_set (p,(plats2+i),value2);
        empty_your_cols_up_dows(plats2,plats3,plats4,2,i);
    }
   }
  if (number == 3){

     if (value1 == value2){
        value_set(p,(plats1+i),(value1+value2));
        value_set(p,(plats2+i),value3);
        empty_your_cols_up_dows(plats2,plats3,plats4,2,i);
     }
     else if (value2 == value3){
       value_set (p,(plats1+i),value1);
       value_set (p,(plats2+i),(value2+value3));
       empty_your_cols_up_dows(plats2,plats3,plats4,2,i);
     }
     else {
      value_set (p,(plats1+i),value1);
      value_set (p,(plats2+i),value2);
      value_set (p,(plats3+i),value3);
      empty_your_cols_up_dows(plats2,plats3,plats4,1,i);
    }
  }
  if (number == 4){
    if (value1==value2 && value3==value4){
      value_set (p,(plats1+i),(value1+value2));
      value_set (p,(plats2+i),(value3+value4));
      empty_your_cols_up_dows(plats2,plats3,plats4,2,i);
    }
    else if (value1==value2){
      value_set(p,(plats1+i),(value1+value2));
      value_set(p,(plats2+i),value3);
      value_set(p,(plats3+i),value4);
      empty_your_cols_up_dows(plats2,plats3,plats4,1,i);
    }
    else if (value2==value3){
      value_set(p,(plats2+i),(value2+value3));
      value_set(p,(plats3+i),value4);
      empty_your_cols_up_dows(plats2,plats3,plats4,1,i);
    }
    else if (value3 == value4){
      value_set(p,(plats3+i),(value3+value4));
      empty_your_cols_up_dows(plats2,plats3,plats4,1,i);
    }
  }
}

static void empty_your_cols_right_left(int position,int num){

  if (num == 6){
    array_empty(p,(position-1));
    array_empty(p,(position-2));
    array_empty(p,(position-3));
  }
  if(num == 5){
    array_empty(p,(position-2));
    array_empty(p,(position-3));
  }
  if(num==4){
    array_empty(p,(position-3));
  }
  if(num==3){
    array_empty(p,(position+1));
    array_empty(p,(position+2));
    array_empty(p,(position+3));
  }
  if(num==2){
    array_empty(p,(position+2));
    array_empty(p,(position+3));
  }
  if(num==1){
    array_empty(p,(position+3));
  }
}

int game_get_square(int row, int column){
    int index = RAD * row + column;
    int value = *(p->data+index);
    return value;
}

static void find_values (int *value1, int *value2, int *value3, int *value4, int num,int i, int sit){
  if(num == 1){
      for (int a = 0; a<4; a++){
        if (sit == 1){
          if(game_get_square(a,i) > 0){
            *value1 = game_get_square(a,i);
          }
        }
        else {
          if(game_get_square(i,a) > 0){
            *value1 = game_get_square(i,a);
          }
        }
      }
    }

  if (num == 2){
    for (int x = 0; x<4 ; x++){
      if (sit == 1){
        if (*value1 == 0){
          *value1 = game_get_square(x,i);
        }
        else if (*value2 == 0) {
          *value2 = game_get_square(x,i);
        }
      }
      else {
        if (*value1 == 0){
          *value1 = game_get_square(i,x);
        }
        else if (*value2 == 0) {
          *value2 = game_get_square(i,x);
        }
      }
    }
  }

  if (num == 3){
    for(int a=0; a<4; a++){
      if(sit == 1){
        if (*value1 == 0){
          *value1 = game_get_square(a,i);
        }
        else if (*value2 == 0) {
          *value2 = game_get_square(a,i);
        }
        else if (*value3 == 0){
          *value3 = game_get_square(a,i);
        }
      }
      else {
        if (*value1 == 0){
          *value1 = game_get_square(i,a);
        }
        else if (*value2 == 0) {
          *value2 = game_get_square(i,a);
        }
        else if (*value3 == 0){
          *value3 = game_get_square(i,a);
        }
      }
    }
   }
   if (num == 4){
     for(int a=0; a<4; a++){
       if (sit==1){
         if (*value1 == 0){
           *value1 = game_get_square(a,i);
         }
         else if (*value2 == 0) {
           *value2 = game_get_square(a,i);
         }
         else if (*value3 == 0){
            *value3 = game_get_square(a,i);
         }
         else if (*value4 == 0){
            *value4 = game_get_square(a,i);
         }
       }
       else {
         if (*value1 == 0){
           *value1 = game_get_square(i,a);
         }
         else if (*value2 == 0) {
           *value2 = game_get_square(i,a);
         }
         else if (*value3 == 0){
            *value3 = game_get_square(i,a);
         }
         else if (*value4 == 0){
            *value4 = game_get_square(i,a);
         }
       }
     }
   }
 }

void game_slide_up(void){

    int i = 0;
    int plats1 = 0, plats2 = 4, plats3 = 8, plats4 = 12;
    while (i < 4) {
      int number = get_quantity_numbers(i,2);

      if (number==1){
        int value=0;
        int *value1 = &value;
        find_values(value1,0,0,0,1,i,1);
        rule_up_down(value,0,0,0,plats1,plats2,plats3,plats4,1,i);
      } // om vi har 1 värde

      else if(number == 2){
        int value1 = 0, value2 = 0;
        int *value_1 = &value1; int *value_2 = &value2;
        find_values (value_1,value_2,0,0,2,i,1);
        rule_up_down(value1,value2,0,0,plats1,plats2,plats3,plats4,2,i);
      }// om vi har 2 värde

      if(number == 3){
        int value1 = 0, value2 = 0, value3 = 0;
        int *value_1= &value1; int *value_2=&value2; int *value_3=&value3;
        find_values (value_1,value_2,value_3,0,3,i,1);
        rule_up_down(value1,value2,value3,0,plats1,plats2,plats3,plats4,3,i);
      }// om vi har 3 värde

      if (number == 4){
        int value1 = 0, value2 = 0, value3 = 0, value4 = 0;
        int *value_1= &value1; int *value_2=&value2; int *value_3=&value3;
        int *value_4 = &value4;
        find_values (value_1,value_2,value_3,value_4,4,i,1);
        rule_up_down(value1,value2,value3,value4,plats1,plats2,plats3,
                    plats4,4,i);
     }// om vi har 4 värde.
     i++;
    }
}

void game_slide_down(void){

  int i = 0, plats1 = 12, plats2= 8, plats3= 4, plats4 = 0;
  while (i < 4) {
    int number = get_quantity_numbers(i,2);

    if (number==1){
      int value=0;
      int *value1 = &value;
      find_values(value1,0,0,0,1,i,1);
      rule_up_down(value,0,0,0,plats1,plats2,plats3,plats4,1,i);
    } // om vi har 1 värde

    else if(number == 2){
      int value1 = 0, value2 = 0;
      int *value_1 = &value1; int *value_2 = &value2;
      find_values (value_2,value_1,0,0,2,i,1);
      rule_up_down(value1,value2,0,0,plats1,plats2,plats3,plats4,2,i);
    }// om vi har 2 värde

    if(number == 3){
      int value1 = 0, value2 = 0, value3 = 0;
      int *value_1= &value1; int *value_2=&value2; int *value_3=&value3;
      find_values (value_3,value_2,value_1,0,3,i,1);
      rule_up_down(value1,value2,value3,0,plats1,plats2,plats3,plats4,3,i);
    }// om vi har 3 värde

    if (number == 4){
      int value1 = 0, value2 = 0, value3 = 0, value4 = 0;
      int *value_1= &value1; int *value_2=&value2; int *value_3=&value3;
      int *value_4 = &value4;
      find_values (value_4,value_3,value_2,value_1,4,i,1);
      rule_up_down(value1,value2,value3,value4,plats1,plats2,plats3,plats4,4,i);
    }// om vi har 4 värde.
    i++;
  }
}

void game_slide_right(void){

  int position = 3;
  for (int i = 0; i < 4 ; i++){
    int number=get_quantity_numbers(i,1);

    if (number==1){
      int value=0;
      int *value1 = &value;
      find_values(value1,0,0,0,1,i,2);
      value_set (p,position,value);
      empty_your_cols_right_left(position,6);
    } // om vi har 1 värde

    if(number == 2){
      int value1 = 0, value2 = 0;
      int *value_1 = &value1; int *value_2 = &value2;
      find_values (value_1,value_2,0,0,2,i,2);

      if (value1 == value2){
        value_set(p,position,(value1+value2));
        empty_your_cols_right_left(position,6);
      }
      else{
          value_set (p,position,value2);
          value_set (p,(position-1),value1);
          empty_your_cols_right_left(position,5);
      }
    } // om vi har 2 värde

    if(number == 3){
      int value1 = 0, value2 = 0, value3 = 0;
      int *value_1= &value1; int *value_2=&value2; int *value_3=&value3;
      find_values (value_1,value_2,value_3,0,3,i,2);

      if (value2 == value3){
          value_set (p,position,(value2+value3));
          value_set (p,(position-1),value1);
          empty_your_cols_right_left(position,5);
      }
      else if (value1 == value2){
          value_set(p,position,value3);
          value_set(p,(position-1),(value1+value2));
          empty_your_cols_right_left(position,5);
      }
      else {
          value_set (p,position,value3);
          value_set (p,(position-1),value2);
          value_set (p,(position-2),value1);
          empty_your_cols_right_left(position,4);
      }
    }// om vi har 3 värde

    if (number == 4){
      int value1=0,value2=0,value3=0,value4=0;
      int *value_1= &value1; int *value_2=&value2; int *value_3=&value3;
      int *value_4 = &value4;
      find_values (value_1,value_2,value_3,value_4,4,i,2);

      if (value1==value2 && value3==value4){
        value_set (p,position,(value3+value4));
        value_set (p,(position-1),(value1+value2));
        empty_your_cols_right_left(position,5);
      }
      else if (value1==value2){
        value_set(p,position,value4);
        value_set(p,(position-1),value3);
        value_set(p,(position-2),(value1+value2));
        empty_your_cols_right_left(position,4);
      }
      if (value3 == value4){
        value_set(p,position,(value3+value4));
        value_set(p,(position-1),value2);
        value_set(p,(position-2),value1);
        empty_your_cols_right_left(position,4);
      }

      else if (value2==value3){
        value_set(p,position,value4);
        value_set(p,(position-1),(value2+value3));
        value_set(p,(position-2),value1);
        empty_your_cols_right_left(position,4);
      }
    }// om vi har 4 värde.
    position += 4;
  }
}

void game_slide_left(void){
  int position = 0;
  for (int i = 0; i < 4 ; i++){
    int number=get_quantity_numbers(i,1);

    if (number==1){
      int value=0;
      int *value1 = &value;
      find_values(value1,0,0,0,1,i,2);
      value_set (p,position,value);
      empty_your_cols_right_left(position,3);
    } // om vi har 1 värde

    if(number == 2){
      int value1 = 0, value2 = 0;
      int *value_1 = &value1; int *value_2 = &value2;
      find_values (value_1,value_2,0,0,2,i,2);
      if (value1 == value2){
        value_set(p,position,(value1+value2));
        empty_your_cols_right_left(position,3);
      }
      else{
          value_set (p,position,value1);
          value_set (p,(position+1),value2);
          empty_your_cols_right_left(position,2);
      }
    }// om vi har 2 värde

    if(number == 3){
      int value1 = 0, value2 = 0, value3 = 0;
      int *value_1= &value1; int *value_2=&value2; int *value_3=&value3;
      find_values (value_1,value_2,value_3,0,3,i,2);

      if (value1 == value2){
          value_set(p,position,(value1+value2));
          value_set(p,(position+1),value3);
          empty_your_cols_right_left(position,2);
      }
      else if (value2 == value3){
        value_set (p,position,value1);
        value_set (p,(position+1),(value2+value3));
        empty_your_cols_right_left(position,2);
      }
      else {
          value_set (p,position,value1);
          value_set (p,(position+1),value2);
          value_set (p,(position+2),value3);
          empty_your_cols_right_left(position,1);
      }
    }// om vi har 3 värde

    if (number == 4){
      int value1=0,value2=0,value3=0,value4=0;
      int *value_1= &value1; int *value_2=&value2; int *value_3=&value3;
      int *value_4 = &value4;
      find_values (value_1,value_2,value_3,value_4,4,i,2);

      if (value1==value2 && value3==value4){
        value_set (p,position,(value1+value2));
        value_set (p,(position+1),(value3+value4));
        empty_your_cols_right_left(position,2);
      }
      else if (value1==value2){
        value_set(p,position,(value1+value2));
        value_set(p,(position+1),value3);
        value_set(p,(position+2),value4);
        empty_your_cols_right_left(position,1);
      }
      else if (value2==value3){
        value_set(p,position,value1);
        value_set(p,(position+1),(value2+value3));
        value_set(p,(position+2),value4);
        empty_your_cols_right_left(position,1);
      }
      if (value3 == value4){
        value_set(p,position,value1);
        value_set(p,(position+1),value2);
        value_set(p,(position+2),(value3+value4));
        empty_your_cols_right_left(position,1);
      }
    }// om vi har 4 värde.
    position += 4;
  }
}

void array_empty(Array *arr, int index){
  *(arr->data+index)=0;}

bool game_is_game_over(void){
  if (is_full() == false){
    return false;
  }
  else {
    return true;
  }
}

bool search_neighbour (void){
  int pos1=4, pos2=8;
  if (is_full()==false){
    return true;
  }
  while (pos1<8){
    if(*(p->data+pos1) == *(p->data+(pos1-4))){
      return true;
    }
    if(*(p->data+pos1) == *(p->data+(pos1+4))){
      return true;
    }
    pos1++;
  }
  while (pos2<12){
      if (*(p->data+pos2) == *(p->data+(pos2+4))){
        return true;
      }
      pos2++;
  }
  for(int i = 1; i < 14; i+=4){
    if (*(p->data+i) == *(p->data+(i-1))){
      return true;
    }
    if(*(p->data+i) == *(p->data+(i+1))){
      return true;
    }
  }
  for ( int j = 2; j < 15 ; j+=4){
    if(*(p->data+j) == *(p->data+(j+1))){
      return true;
    }
  }
  return false;
}

bool is_full (void){
  for(int i = 0; i < 4; i++){
    for(int j = 0; j < 4; j++){
      if (game_get_square(i,j) == 0){
        return false;
      }
    }
  }
  return true;
}
