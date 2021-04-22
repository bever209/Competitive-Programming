package dynamic_programming;

import java.util.Scanner;

public class arraydesc {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        String[] info=s.nextLine().split(" ");
        int a=Integer.parseInt(info[0]);
        int b=Integer.parseInt(info[1]);
        int[] list=new int[a];
        String[] l=s.nextLine().split(" ");
        for (int i=0;i<l.length;i++){
            list[i]=Integer.parseInt(l[i]);
        }
        int mod=1000000007;
        long[][] dp=new long[a][b+1];
        for (int i=0;i<b+1;i++){
            if (list[0]==0 || list[0]==i){
                dp[0][i]=1;
            }
        }
        for (int i=1;i<a;i++){
            int c=list[i];
            if (c==0){
                for (int j = 1; j < b+1; j++) {
                    for (int k=j-1;k<=j+1;k++) {
                        if (k > 0 && k < b+1) {
                            dp[i][j]=(dp[i][j]+dp[i-1][k])%mod;
                        }
                    }
                }
            }
            else{
                for (int p=c-1;p<=c+1;p++){
                    if (p>0 && p<b+1){
                        dp[i][c]=(dp[i][c]+dp[i-1][p])%mod;
                    }
                }
            }
        }
        long sum=0;
        for (int i=1;i<=b;i++){
            sum=(sum+dp[a-1][i])%mod;
        }
        System.out.println((((sum%mod)+mod)%mod));


    }
}
