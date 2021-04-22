package round_710;


import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;

public class E {
    static class InputReader {
        BufferedReader buffreader;
        StringTokenizer strtokenizer;
        public InputReader(InputStream inputstr) {
            buffreader = new BufferedReader(new InputStreamReader(inputstr), 1000000);strtokenizer = null; }
        //////////////////////////////////////////////////////////////////////////////////////////
        String next() {
            while (strtokenizer == null || !strtokenizer.hasMoreTokens()) {
                try { strtokenizer = new StringTokenizer(buffreader.readLine()); }
                catch (IOException e) { throw new RuntimeException(e); }
            }
            return strtokenizer.nextToken(); }
        ///////////////////////////////////////////////////////////////////////////////////////////
        public int nextInt() { return Integer.parseInt(next()); }
        public long nextLong() { return Long.parseLong(next()); }
        public double nextDouble() { return Double.parseDouble(next()); }
        public int[] nextIntArr(int n){
            int[] arr=new int[n];
            for (int i=0;i<n;i++){arr[i]=nextInt();}
            return arr;}
        public long[] nextLongArr(int n){
            long[] arr=new long[n];
            for (int i=0;i<n;i++){arr[i]=nextLong();}
            return arr;}
        public String[] nextStringArr(int n){
            String[] arr=new String[n];
            for (int i=0;i<n;i++){arr[i]=next();}
            return arr;}
    }
    static InputReader r = new InputReader(System.in);
    static PrintWriter pw = new PrintWriter(System.out);
    public static void main(String[] args){
        int t=r.nextInt();
        for (int v=0;v<t;v++) {
            int n = r.nextInt();
            int[] arr = r.nextIntArr(n);

            boolean[] used=new boolean[n+1];

            int[] base=new int[n];
            Arrays.fill(base,-1);
            base[0]=arr[0];used[arr[0]]=true;
            for (int i=1;i<arr.length;i++){
                if (arr[i]!=arr[i-1]){
                    base[i]=arr[i];
                    used[arr[i]]=true;
                }
            }
            int num=1;

            for (int i:base){
                if (i!=-1){
                    pw.print(i+" ");
                }
                else{
                    while (used[num]){
                        num++;
                    }
                    pw.print(num+" ");num++;
                }
            }
            pw.println();

            ArrayList<Integer> list=new ArrayList<>();
            for (int i=1;i<used.length;i++){
                if (!used[i]){
                    list.add(i);
                }
            }
            int z=0;
            for (int i:base){
                if (i!=-1){
                    pw.print(i+" ");
                    z=i;
                }
                else{
                    //Collections.sort(list);
                    int left=0;
                    int right=list.size()-1;
                    while (left<right){
                        int mid=(left+right+1)/2;
                        if (list.get(mid)<z){
                            left=mid;
                        }
                        else{
                            right=mid-1;
                        }
                    }
                    num=list.get(left);
                    list.remove(left);
                    pw.print(num+" ");
                }
            }
            pw.println();









        }
        pw.close();





    }
}
