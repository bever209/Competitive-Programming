package Template;

import java.util.*;

public class Next_permutation {

    public static void main(String[] args){
        /*int[] arr=new int[5];           TESTING
        arr[0]=2;
        arr[1]=4;
        arr[2]=5;
        arr[3]=1;
        arr[4]=3;
        System.out.println(Arrays.toString(nextPermutation(arr)));*/
    }


    public static int[] nextPermutation(int[] nums) {
        //find first decreasing digit
        int mark = -1;
        for (int i = nums.length - 1; i > 0; i--) {
            if (nums[i] > nums[i - 1]) {
                mark = i - 1;
                break;
            }
        }

        if (mark == -1) {
            return nums; //BEWARE THAT THIS IS THE FINAL LEXICOGRAPHIC ARRAY
        }

        int idx = nums.length-1;
        for (int i = nums.length-1; i >= mark+1; i--) {
            if (nums[i] > nums[mark]) {
                idx = i;
                break;
            }
        }

        nums=swap(nums, mark, idx);

        nums=reverse(nums, mark + 1, nums.length - 1);
        return nums;
    }

    public static int[] swap(int[] nums, int i, int j) {
        int t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
        return nums;
    }

    public static int[]  reverse(int[] nums, int i, int j) {
        while (i < j) {
            swap(nums, i, j);
            i++;
            j--;
        }
        return nums;
    }
}
