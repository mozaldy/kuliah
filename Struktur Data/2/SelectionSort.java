import java.util.Arrays;
import java.util.concurrent.ThreadLocalRandom;

public class SelectionSort{
    public static void main(String[] args){
        SelectionSort sort = new SelectionSort();

        int[] data = new int[20];
        for (int i = 0; i < data.length; i++) {
            data[i] = ThreadLocalRandom.current().nextInt(0, 100);
        }

        System.out.println("Old Data: " + Arrays.toString(data));

        int[] newdata = sort.selectionSortAsc(data);

        System.out.println("New Data: " + Arrays.toString(newdata));
    }
    
    int[] selectionSortAsc(int[] data){
        for (int i = 0; i < data.length - 1; i++){
            int minIndex = i;
            for (int j = i + 1; j < data.length; j++){
                if (data[j] < data[minIndex]){
                    minIndex = j;
                }
            }
            int temp = data[i];
            data[i] = data[minIndex];
            data[minIndex] = temp;
        }
        return data;
    }
}
