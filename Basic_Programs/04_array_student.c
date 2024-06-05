#include <stdio.h>

int main() {

    char *classes[3] = {"Math Class", "English Class", "Science Class"};


    int numbers[3][10] = {
            {2, 1, 2, 3, 4, 5, 6, 7, 7, 8},
            {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
            {11, 12, 13,14, 15, 16, 17, 18, 19, 20},

    };

    for (int i = 0; i < 10; ++i) {
        printf("\n---------- Student %d details ----------\n", i);
        int totalGrades = 0;
        float averageGrades = 0;
        for (int j = 0; j < 3; ++j) {
            int grades = numbers[j][i];
            printf("Student %d : grades in %s = %d\n", i + 1, classes[j], grades);
            totalGrades= totalGrades + grades;
        }
        averageGrades = (float)totalGrades / 3;
        printf("Student %d: total grades %d\n",i + 1, totalGrades);
        printf("Student %d: average grades %.2f\n", i + 1,  averageGrades);
    }
    return 0;
}

/*
        * `classes`: an array of character pointers that holds the names of the three classes.
        * `numbers`: a 2D array of integers that stores the marks for each student in each class.
3. **Main function**: The main function is where the program starts executing.
4. **For loop (outer)**: An outer for loop that iterates over the students ( indices `i` from 0 to 9).
5. **Inner for loop**: Inside the outer loop,  another for loop that iterates over each class (indices `j` from 0 to 2
2). For each student and class combination, you:
        * Print out a header with the student number and class name.
        * Calculate the total marks by summing up the individual marks in each class.
        * Calculate the average marks by dividing the total marks by the number of classes (3).
        * Print out the total and average marks for that student.*/