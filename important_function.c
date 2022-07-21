#include <stdio.h>
#include <math.h>


int main() {
    float x, y, c1, c2, c3;
    if (scanf("%f", &x) != 1) {
        printf("n/a");
    } else {
    c1 =  7e-3 * pow(x, 4);
    c2 = ((22.8 * pow(x, 1 / 3) - 1e3 * x + 3)) / (x * x / 2);
    c3 = x * (pow(10 + x, 2 / x));
    y = c1 + c2 - c3 - 1.01;
    printf("%.1f ", y);
    }
    return 0;
}
