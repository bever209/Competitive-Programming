package year_2019_2020;

import java.io.*;
import java.util.*;



public class b_Dec_1 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("C:\\Users\\User\\Documents\\Programs\\java_programs\\usaco\\src\\year_2019_2020\\gymnastics.in"));
        String[] info = br.readLine().split(" ");
        int lines = Integer.parseInt(info[0]);
        int num = Integer.parseInt(info[1]);
        int[][] list = new int[lines][num];
        for (int p=0;p<lines;p++){
            String[] l = br.readLine().split(" ");
            int[] intv = new int[l.length];
            for (int q=0;q<intv.length;q++){
                intv[q]=Integer.parseInt(l[q]);
            }
            list[p]=intv;
        }
        int[][] pairs = new int[num*(num-1)/2][2];
        int[] box = new int[2];
        int count=0;
        for (int i=1;i<num+1;i++){
            for (int j=i;j<num+1;j++){

                if (i!=j){
                box[0]=i;
                box[1]=j;
                pairs[count]= box.clone();
                count++;

                }
            }
        }

        for (int i=0;i<pairs.length;i++){
            int a = pairs[i][0];
            int b = pairs[i][1];
            int c = index(list[0],a);
            int d = index(list[0],b);

            if (c>d){
                pairs[i][0]=b;
                pairs[i][1]=a;
            }
        }

        for (int i=1;i<list.length;i++){
            for (int j=0;j<pairs.length;j++){
                int a = pairs[j][0];
                int b = pairs[j][1];
                int c = index(list[i],a);
                int d = index(list[i],b);
                if (c>d){
                    pairs[j][0]=-1;
                    pairs[j][1]=-1;
                }

            }
        }
        int c=pairs.length;

        for (int[] i:pairs){
            if (i[0]==-1){
                c--;
            }
        }
        BufferedWriter out = new BufferedWriter(new FileWriter("gymnastics.out"));
        out.write(Integer.toString(c));
        out.close();

    }
    public static int index(int[] list,int n){
        int ind=0;
        for (int i=0;i<list.length;i++){
            if (list[i]==n){
                ind =i;
                break;
            }
        }
        return ind;
    }
}
