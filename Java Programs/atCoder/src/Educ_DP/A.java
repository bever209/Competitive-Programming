package Educ_DP;

import java.util.Scanner;

public class A {
    public static void main(String[] args){
        Scanner s=new Scanner(System.in);
        int a=s.nextInt();
        s.nextLine();
        String[]l=s.nextLine().split(" ");
        int[] list=new int[l.length];
        for (int i=0;i<list.length;i++){
            list[i]=Integer.parseInt(l[i]);
        }
        int[] dp=new int[list.length];
        dp[dp.length-1]=0;
        dp[dp.length-2]=Math.abs(list[list.length-1]-list[list.length-2]);
        for (int i=dp.length-3;i>=0;i--){
            dp[i]=Math.min(dp[i+2]+Math.abs(list[i]-list[i+2]),dp[i+1]+Math.abs(list[i]-list[i+1]));
        }
        System.out.println(dp[0]);
    }
}
