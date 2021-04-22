package dynamic_programming;

import java.util.Scanner;

public class removeDigits {
    static int[] dp;
    static int c=0;
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int a=s.nextInt();
        dp=new int[a+1];
        for (int i=1;i<10 && i<a+1;i++){
            dp[i]=1;
        }
        dp[0]=0;
        for (int i=10;i<=a;i++){
            dp[i]=find(i);
        }
        System.out.println(dp[a]);
    }
    public static int find(int i){
        int min=-1;
        c=i;
        while (c>0){
            if (c%10!=0) {
                if (min == -1) {
                    min = dp[i - c % 10] + 1;
                } else {
                    min = Math.min(min, dp[i - c % 10] + 1);
                }
            }
            c=c/10;
        }
        return min;
    }
}
