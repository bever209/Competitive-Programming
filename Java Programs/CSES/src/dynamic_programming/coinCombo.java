package dynamic_programming;
///GIVES RUNTIME BUT I THINK IT IS BECAUSE IT IS JAVA
import java.util.Scanner;

public class coinCombo {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        String[] info = s.nextLine().split(" ");
        int a=Integer.parseInt(info[0]);
        int sum = Integer.parseInt(info[1]);
        String[] l = s.nextLine().split(" ");
        int[] list = new int[l.length];
        for (int i = 0; i < list.length; i++) {
            list[i] = Integer.parseInt(l[i]);
        }
        long[][] dp = new long[a + 1][sum+1];
        dp[0][0]=1;

        for (int i = 1; i <= a; i++) {
            for (int j = 0; j <= sum; j++) {
                dp[i][j] = dp[i-1][j]+dp[i][j];
                int left = j-list[i-1];
                if (left >= 0) {
                    dp[i][j]=dp[i][left]+dp[i][j];

                }
            }
        }
        System.out.println(((dp[a][sum]%1000000007)+1000000007)%1000000007);


    }
}
