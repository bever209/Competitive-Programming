package dynamic_programming;

import java.util.Scanner;

public class coinComb {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        String[] info = s.nextLine().split(" ");
        int sum = Integer.parseInt(info[1]);
        String[] l = s.nextLine().split(" ");
        int[] list = new int[l.length];
        for (int i = 0; i < list.length; i++) {
            list[i] = Integer.parseInt(l[i]);
        }
        long[] dp=new long[sum+1];
        dp[0]=1;
        for (int j=1;j<dp.length;j++){
            for (int i:list){
                if (j-i>=0){
                    dp[j]=((dp[j]+dp[j-i]%1000000007)+1000000007)%1000000007;
                }
            }
        }
        System.out.println(((dp[dp.length-1]%1000000007)+1000000007)%1000000007);
    }
}
