import java.util.Arrays;
import java.util.concurrent.ThreadLocalRandom;

public class bubbleSort{
    public static void main(String[] args){

        int[] data = new int[20];
        
        for (int i = 0; i < data.length; i++) {
            data[i] = ThreadLocalRandom.current().nextInt(0, 100);
        }

        System.out.println("Old Data: " + Arrays.toString(data));

        int[] newdata = bubbleSortDesc(data);

        System.out.println("New Data: " + Arrays.toString(newdata));

    }
    static int[] bubbleSortAsc(int arr[]){
        int n = arr.length;
        for (int i = 0; i < n - 1; i++)
            for (int j = 0; j < n - i - 1; j++)
                if (arr[j] > arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
        return arr;
    }
    static int[] bubbleSortDesc(int arr[]){
        int n = arr.length;
        for (int i = 0; i < n - 1; i++)
            for (int j = 0; j < n - i - 1; j++)
                if (arr[j] < arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
        return arr;
    }
}