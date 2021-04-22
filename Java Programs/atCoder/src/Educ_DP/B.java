package Educ_DP;

import java.util.Arrays;
import java.util.Scanner;

public class B {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        String[] l=s.nextLine().split(" ");
        int num=Integer.parseInt(l[0]);
        int max=Integer.parseInt(l[1]);

        int[] list=new int[num];
        String[] t=s.nextLine().split(" ");
        for (int i=0;i<list.length;i++){
            list[i]=Integer.parseInt(t[i]);
        }
        int[] dp=new int[num];
        Arrays.fill(dp,-1);
        dp[dp.length-1]=0;
        dp[dp.length-2]=dp[dp.length-1]+Math.abs(list[list.length-1]-list[list.length-2]);

        for (int i=dp.length-3;i>=0;i--){
            for (int j=max+i;j>i;j--){
                if (j<list.length){
                    int x=dp[j]+ Math.abs(list[i]-list[j]);
                    if (dp[i]==-1){
                        dp[i]=x;
                    }
                    dp[i]=Math.min(dp[i],x);
                }
            }
        }

        System.out.println(dp[0]);
    }
}
