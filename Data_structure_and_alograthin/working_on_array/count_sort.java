
// import java.util.Collections;
import java.util.Arrays;
public class count_sort {
    public static void main(String[] args) {
        int[] array = {1,6,9,6,1,9,7,8,10,3};
        int max = Arrays.stream(array).max().getAsInt();
        System.out.println(max);
    //    int  maxs = Collections.max(Arrays.asList(array));
        int[] counting_array = new int[max+1];
        for(int i=0; i<max+1; i++)
        {
            counting_array[i]=0;
        }

        for(int i=0; i<10; i++)
        {
            counting_array[array[i]] = counting_array[array[i]] + 1;
        }

        int j =0;
         int i =0;
        while(i<=max)
        {
            if(counting_array[i]>0)
            {
                array[j] = i;
                counting_array[i]=counting_array[i]-1;
                j++;
            }
            else{
                i++;
            }
        }


        for(int k=0; k<10; k++)
        {
            System.out.print(" "+ array[k]);
        }
    }
}
