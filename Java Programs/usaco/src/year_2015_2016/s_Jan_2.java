package year_2015_2016;

import java.io.*;

public class s_Jan_2 {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new FileReader("C:\\Users\\User\\Documents\\Programs\\java_programs\\usaco\\src\\year_2015_2016\\div7.in"));
        int a = Integer.parseInt(in.readLine());
        int[] list = new int[a];
        for (int i=0;i<a;i++){
            list[i]=((Integer.parseInt(in.readLine())%7)+7)%7;
        }
        int[] prefix = new int[a];
        int sum=0;
        for (int i=0;i<list.length;i++){
            sum=sum%7;
            sum=(sum+list[i])%7;
            prefix[i]=sum;
        }
        int max=0;
        for (int i=prefix.length-1;i>=0;i--){
            if (prefix[i]%7==0){
                max=i+1;
                break;
            }
        }

        for (int i=1;i<prefix.length;i++){
            if (max>=prefix.length-i){
                break;
            }
            for (int j=prefix.length-1;j>=i;j--){
                if (j-i+1<=max){
                    break;
                }
                else{
                    if (prefix[i-1]%7==prefix[j]%7){

                        max=Math.max(max,j-i+1);
                    }
                }
            }
        }
        in.close();
        BufferedWriter out = new BufferedWriter(new FileWriter("div7.out"));

        out.write(Integer.toString(max));
        out.close();
    }
}
