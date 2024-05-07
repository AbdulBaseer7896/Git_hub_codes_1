// import java.nio.channels.SeekableByteChannel;

public class merge_array_in_sorting_order {
    public static void main(String[] args) {
        int[] first = {2,5,6,8,9};
        int[] secound = {1,2,4,7,8};
        int l1 = 5;
        int l2 = 5;
        int i=0;
        int j=0;
        int k=0;
        int[] array = new int[l1+l2];
        while(i<l1 && j<l2)
        {
            if(first[i]<secound[j])
            {
                array[k] = first[i];
                i++;
                k++;
            }
            else
            {
                array[k] = secound[j];
                j++;
                k++;
            }
        }
        
        while(i<j)
        {
            array[k]  = first[i];
            k++;
            i++;
        }

        while(j<i)
        {
            array[k] = secound[j];
            k++;
            j++;
        }

        for(i=0; i<10 ; i++)
        {
            System.out.print(" " + array[i]);
        }
    }
}
