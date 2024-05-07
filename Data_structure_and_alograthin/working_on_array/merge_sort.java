public class merge_sort {

   static void merge(int array[], int mid, int high , int low)
    {
        int i,j,k;
        int[] secound = new int[high-low+1];
        i = low;
        j=mid+1;
        k=low;  
        while(i<=low && j<=high)
        {
            if(array[i]<array[j])
            {
                secound[k] = array[i];
                i++;
                k++;
            }
            else
            {
                secound[k] = array[j];
                j++;
                k++;
            }
        }

        while(i<=mid)
        {
            secound[k] = array[i];
            i++;
            k++;    
        }
        while(j<=mid)
        {
            secound[k] = array[j];
            j++;
            k++;
        }

    for(i=low; i<=high; i++)
    {
        array[i]= secound[i];  
    }
    }



   static void merge_algorithm(int array[], int high, int low) 
    {
        int mid;
        if(low<high){
        mid = ((high + low)/2);
        merge_algorithm(array, mid +1, low);
        merge_algorithm(array, high, mid+1);
        merge(array, mid, high, low);
        }
    }
public static void main(String[] args) {
    int[] array = {1,2,4,7,8,2,5,6,8,9};
    int n= 10;

    int low, high, mid;
    low = 0;
    high = 10;
    
    mid = ((low+high)/2);
    merge(array, mid, high, low);
    merge_algorithm(array, high, low);


    
    for(int i=0; i<n; i++)
    {
        System.out.print(" " +array[i]);
    }

}
}
