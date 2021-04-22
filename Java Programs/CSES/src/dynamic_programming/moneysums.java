package dynamic_programming;


import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class moneysums {
    public static void main(String[] args){
        Scanner s=new Scanner(System.in);
        int a=s.nextInt();
        s.nextLine();
        String[] l=s.nextLine().split(" ");
        int[] list=new int[a];
        for (int i=0;i<a;i++){
            list[i]=Integer.parseInt(l[i]);
        }
        boolean[][] dp=new boolean[a+1][1000*a+1];
        dp[0][0]=true;
        for (int i=1;i<=a;i++){
            for (int j=0;j<=1000*a;j++){
                dp[i][j]=dp[i-1][j];
                int x=j-list[i-1];
                if (x>=0 && dp[i-1][x]){
                    dp[i][j]=true;
                }
            }
        }
        int count=0;
        ArrayList<Integer> out=new ArrayList<Integer>();
        for (int i=0;i<dp[a].length;i++){
            if (dp[a][i] && i!=0){
                count++;
                out.add(i);
            }
        }
        Collections.sort(out);
        System.out.println(count);
        for (int i:out){
            if (i!=0) {
                System.out.print(i + " ");
            }
        }

    }
}
