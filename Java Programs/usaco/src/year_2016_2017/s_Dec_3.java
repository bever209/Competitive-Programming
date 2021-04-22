package year_2016_2017;

import java.io.*;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;

public class s_Dec_3 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("C:\\Users\\User\\Documents\\Programs\\java_programs\\usaco\\src\\year_2016_2017\\moocast.in"));
        int a = Integer.parseInt(br.readLine());
        int[][] list  =new int[a][3];
        for (int i=0;i<a;i++){
            String[] l = br.readLine().split(" ");
            int[] b = new int[l.length];
            for (int j=0;j<b.length;j++){
                b[j]=Integer.parseInt(l[j]);
            }
            list[i]=b.clone();
        }
        int max=0;
        Queue<int[]> q = new LinkedList<int[]>();

        for (int i=0;i<list.length;i++){
            boolean[] visit = new boolean[list.length];
            Arrays.fill(visit,false);
            int count=1;
            q.add(list[i]);
            while (!q.isEmpty()) {
                int[] v = q.poll();
                for (int j = 0; j < list.length; j++) {
                    if (!visit[j] && i!=j){
                        if (make(v,list[j])){
                            q.add(list[j]);
                            visit[j]=true;
                            count++;
                        }
                    }
                }
            }
            if (count > max) {
                max = count;
            }
            if (max >= list.length / 2 && list.length % 2 == 0) {
                break;
            }
            if (max >= list.length / 2 + 1 && list.length % 2 == 1) {
                break;
            }
        }
        BufferedWriter out = new BufferedWriter(new FileWriter("moocast.out"));
        out.write(Integer.toString(max));
        br.close();
        out.close();

    }
    public static boolean make(int[] a,int[]b){
        double x = Math.pow(Math.abs(a[0]-b[0]),2);
        double y = Math.pow(Math.abs(a[1]-b[1]),2);
        double z = Math.sqrt(x+y);
        if (z<=a[2]){
            return true;
        }
        return false;

    }
}
