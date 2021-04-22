package year_2015_2016;

import java.io.*;
import java.util.ArrayList;

public class s_Dec_3 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("C:\\Users\\User\\Documents\\Programs\\java_programs\\usaco\\src\\year_2015_2016\\bcount.in"));
        String[] l = br.readLine().split(" ");
        int cows = Integer.parseInt(l[0]);
        int query = Integer.parseInt(l[1]);

        ArrayList<ArrayList<Integer>> prefix = new ArrayList<ArrayList<Integer>>();
        int a=0;
        int b=0;
        int c=0;
        for (int o=0;o<cows;o++){
            int num = Integer.parseInt(br.readLine());
            if (num==1){
                a++;
            }
            else if (num==2){
                b++;
            }
            else{
                c++;
            }
            ArrayList<Integer> term = new ArrayList<Integer>();
            term.add(a);
            term.add(b);
            term.add(c);
            prefix.add(term);
        }

        BufferedWriter out = new BufferedWriter(new FileWriter("bcount.out"));
        for (int i=0;i<query;i++){
            String[] list = br.readLine().split(" ");
            int beg=Integer.parseInt(list[0])-1;
            int end=Integer.parseInt(list[1])-1;
            beg=beg-1;
            if (beg==-1){
                out.write(Integer.toString(prefix.get(end).get(0))+" "+Integer.toString(prefix.get(end).get(1))+" "+Integer.toString(prefix.get(end).get(2))+"\n");
            }
            else{
                out.write(Integer.toString(prefix.get(end).get(0)-prefix.get(beg).get(0))+" "+Integer.toString(prefix.get(end).get(1)-prefix.get(beg).get(1))+" "+Integer.toString(prefix.get(end).get(2)-prefix.get(beg).get(2))+"\n");

            }
        }
        br.close();
        out.close();
    }
}
