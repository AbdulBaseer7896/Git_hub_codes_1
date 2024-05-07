import java.util.Scanner;
class deleat{
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        int[] array = new int[10];
        for(int i=0; i<8; i++)
        {
            array[i]=i;
        }
        int num=5;
        System.out.print("Enter the number that you want you Deleate = ");
        // int num.cin;
        
        for(int i=num; i<8; i++)
        {
            array[i]=array[i+1];
        }
        cin.close();

        for(int i=0; i<8; i++)
        {
            System.out.println(array[i]);
        }
    }
}