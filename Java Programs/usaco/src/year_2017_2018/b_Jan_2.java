package year_2017_2018;

import java.io.*;
import java.util.*;

public class b_Jan_2 {
    public static void main(String[] args) throws IOException {
        BufferedReader br  = new BufferedReader(new FileReader("C:\\Users\\User\\Documents\\Programs\\java_programs\\usaco\\src\\year_2017_2018\\lifeguards.in"));
        int b = Integer.parseInt(br.readLine());
        ArrayList<ArrayList<Integer>> list = new ArrayList<ArrayList<Integer>>();
        for (int i=0;i<b;i++){
            String[] l = br.readLine().split(" ");
            ArrayList<Integer> a = new ArrayList<Integer>();
            a.add(Integer.parseInt(l[0]));
            a.add(Integer.parseInt(l[1]));
            list.add(a);
        }
        Collections.sort(list, new Comparator<ArrayList<Integer>>(){
            @Override
            public int compare(ArrayList<Integer> o1, ArrayList<Integer> o2){
                return o1.get(0).compareTo(o2.get(0));
            }
        });


        ArrayList<Integer> hours = new ArrayList<Integer>();
        for (int i=0;i<list.size();i++){
            ArrayList<ArrayList<Integer>> other = new ArrayList<ArrayList<Integer>>();
            for (int j=0;j<list.size();j++){
                if (j!=i){
                    other.add(list.get(j));
                }
            }
            hours.add(time(other));
        }
        br.close();
        BufferedWriter out = new BufferedWriter(new FileWriter("lifeguards.out"));
        out.write(Integer.toString(Collections.max(hours)));
        out.close();

    }
    public static int time(ArrayList<ArrayList<Integer>> list){
        int count=0;
        count=count+list.get(0).get(1)-list.get(0).get(0);
        for (int i=1;i<list.size();i++){
            if (list.get(i-1).get(1)>list.get(i).get(0)){
                count=count+list.get(i).get(1)-list.get(i).get(0)-(list.get(i-1).get(1)-list.get(i).get(0));
            }
            else{
                count=count+list.get(i).get(1)-list.get(i).get(0);
            }
        }
        return count;
    }
}
