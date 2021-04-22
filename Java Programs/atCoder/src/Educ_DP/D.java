package Educ_DP;

import java.util.Scanner;

public class D {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        String[] l=s.nextLine().split(" ");
        int num=Integer.parseInt(l[0]);
        int w=Integer.parseInt(l[1]);
        long[][] dp=new long[num+1][w+1];
        long[][] list=new long[num][2];
        for (int i=0;i<num;i++){
            String[] x=s.nextLine().split(" ");
            long[] a=new long[2];
            for (int j=0;j<2;j++){
                a[j]=Long.parseLong(x[j]);
            }
            list[i]=a.clone();
        }
        for (int i=0;i<w+1;i++){
            if (list[0][0]<=i){
                dp[1][i]=list[0][1];
            }
        }
        for (int i=2;i<num+1;i++){
            for (int j=1;j<w+1;j++){
                dp[i][j]=dp[i-1][j];
                int left=(int)(j-list[i-1][0]);
                if (left>=0){
                    dp[i][j]=Math.max(dp[i][j],dp[i-1][left]+list[i-1][1]);
                }
            }
        }
        System.out.println(dp[num][w]);



    }
}
