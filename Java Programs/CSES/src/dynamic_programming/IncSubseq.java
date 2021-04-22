package dynamic_programming;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;

public class IncSubseq {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int a = s.nextInt();
        s.nextLine();
        String[] l = s.nextLine().split(" ");
        int[] list = new int[a];
        for (int i = 0; i < a; i++) {
            list[i] = Integer.parseInt(l[i]);
        }
        ArrayList<Integer> dp=new ArrayList<Integer>();
        for (int i=0;i<list.length;i++){
            int x= Collections.binarySearch(dp,list[i]);
            if (x<0){
                x=-x-1;
            }

            if (x==dp.size()){
                dp.add(list[i]);
            }
            else{
                dp.set(x,list[i]);
            }
        }
        System.out.println(dp.size());

    }
}
