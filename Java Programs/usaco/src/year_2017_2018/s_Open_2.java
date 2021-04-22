package year_2017_2018;

import java.io.*;
import java.util.Arrays;
import java.util.Collections;

public class s_Open_2 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("C:\\Users\\User\\Documents\\Programs\\java_programs\\usaco\\src\\year_2017_2018\\lemonade.in"));
        int t = Integer.parseInt(br.readLine());
        String[] l = br.readLine().split(" ");
        Integer[] list = new Integer[t];
        for (int i=0;i<l.length;i++){
            list[i]=Integer.parseInt(l[i]);
        }
        Arrays.sort(list, Collections.reverseOrder());
        int ind=0;
        for (int i=0;i<list.length;i++){
            if (list[i]<i){
                ind=i;
                break;
            }
        }
        if (ind==0){
            ind=list.length;
        }
        BufferedWriter out = new BufferedWriter(new FileWriter("lemonade.out"));
        br.close();
        out.write(Integer.toString(ind));
        out.close();
    }
}
