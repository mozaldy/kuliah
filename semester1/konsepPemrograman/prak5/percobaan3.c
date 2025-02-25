#include <stdio.h>

void main()
{
    int pembelian; 
    printf("Inputkan angka: ");
    scanf("%d", &pembelian);
    if (pembelian >= 100000)
        pembelian = pembelian - (pembelian * 0.05);
    
    printf("Total pembelian adalah Rp. %d\n", pembelian);

}