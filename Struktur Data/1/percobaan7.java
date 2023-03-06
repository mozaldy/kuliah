public class percobaan7{
    public static void main(String[] args) {
        int myArray[][] = { {1, 2 }, { 3 }, { 4, 5, 6 } };
        for ( int i = 0; i < myArray.length; i++ )
        {
            System.out.println("Row number " + i + " has " + myArray[i].length + "columns." );
        }//end for
        for ( int i = 0; i < myArray.length; i++ ) {
            for ( int j = 0; j< myArray[i].length; j++ ) {
                System.out.print(myArray[i][j]+"");
            }
            System.out.println("");
        }
    }
}
    