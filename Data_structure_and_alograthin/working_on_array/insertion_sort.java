public class insertion_sort {

    public static void main(String[] args) {
        int[] array = new int[10];
int j=0;
        for(int i=9; i>=0; i--)
        {
            array[j] = i;
            j++;
        }
        int key, k;
        for(int i=1; i<10-1; i++)
        {
            key = array[i];
            k=i-1; 
            while(k>=0 && array[k]>key)
            {
                array[k+1] =array[k];
                k--;
            }
            array[k+1]=key; 
        }

        for(int i=0; i<10; i++)
        {
            System.out.println(array[i]);
        }
    }
    
}
