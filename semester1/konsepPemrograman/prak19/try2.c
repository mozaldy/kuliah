#include <stdio.h>

void main()
{
    int data_mahasiswa[4][4] = {
        {1, 81, 90, 62},
        {2, 50, 83, 87},
        {3, 85, 50, 52},
        {4, 85, 60, 62},
    };
    printf("No. Mahasiswa\tRata-rata"); //heading
    for (int i = 0; i < 4; i++) 
    {
        int total = 0;  
        printf("\n");
        printf("%d", data_mahasiswa[i][0]);
        for (int j = 1; j < 4; j++){
            
            total += data_mahasiswa[i][j];
        }
        printf("\t\t%.2f", total / 3.0);
    }
    printf("\n");
}