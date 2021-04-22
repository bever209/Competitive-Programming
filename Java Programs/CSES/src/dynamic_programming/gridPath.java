package dynamic_programming;

import java.util.Scanner;

public class gridPath {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int mod=1000000007;
        int a=s.nextInt();
        s.nextLine();
        String[] list=new String[a];
        for (int i=0;i<a;i++){
            list[i]=s.nextLine();
        }
        int[][] dp=new int[a][a];
        if (list[0].charAt(0) == '*'){
            System.out.println(0);
        }
        else{
            dp[0][0]=1;
            for (int i=1;i<a;i++){
                if (list[0].charAt(i) == '.'){
                    dp[0][i]=dp[0][i-1];
                }
                else{
                    dp[0][i]=0;
                }
            }
            for (int i=1;i<a;i++){
                for (int j=0;j<a;j++){
                    if (list[i].charAt(j)=='*'){
                        dp[i][j]=0;
                    }
                    else{
                        if (j==0){
                            dp[i][j]=dp[i-1][j];
                        }
                        else {
                            dp[i][j] = ((dp[i - 1][j] + dp[i][j - 1])%mod+mod)%mod;
                        }
                    }
                }
            }
            System.out.println(dp[a-1][a-1]);
        }

    }
}
