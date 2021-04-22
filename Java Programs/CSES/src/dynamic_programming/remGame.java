package dynamic_programming;

import java.util.Scanner;

public class remGame {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int a = s.nextInt();
        s.nextLine();
        String[] l = s.nextLine().split(" ");
        int[] list = new int[a];
        for (int i = 0; i < a; i++) {
            list[i] = Integer.parseInt(l[i]);
        }

        long[][] dp=new long[a][a];
        long sum=0;
        for (int i=0;i<a;i++){
            dp[i][i]=list[i];
            sum=sum+list[i];
        }
        for (int j=a-1;j>=0;j--){
            for (int i=j+1;i<a;i++){
                if (j!=i){
                    dp[j][i]=Math.max(list[j]-dp[j+1][i],list[i]-dp[j][i-1]);
                }
            }
        }
        System.out.println((sum+dp[0][a-1])/2);

    }
}
