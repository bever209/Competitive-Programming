package year_2019_2020;
//gives time limit exceeded error for a lot of cases.
import java.io.*;
import java.util.ArrayList;

public class b_Feb_3 {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new FileReader("C:\\Users\\User\\Documents\\Programs\\java_programs\\usaco\\src\\year_2019_2020\\swap.in"));
        String[] l = in.readLine().split(" ");
        int a = Integer.parseInt(l[0]);
        int num = Integer.parseInt(l[1]);
        ArrayList<ArrayList<Integer>> list = new ArrayList<ArrayList<Integer>>();
        for (int p=0;p<2;p++){
            String[] line = in.readLine().split(" ");
            ArrayList<Integer> q = new ArrayList<Integer>();
            q.add(Integer.parseInt(line[0])-1);
            q.add(Integer.parseInt(line[1])-1);
            list.add(q);
        }
        ArrayList<Integer> cows = new ArrayList<Integer>();
        for (int i=1;i<=a;i++){
            cows.add(i);
        }
        for (int i=0;i<num;i++){
        for (ArrayList<Integer> j:list){
            cows=reverse(cows,j);
        }}
        BufferedWriter out =new BufferedWriter(new FileWriter("swap.out"));
        for (int i:cows){
            out.write(Integer.toString(i) + "\n");

        }
        in.close();
        out.close();

    }
    public static ArrayList<Integer> reverse(ArrayList<Integer> list,ArrayList<Integer> swap){
        int max =(swap.get(0)+swap.get(1))/2;
        int min=swap.get(0);
        for (int i=min;i<=max;i++){

            int a = list.get(i);
            int b = list.get(swap.get(1)-(i-min));
            list.set(i,b);
            list.set(swap.get(1)-(i-min),a);

        }

        return list;
    }
}
