#include <stdio.h>
#include <math.h>

int main() {
    float hx = 2.0, hy =  2.5;
    float x0 = 1.0, x1 = 4.0;
    float y0 = 2.0, y1 = 5.0;
    float u1, u2;
    float xn, yn;
    double U;
        for (xn = x0; xn <=x1; xn += hx); {
            for (yn = y0; yn <=y1; yn += hy); {
                printf ("x = %f; y = %f; ", xn, yn);

                u1 = sin(xn)*sin(xn) + exp(3.0);
                u2 = log(fabs(xn + (yn*yn*yn)));
                if (fminf(u1, u2)< 1.0) {
                   U = 2.0 * pow(yn, xn);
                    printf ("U = %f\n", U);

                } else {
                       U = cbrt((xn * (yn * yn)) / (1 - tan(xn - (yn * yn))));
                     printf ("U = %f\n", U);
                  }
            }
        }
return 0;

