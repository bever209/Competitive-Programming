package Educ_DP;

import java.util.Scanner;

public class H {
    public static void main(String[] args) {
        int m=1000000007;
        Scanner s = new Scanner(System.in);
        String[] l = s.nextLine().split(" ");
        int row = Integer.parseInt(l[0]);
        int col = Integer.parseInt(l[1]);
        String[] list=new String[row];
        for (int i=0;i<row;i++){
            list[i]=s.nextLine();
        }
        long[][] dp=new long[row][col];
        if (list[0].charAt(0)=='.'){
            dp[0][0]=1;
        }
        for (int i=0;i<row;i++){
            for (int j=0;j<col;j++){
                if (i!=0 || j!=0){
                    if (list[i].charAt(j)=='#'){
                        dp[i][j]=0;
                    }
                    else{
                        if (j==0){
                            dp[i][j]=dp[i-1][j]%m;
                        }
                        else if (i==0){
                            dp[i][j]=dp[i][j-1]%m;
                        }
                        else{
                            dp[i][j]=(dp[i-1][j]+dp[i][j-1])%m;
                        }
                    }
                }
            }
        }
        System.out.println((((dp[row-1][col-1])%m)+m)%m);





    }
}
