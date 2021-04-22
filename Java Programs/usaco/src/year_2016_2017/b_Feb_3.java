package year_2016_2017;

import java.io.*;
import java.util.Arrays;

public class b_Feb_3 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("cowqueue.in"));
        int t = Integer.parseInt(br.readLine());
        int[][] list = new int[t][];
        for (int i=0;i<t;i++){
            String[] l = br.readLine().split(" ");
            int[] p = new int[2];
            for (int k=0;k<2;k++){
                p[k]=Integer.parseInt(l[k]);
            }
            list[i]=p;
        }
        Arrays.sort(list, (a, b) -> a[0] - b[0]);
        int count=0;
        count=count+list[0][0]+list[0][1];
        for (int i=1;i<list.length;i++){
            count = Math.max(count,list[i][0]);
            count = count+list[i][1];
        }
        br.close();
        BufferedWriter out = new BufferedWriter(new FileWriter("cowqueue.out"));
        out.write(Integer.toString(count));
        out.close();

    }
}
