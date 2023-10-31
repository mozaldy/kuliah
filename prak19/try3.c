#include <stdio.h>
#include <math.h>

#define PI 3.15269

float radian(int);

void main()
{
    float data[13][3];
    int x[13] = {0, 30, 60, 90, 120, 150, 180, 210, 240, 270, 300, 330, 360};
    
    for (int i = 0; i < 13; i++)
    {
        data[i][0] = sin(radian(x[i]));
        data[i][1] = cos(radian(x[i]));
        data[i][2] = tan(radian(x[i]));
    }
    for (int i = 0; i < 13; i++)
    {
        printf("%d\t", x[i]);
        for (int j = 0; j < 3; j++)
        {
            printf("%.1f\t", data[i][j]);
        }
        printf("\n");
    }
}

float radian(int derajat)
{
    return derajat / 180.0 * PI;
}