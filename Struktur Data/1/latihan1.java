import java.util.Arrays;

public class latihan1 {
    public static void main(String[] args){
        int[] data = { 23, 6, 47, 35, 2, 14};
        int[] sorted = data;
        Arrays.sort(data);
        System.out.println("1. Urutan:" + sorted);
        System.out.println("2. Rata-rata:" + Arrays.stream(data).average().orElse(Double.NaN));
        System.out.println("3. Min-Max:" + Arrays.stream(data).min().getAsInt() + Arrays.stream(data).max().getAsInt());
        System.out.println("4. Ganjil:");
        System.out.println("5. Prima:");
    }
    void urutan(int[] data){

    }
}
