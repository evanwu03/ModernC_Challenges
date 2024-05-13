
#include <stdio.h> 

double num_derivative(double x); 

int main() {  
    double x; 
    printf("This program calculates the derivative of x^2 given a value\n");
    printf("Enter a value x: "); 
    scanf("%lf", &x); 
    printf("x = %lf\n", x); 
    printf("f(x) = %lf\n", x*x ); 
    printf("f'(x) = %lf", num_derivative(x));
    return 0;
}

// takes the derivative of x^2 using the different quotient
// of a function 
double num_derivative(const double x)  {
    double f = x*x; 
    double h = 0.001; // Choose a arbitrarilly small number for  
    return ((x+h)*(x+h) - f)/h;  
}