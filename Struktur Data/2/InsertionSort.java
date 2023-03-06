import java.util.Arrays;
import java.util.concurrent.ThreadLocalRandom;

public class InsertionSort{
    public static void main(String[] args){
        InsertionSort sort = new InsertionSort();

        int[] data = new int[20];
        for (int i = 0; i < data.length; i++) {
            data[i] = ThreadLocalRandom.current().nextInt(0, 100);
        }

        System.out.println("Old Data: " + Arrays.toString(data));

        int[] newdata = sort.insertionSortDesc(data);

        System.out.println("New Data: " + Arrays.toString(newdata));

    }
    int[] insertionSortAsc(int[] data){
        for (int i = 1; i < data.length; i++){
            int key = data[i];
            int j = i - 1;
            
            while (j >= 0 && data[j] > key){
                data[j + 1] = data[j];
                j = j - 1;
            }
            data[j + 1] = key;            
        }
        return data;
    }
    int[] insertionSortDesc(int[] data){
        for (int i = 1; i < data.length; i++){
            int key = data[i];
            int j = i - 1;
            
            while (j >= 0 && data[j] < key){
                data[j + 1] = data[j];
                j = j - 1;
            }
            data[j + 1] = key;            
        }
        return data;
    }
}