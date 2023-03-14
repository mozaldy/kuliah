public class Shell {
    public static <T extends Comparable<? super T>>void shellSort(T[] arr){
        int i, jarak;
        Boolean did_swap = true;
        T temp;
        jarak = arr.length;
        while (jarak > 1){
            jarak = jarak / 2;
            did_swap = true;
            while (did_swap){
                did_swap = false;
                i = 0;
                while (i < (arr.length - jarak)){
                    if(arr[i].compareTo(arr[i + jarak]) > 0){
                        temp = arr[i];
                        arr[i] = arr[i + jarak];
                        arr[i + jarak] = temp;
                        did_swap = true;
                    }
                    i++;
                }
            }
        }
    }
    public static <T> void tampil (T data[]){
        for (T objek : data){
            System.out.print(objek + " ");
        }
        System.out.println();
    }
    public static void main(String[] args){
        Integer data[] = new Integer[10];
        for (int a = 0; a < data.length; a++){
            data[a] = (int)(Math.random() * 13 + 1);
        }
        long awal = System.currentTimeMillis();
        shellSort(data);
        long sisaWaktu = System.currentTimeMillis() - awal;
        tampil(data);
        System.out.println("Waktu: " + sisaWaktu);
    }
}
