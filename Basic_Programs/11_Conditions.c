// If conditions exercise
// Created by lamarwells on 6/11/2024.
//

#include "11_Conditions.h"
#include <stdio.h>
void guessNumber(int guess){
    if (guess < 555){
        printf("You guessed is to low\n");

    }else if (guess > 555){
        printf("you guessed is to high\n");
    }
    else if (guess == 555){
        printf("Correct you guessed it!\n");

    }
}
int main(){
    guessNumber(500);
    guessNumber(600);
    guessNumber(555);

    return 0;
}
