public class quick_sort {
    public static void main(String[] args) {
        int[] array = {5,4,3,1,2,9,7,6,8,10};
        
        int low = 0;
        int high = 10;
        
        int pivit;
        int num1=0;
        int num2=0;
        int temp=0;
        // for(int i=low; i<10; i++)
        // {
            
        //     pivit = array[i];
            for (int i = high; i < array.length; i++) 
            {
                if(array[i]>pivit)
                {
                    num1 = array[i];
                }

                if(array[i]<pivit)
                {
                    num2 = array[i];
                }
            }
            temp = array[num1];
            array[num1] = array[num2];
            array[num2] = temp;
            

        for(int i=0; i<10; i++)
        {
            System.out.print(array[i]);
        }
        }
    }
    

