#include <stdio.h>

int count;

int input(int array[]);
int find_max(int array[]);
void main()
{
    int array[50];
    input(array);
    printf("Angka tertinggi dari array adalah %d", find_max(array));
}

int input(int array[])
{
    int value;
    printf("Berapa data yang ingin di input: ");
    scanf("%d", &count);
    array[count];
    for (int i = 0; i < count; i++)
    {
        printf("Input value ke-%d: ", i + 1);
        scanf("%d", &array[i]);
    }
    return count;
}
int find_max(int array[])
{
    for (int i = 0; i < count - 1; i++)
    {

        for (int j = 0; j < count - i - 1; j++)
        {
            if (array[j] < array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
    return array[0];
}