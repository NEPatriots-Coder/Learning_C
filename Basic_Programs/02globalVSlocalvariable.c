//
// Created by lamarwells on 6/12/2024.
//
#include <stdio.h>

// Global variable
int globalVar = 10;

void function1() {
    // Local variable inside function1
    int localVar1 = 20;
    printf("Local variable inside function1: %d\n", localVar1);
}

void function2() {
    // Local variable inside function2
    int localVar2 = 30;
    printf("Local variable inside function2: %d\n", localVar2);
}

int main() {
    printf("Global variable in main: %d\n", globalVar);
    function1();
    function2();
    return 0;
}

//local variables are accessible only within the function where they are declared,
// while global variables can be accessed by any function in the same file (or in multiple files if declared with extern).
//Global variables provide a way for functions to communicate with each other when necessary,
// but they can also lead to potential issues like unintended modification or coupling between different parts of the program.
// That's why it's generally recommended to use local variables whenever possible,
// as it promotes encapsulation and modularization of code.