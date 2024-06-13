//
// Created by lamarwells on 6/12/2024.
// Both functions are global
#include <stdio.h>

// Global variable
int globalVar = 10;

void function1() {
    printf("Global variable inside function1: %d\n", globalVar);
}

void function2() {
    printf("Global variable inside function2: %d\n", globalVar);
}

int main() {
    printf("Global variable in main: %d\n", globalVar);
    function1();
    function2();
    return 0;
}
