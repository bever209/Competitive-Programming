package dynamic_programming;

import java.util.Scanner;

public class rectCut {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        String[] l=s.nextLine().split(" ");
        int a=Integer.parseInt(l[0]);
        int b=Integer.parseInt(l[1]);

        int[][] dp=new int[a+1][b+1];
        for (int i=1;i<a+1;i++){
            for (int j=1;j<b+1;j++){
                if (i==j){
                    dp[i][j]=0;
                }
                else{
                    for (int k=1;k<i/2 +1;k++){
                        if (dp[i][j]==0){
                            dp[i][j]=dp[k][j]+dp[i-k][j]+1;
                        }
                        dp[i][j]=Math.min(dp[i][j],1+dp[k][j]+dp[i-k][j]);
                    }
                    for (int k=1;k<j/2 +1;k++){
                        if (dp[i][j]==0){
                            dp[i][j]=dp[i][k]+dp[i][j-k]+1;
                        }
                        dp[i][j]=Math.min(dp[i][j],1+dp[i][k]+dp[i][j-k]);
                    }
                }
            }
        }

        System.out.println(dp[a][b]);
    }
}
