package dynamic_programming;

import java.util.Scanner;

public class diceCombos {
    public static void main(String[] args){
        Scanner s=new Scanner(System.in);
        int a=s.nextInt();
        int[] list=new int[a+1];
        list[0]=1;
        for (int i=0;i<list.length;i++){
            for (int j=i-1;j>=i-6 && j>=0;j--){
                list[i]=((list[i]+list[j])%1000000007+1000000007)%1000000007;
            }
        }

        System.out.println(((list[list.length-1])%1000000007+1000000007)%1000000007);

    }
}
