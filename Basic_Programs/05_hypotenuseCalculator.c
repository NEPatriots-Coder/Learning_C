#include <stdio.h>
#include <math.h>

int main() {
    double A;
    double B;
    double C;

    printf("Enter side A: ");
    scanf("%lf", &A); // &A is the address of variable A

    printf("Enter side B: ");
    scanf("%lf", &B); // &B is the address of variable B

    C = sqrt(A * A + B * B); // Calculate the hypotenuse

    printf("The hypotenuse is: %lf\n", C); // Display the result

    return 0;
}
