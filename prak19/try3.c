#include <stdio.h>
#include <math.h>

#define PI 3.15269

float radian(int);

void main()
{
    float data[999][999];
    int x[999] = {0, 30, 60, 90, 120, 150, 180, 210, 240, 270, 300, 330, 360};
    int len = sizeof(x) / sizeof(x[0]);
    for (size_t i = 0; i < 13; i++)
    {
        int n1 = radian(x[0]);
        int n2 = radian(x[1]);
        int n3 = radian(x[2]);
        data[i][0] = sin(n1);
        data[i][1] = cos(n2);
        data[i][2] = tan(n3);
    }
    for (size_t i = 0; i < 13; i++)
    {
        printf("%d\t", x[i]);
        for (size_t j = 0; j < 3; j++)
        {
            printf("%f\t", data[i][j]);
        }
        printf("\n");
    }
}

float radian(int derajat)
{
    return derajat / 180.0 * PI;
}