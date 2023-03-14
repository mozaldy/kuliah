public class BubbleDemo{
    public static void bubbleSort(int[] arr){
        int i = 1, j, n = arr.length;
        int temp;
        while (i < n){
            j = n - 1;
            while (j >= i){
                if (arr[j - 1] > arr[j]){
                    temp = arr[j];
                    arr[j] = arr[j - 1];
                    arr[j - 1] = temp;  
                }
                j = j - 1;
            }
            i++;
        }
    }
    public static void tampil(int data[]){
        for (int i = 0; i < data.length; i++){
            System.out.print(data[i] + " ");
        }
        System.out.println();
    }
    public static void main(String[] args){
        int a[] = {10, 4, 8, 3, 11};
        System.out.print("Array lama: ");
        tampil(a);
        bubbleSort(a);
        System.out.print("Array baru: ");
        tampil(a);
    }
}
