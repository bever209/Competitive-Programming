package year_2015_2016;

import java.io.*;

public class b_Feb_1 {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new FileReader("C:\\Users\\User\\Documents\\Programs\\java_programs\\usaco\\src\\year_2015_2016\\pails.in"));
        String[] l = br.readLine().split(" ");

        int[] list = new int[3];
        for (int i=0;i<3;i++){
            list[i]=Integer.parseInt(l[i]);
        }
        int m = list[2];
        int ans=0;
        for (int i=m;i>=0;i--){
            boolean check=false;
            int a = list[0];
            int count=0;
            while (count*a<=i){

                if ((i-count*a)%list[1]==0){
                    check=true;
                    ans=i;
                    break;
                }
                count++;
            }
            if (check){
                break;
            }
        }
        System.out.println(ans);
        BufferedWriter out = new BufferedWriter(new FileWriter("pails.out"));
        out.write(Integer.toString(ans));
        out.close();

    }
}
