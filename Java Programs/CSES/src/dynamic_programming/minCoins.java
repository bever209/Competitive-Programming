package dynamic_programming;


import java.util.Arrays;
import java.util.Scanner;

public class minCoins {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        String[] info=s.nextLine().split(" ");
        int a=Integer.parseInt(info[0]);
        int sum=Integer.parseInt(info[1]);

        String[] l=s.nextLine().split(" ");
        int[] list=new int[l.length];
        for (int i=0;i<list.length;i++){
            list[i]=Integer.parseInt(l[i]);
        }
        int[] dp=new int[sum+1];
        Arrays.fill(dp,1000000000);
        dp[0]=0;

        for (int i = 1; i < dp.length; i++) {
            for (int j = 0; j < list.length; j++) {
                if (i-list[j] >= 0) {
                    dp[i] = Math.min(dp[i], dp[i-list[j]]+1);
                }
            }
        }
        if (dp[dp.length-1]==1000000000){
            System.out.println(-1);
        }
        else {
            System.out.println(dp[dp.length - 1]);
        }

    }
}
