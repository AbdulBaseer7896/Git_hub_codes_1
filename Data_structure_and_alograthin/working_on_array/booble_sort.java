public class booble_sort {
    public static void main(String[] args) {
        int[] array = new int[10];
       int  k =9;
        for(int i=9; i>=0; i--)
        {
            array[k]=i;
            k--;
        }
int hello= 0;

        for(int i=0; i<9; i++)
        {
            System.out.println("This array is sorted in "+ i + " steps;");
            hello =1;
            for(int j=0; j<10-i-1; j++)
            {
                if(array[j]>array[j+1])
                {
                    int temp = array[j];
                    array[j] = array[j+1];
                    array[j+1] = temp;
                    hello = 0;
                }
               
            }
            if(hello==1)
            {
                break;
            }
        }

        for(int i=0; i<10; i++)
        {
            System.out.print(array[i]);;
        }
    }
}
