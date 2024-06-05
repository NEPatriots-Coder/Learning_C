/*C Program to input 2-D array of size 3*5*/
#include <stdio.h> // Include the standard input-output library

int main() {
    int a[3][5]; // Declare a 2D array with 3 rows and 5 columns
    int i, j;    // Declare loop variables

    // Prompt user to enter the elements of the array
    printf("Enter the Elements:\n");
    for (i = 0; i <= 2; i++) { // Loop through each row
        for (j = 0; j <= 4; j++) { // Loop through each column in the current row
            // Read an integer value from the user and store it in a[i][j]
            scanf("%d", &a[i][j]);
        }
    }

    // Display the elements of the array
    printf("Elements are : \n");
    for (i = 0; i <= 2; i++) { // Loop through each row
        for (j = 0; j <= 4; j++) { // Loop through each column in the current row
            // Print the value stored in a[i][j]
            printf("%d\t", a[i][j]);
        }
        printf("\n"); // Print a newline after each row
    }

    return 0; // Indicate that the program ended successfully
}

