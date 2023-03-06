import java.util.Arrays;
import java.util.concurrent.ThreadLocalRandom;

class Main{
    static int counter = 0;
    public static void main(String[] args){
        int[] data1 = new int[100];
        int[] data2 = new int[100];
        for (int i = 0; i < data1.length; i++) {
            data1[i] = ThreadLocalRandom.current().nextInt(0, 100);
            data2[i] = ThreadLocalRandom.current().nextInt(0, 100);
        }
        int n = data1.length; 
        quickSort(data1, 0, n - 1);
    }
    static void quickSort(int arr[], int begin, int end) {
        if (begin < end) {
            int partitionIndex = partition(arr, begin, end);
    
            quickSort(arr, begin, partitionIndex-1);
            quickSort(arr, partitionIndex+1, end);
        }
    }
    static int partition(int arr[], int begin, int end) {
        int pivot = arr[end];
        int i = (begin-1);
    
        for (int j = begin; j < end; j++) {
            if (arr[j] <= pivot) {
                i++;
                
                int swapTemp = arr[i];
                arr[i] = arr[j];
                arr[j] = swapTemp;
                System.out.println("Proses ke-" + counter + ": " + Arrays.toString(arr));
                counter++;
            }
        }
    
        int swapTemp = arr[i+1];
        arr[i+1] = arr[end];
        arr[end] = swapTemp;
    
        return i+1;
    }
}