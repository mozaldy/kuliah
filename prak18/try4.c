#include <stdio.h>

#define MAX 50

int sortir(int data[]);

int n;

void main(){
    int data[MAX];
    printf("Berapa data yang ingin di input: ");
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++)
    {
        int input;
        printf("Input angka ke-%d: ", i);
        scanf("%d", &input);
        getchar();
        data[i] = input;
    }
    
    printf("Angka terbesar adalah %d\n", sortir(data));
}

int sortir(int data[]){
    int terbesar = data[0];
    for (int i = 0; i < n; i++)
    {
        if(data[i] > terbesar){
            terbesar = data[i];
        }
    }
    return terbesar;
    
}