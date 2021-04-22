package year_2017_2018;

import java.io.*;
import java.util.*;

public class b_Dec_3 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("C:\\Users\\User\\Documents\\Programs\\java_programs\\usaco\\src\\year_2017_2018\\measurement.in"));
        int t = Integer.parseInt(br.readLine());
        HashMap<String,Integer> map = new HashMap<String, Integer>();
        map.put("Mildred",7);
        map.put("Bessie",7);
        map.put("Elsie",7);
        int count=0;

        TreeMap<Integer,String> change = new TreeMap<Integer, String>();
        for (int i=0;i<t;i++){
            String[] list = br.readLine().split(" ");
            String s = list[1]+" " +list[2];
            int a = Integer.parseInt(list[0]);
            change.put(a,s);
        }
        ArrayList<String> max = new ArrayList<String>();
        max.add("Mildred");
        max.add("Bessie");
        max.add("Elsie");
        Collections.sort(max);
        ArrayList<String> curr = new ArrayList<String>();
        for (int i:change.keySet()){
            curr= new ArrayList<String>(max);
            String[] b = change.get(i).split(" ");
            String name = b[0];
            int c = Integer.parseInt(b[1].substring(1,2));
            String sign = b[1].substring(0,1);
            if (sign.equals("+")){
                map.replace(name,map.get(name)+c);
            }
            else{
                map.replace(name,map.get(name)-c);
            }
            //update curr and check if equals max. if not, then count++
            max.clear();
            int m=0;
            for (String j:map.keySet()){
                if (map.get(j)>m){
                    m=map.get(j);
                }
            }
            for (String k:map.keySet()){
                if (map.get(k)==m){
                    max.add(k);
                }
            }
            Collections.sort(max);

            if (!(max.equals(curr))){
                count++;
            }
        }
        br.close();
        BufferedWriter out = new BufferedWriter(new FileWriter("measurement.out"));
        out.write(Integer.toString(count));
        out.close();
    }
}
