package year_2015_2016;

import java.io.*;
import java.util.*;

public class b_Feb_2 {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new FileReader("C:\\Users\\User\\Documents\\Programs\\java_programs\\usaco\\src\\year_2015_2016\\cbarn.in"));
        int a = Integer.parseInt(in.readLine());
        int[] list = new int[a];
        for (int i=0;i<a;i++){
            list[i]=Integer.parseInt(in.readLine());
        }
        ArrayList<Integer> total = new ArrayList<Integer>();
        for (int i=0;i<list.length;i++){
            total.add(compute(list,i));
        }
       BufferedWriter out = new BufferedWriter(new FileWriter("cbarn.out"));
        out.write(Integer.toString(Collections.min(total)));
        out.close();
    }
    public static int compute(int[] list,int ind){
        int sum=0;

        for (int i=0;i<list.length;i++){
                if (i<ind){
                sum=sum+list[i]*(i-ind+list.length);}
                else{
                    sum=sum+list[i]*(i-ind);
                }
        }
        return sum;
    }
}
