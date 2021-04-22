package dynamic_programming;

import java.util.Scanner;

public class Tsets {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int a = s.nextInt();
        int m=1000000007;
        int sum=a*(a+1)/2;
        if (sum%2!=0){
            System.out.println(0);
        }
        else{
            sum=sum/2;
            long[][] dp=new long[a][sum+1];
            dp[0][0]=1;
            for (int i=1;i<a;i++){
                for (int j=0;j<=sum;j++){
                    dp[i][j]=dp[i-1][j];
                    int x=j-i;
                    if (x>=0){
                        dp[i][j]=dp[i-1][x]+dp[i][j];
                        dp[i][j]=dp[i][j]%m;
                    }
                }
            }
            System.out.println((dp[a-1][sum]%m+m)%m);
        }
    }
}
