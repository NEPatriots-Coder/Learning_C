//
// Created by lamarwells on 6/7/2024.
//
#include <stdio.h>

int main(){
    int age;

    printf("\nEnter your age: ");
    scanf("%d", &age);

    if(age >= 18){
        printf("You are now signed up");
    }
    else{
        printf("Your are too young to sign up");
    }
    return 0;
}