package Educ_DP;

import java.util.Scanner;

public class K {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        String[] l=s.nextLine().split(" ");
        int num=Integer.parseInt(l[0]);
        int cap=Integer.parseInt(l[1]);

        String[] a=s.nextLine().split(" ");
        int[] list=new int[a.length];
        for (int i=0;i<list.length;i++){
            list[i]=Integer.parseInt(a[i]);
        }
        boolean[] dp=new boolean[cap+1];
        for (int i=0;i<=cap;i++){
            for (int j:list){
                if (i-j>=0 && !dp[i-j]){
                    dp[i]=true;
                }
            }
        }
        if (dp[cap]){
            System.out.println("First");
        }
        else{
            System.out.println("Second");
        }
    }
}
