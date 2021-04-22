package dynamic_programming;

import java.util.Scanner;

public class bookshop {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        String[] info=s.nextLine().split(" ");
        int a=Integer.parseInt(info[0]);
        int b=Integer.parseInt(info[1]);
        String[] l=s.nextLine().split(" ");
        int[] price = new int[l.length];
        for (int i=0;i<price.length;i++){
            price[i]=Integer.parseInt(l[i]);
        }
        l=s.nextLine().split(" ");
        int[] page = new int[l.length];
        for (int i=0;i<page.length;i++){
            page[i]=Integer.parseInt(l[i]);
        }
        int[][] dp=new int[a+1][b+1];

        for (int i=1;i<a+1;i++){
            for (int j=0;j<b+1;j++){
                dp[i][j]=dp[i-1][j];
                int c=j-price[i-1];
                if (c>=0){
                    dp[i][j]=Math.max(dp[i][j],dp[i-1][c]+page[i-1]);
                }
            }
        }

        System.out.println(dp[a][b]);
    }
}
