package year_2015_2016;

import java.io.*;
import java.util.ArrayList;
import java.util.Collections;

public class s_Dec_2 {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new FileReader("C:\\Users\\User\\Documents\\Programs\\java_programs\\usaco\\src\\year_2015_2016\\highcard.in"));
        int a = Integer.parseInt(in.readLine());
        ArrayList<Integer> list = new ArrayList<Integer>();
        for (int i=0;i<a;i++){
            list.add(Integer.parseInt(in.readLine()));
        }
        Collections.sort(list);
        int count=0;
        for (int i=1;i<list.size();i++){
            int b = list.get(i)-list.get(i-1)-1;
            if (b>0){
                count++;
                b--;
            }
            if (b>0){
                int c = i-count;
                if (c>0){
                    int d = Math.min(b,c);
                    count=count+d;
                }
            }
        }
        int x = list.get(list.size()-1);
        count=count+2*a-x;

        BufferedWriter out = new BufferedWriter(new FileWriter("highcard.out"));
        in.close();
        out.write(Integer.toString(count));
        out.close();
    }
}
