import java.util.Arrays;
import java.util.concurrent.ThreadLocalRandom;
class Main{
    public static void main(String[] args){
        int[] data1 = new int[100];
        int[] data2 = new int[100];
        for (int i = 0; i < data1.length; i++) {
            data1[i] = ThreadLocalRandom.current().nextInt(0, 100);
            data2[i] = ThreadLocalRandom.current().nextInt(0, 100);
        }
        insert(data1);
        // binary(data2);
        
    }
    static void insert(int[] data){
        System.out.println("insert Sorting:");
        for (int i = 1; i < data.length; i++){
            int key = data[i];
            int j = i - 1;
            
            while (j >= 0 && data[j] < key){
                data[j + 1] = data[j];
                j = j - 1;
            }
            data[j + 1] = key;
            System.out.print("Proses ke-" + i + ": ");
            System.out.println(Arrays.toString(data));
        }
    }
    static void binary(int[] data){
        int counter = 1;
        System.out.println("\nBinary Sorting:");
        for (int i = 0; i < data.length; i++){
            for (int j = 0; j < data.length - 1; j++)
                if (data[j] > data[j + 1]){
                    int temp = data[j];
                    data[j] = data[j + 1];
                    data[j + 1] = temp;
                    counter++;
                    System.out.print("Proses ke-" + counter + ": ");
                    System.out.println(Arrays.toString(data));
                }
        }
    }
}