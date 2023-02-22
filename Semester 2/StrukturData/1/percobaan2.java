import java.util.*;
public class percobaan2{
    public static void main(String[] args){
        int num[] = {50,20,45,82,25,63};
        int l = num.length;
        int i,j,t;
        System.out.print("Given number : ");
        for (i = 0;i < l;i++ ){
        System.out.print(" " + num[i]);
        }
        System.out.println("\n");
        System.out.print("Accending order number : ");
        Arrays.sort(num);
        for(i = 0;i < l;i++){
        System.out.print(" " + num[i]);
        }
    }
}