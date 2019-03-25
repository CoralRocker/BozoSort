/**
 * @(#)BozoSort.java
 *
 *
 * @author 
 * @version 1.00 2019/2/8
 */

public class BozoSort {
        
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
    		int[] numbers = new int[7];
    		fill(numbers, 0, 100);
    		System.out.println(strArr(numbers));
    		for(int i = 1; i < 12; i++)
    		{
    			long numPass =0;
    			for(int x = 0; x < 5; x++)
    			{
    				int[] num = new int[i];
    				fill(num, 0, 100);
    				long t = sort(num);
    				System.out.printf("For Size %d, test %d, %,d passes\n", i, x, t);
    				numPass += t;
    			}
    			System.out.printf("For %d, AVG %,d passes\n\n", i, numPass/5);
    		}
    		System.out.printf("Bozo Sort Passes: %d\nSorted Array: %s\n", sort(numbers), strArr(numbers));
    
    }
    
    public static void fill(int[] nums, int min, int max)
    {
    	for(int i = 0; i < nums.length; i++)
    	{
    		nums[i] = (int)(Math.random() * (max-min) + min);
    	}
    }
    
    public static String strArr(int[] nums)
    {
    	String str = new String();
    	str = "[";
    	for(int i = 0; i < nums.length - 1; i++)
    	{
    		str += nums[i] + ", ";
    	}
    	str += nums[nums.length - 1] + "]";
    	return str;
    }
    
    public static long sort(int[] nums)
    {
    	long counter = 0;
    	while(!isInOrder(nums))
    	{
    		int t1 = (int)(Math.random() * nums.length), t2 = (int)(Math.random() * nums.length);
    		//System.out.printf("1: %d 2: %d\n", t1, t2);
    		int t3 = nums[t1];
    		nums[t1] = nums[t2];
    		nums[t2] = t3;
    		counter++;
    	}
    	return counter;
    }
    
    public static boolean isInOrder(int[] nums)
    {
    	if(nums.length <= 1)
    		return true;
    	for(int i = 1; i < nums.length; i++)
    	{
    		if(nums[i] < nums[i-1])
    			return false;
    	}
    	return true;
    }
}
