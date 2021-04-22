package year_2015_2016;
///////////////////////////////////////////ONLY 7/10 ON THE TEST CASES!!!
import java.io.*;
import java.util.ArrayList;
import java.util.Collections;

public class b_Feb_3 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("C:\\Users\\User\\Documents\\Programs\\java_programs\\usaco\\src\\year_2015_2016\\balancing.in"));
        String[] l = br.readLine().split(" ");
        int cow = Integer.parseInt(l[0]);
        int max = Integer.parseInt(l[1]);
        ArrayList<ArrayList<Integer>> list = new ArrayList<ArrayList<Integer>>();
        for (int q=0;q<cow;q++){
            String[] t = br.readLine().split(" ");
            ArrayList<Integer> pair = new ArrayList<Integer>();
            pair.add(Integer.parseInt(t[0]));
            pair.add(Integer.parseInt(t[1]));
            list.add(pair);
        }
        ///////////////////////TRY USING LONGS INSTEAD OF INTS AND SEE WHAT HAPPENS
        /////////////////////// USE LONGS ON THE AVERAGE VARIABLES.
        int av_x=0;
        for (ArrayList<Integer> p:list){
            av_x=av_x+p.get(0);
        }
        av_x=av_x/list.size();
        if (av_x%2==1){
            av_x=av_x-1;
        }
        int av_y=0;
        for (ArrayList<Integer> p:list){
            av_y=av_y+p.get(0);
        }
        av_y=av_y/list.size();
        if (av_y%2==1){
            av_y=av_y-1;
        }
        ArrayList<Integer> max_vals = new ArrayList<Integer>();
        for (int i=av_x-1500;i<av_x+1501;i=i+2){
            for (int j=av_y-1500;j<av_y+1501;j=j+2){
                max_vals.add(get_max(list,i,j));
            }
        }
        int m = Collections.min(max_vals);
        br.close();
        BufferedWriter out = new BufferedWriter(new FileWriter("balancing.out"));
        out.write(Integer.toString(m));
        out.close();
    }
    public static int get_max(ArrayList<ArrayList<Integer>> list, int i,int j){
        int left_up=0;
        int right_up=0;
        int left_down=0;
        int right_down=0;
        for (ArrayList<Integer> a:list){
            if (a.get(0)<i && a.get(1)>j){
                left_up++;
            }
            else if (a.get(0)<i && a.get(1)<j){
                left_down++;
            }
            else if (a.get(0)>i && a.get(1)<j){
                right_down++;
            }
            else{
                right_up++;
            }
        }
        int max = Math.max(left_up,left_down);
        max = Math.max(max,right_down);
        max = Math.max(max,right_up);
        return max;

    }

}
