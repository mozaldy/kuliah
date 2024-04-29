#include <stdio.h>

#define MAX 10

int pertukaran = 0, perbandingan = 0;

int selection(int *);

int print_array(int *);
void input_array(int *, int);
void swap(int *, int *);

int main(int argc, char *argv[])
{
  int array[MAX], size;
  printf("Size of array: ");
  scanf("%d", &size);
  input_array(array, size);
  printf("array inisial: ");
  print_array(array);
  selection(array);
  printf("array akhir: ");
  print_array(array);
  printf("Perbandingan: %d, Pertukaran: %d\n", perbandingan, pertukaran);
  return 0;
}

void input_array(int *arr, int size)
{
  for (int i = 0; i < size; i++)
  {
    printf("Value ke-%d: ", i);
    scanf("%d", &arr[i]);
  }
}

int selection(int *arr)
{
  for (int i = 0; i < MAX; i++)
  {
    int temp, min = i;
    printf("Iterasi ke-%d: ", i);
    print_array(arr);
    for (int j = i + 1; j < MAX; j++)
    {
      perbandingan++;
      if (arr[j] < arr[min])
        min = j;
    }
    pertukaran++;
    swap(&arr[i], &arr[min]);
  }
  return 0;
}

int print_array(int *arr)
{
  for (int i = 0; i < MAX; i++)
    printf("%d ", arr[i]);
  printf("\n");
  return 0;
}

void swap(int *x, int *y)
{
  int temp = *x;
  *x = *y;
  *y = temp;
}