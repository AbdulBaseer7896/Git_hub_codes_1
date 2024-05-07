public class Selection_sort {
    public static void main(String[] args) {
        int[] array = {3,2,6,7,8,9,1,4,5,10};


        for(int i=0; i<10-1; i++)
        {
            int small = i;
            for(int j=i+1; j<10 ; j++)
            {
                if(array[j]<array[small])
                {
                   small = j;
                }
            }
            int temp = array[i];
            array[i] = array[small];
            array[small] = temp;
        }


        for(int i=0; i<10; i++)
        {
            System.out.println(array[i]);
        }
    }
}
