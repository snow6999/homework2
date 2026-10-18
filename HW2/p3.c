/* CS100 Fall 2026 - HW2 Problem 3: Polynomial evaluation
 *
 * Evaluate P(x) at m given points; print each value rounded to 3 decimals.
 * An array is enough for the coefficients; do not use heap memory and do
 * not use <math.h> (your program is not linked against the math library).
 * Do not rename this file.
 */
#include <stdio.h>

int main(void)
{
    int n;
    scanf("%d",&n);
    double arr[31];
    for (int i=0;i<n+1;i++){
        scanf("%lf",arr+i);
    }
    int round;
    scanf("%d",&round);
    for (int i=0;i<round;i++){
        int x;
        double sum = 0.0;
        scanf("%d",&x);
        for (int j=0;j<n+1;j++){
            sum=sum*x+arr[n-j];
        }
        printf("%.3f\n", sum);
    }
    return 0;
}
