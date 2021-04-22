package Educ_DP;

import java.util.Scanner;

public class C {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int a=s.nextInt();
        s.nextLine();
        int[][] dp=new int[a][3];
        for (int i=0;i<a;i++){
            String[] l=s.nextLine().split(" ");
            int[] list=new int[3];
            for (int j=0;j<3;j++){
                list[j]=Integer.parseInt(l[j]);

            }
            if (i==0){
                for (int j=0;j<3;j++){
                    dp[i][j]=list[j];
                }
            }
            else{
                for (int j=0;j<3;j++){
                    for (int k=0;k<3;k++){
                        if (j!=k){
                            dp[i][j]=Math.max(dp[i][j],dp[i-1][k]+list[j]);
                        }
                    }
                }
            }
        }
        int x=dp[dp.length-1][0];
        int y=Math.max(dp[dp.length-1][1],dp[dp.length-1][2]);
        System.out.println(Math.max(x,y));
    }
}
