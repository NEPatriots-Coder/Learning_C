//
// Created by lamarwells on 6/11/2024.
//
#include <stdio.h>
int counter = 0; //Global Variable

void incrementCounter() {
    counter++;
}

void printCounter() {
    printf("%d", counter);
}

int main() {
    incrementCounter();
    printCounter();

    return 0;
}