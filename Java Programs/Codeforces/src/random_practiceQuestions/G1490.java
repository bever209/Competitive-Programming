package random_practiceQuestions;


import java.io.*;
import java.util.*;

public class G1490 {
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
        for (int v=0;v<t;v++){
            int n=r.nextInt();int m=r.nextInt();
            int[] a=r.nextIntArr(n);
            int[] x=r.nextIntArr(m);
            int[] pref=new int[n];
            int sum=0;int max=0;
            for (int i=0;i<n;i++){
                sum+=a[i];
                pref[i]=sum;
                max=Math.max(max,pref[i]);
            }
            ArrayList<Integer> arr=new ArrayList<>();
            ArrayList<Integer> inds=new ArrayList<>();
            arr.add(pref[0]);
            inds.add(0);
            for (int i=1;i<n;i++){
                if (pref[i]>arr.get(arr.size()-1)){
                    arr.add(pref[i]);
                    inds.add(i);
                }
            }


            for (int i:x){
                if (max<i && sum<=0){
                    pw.print(-1+" ");
                    continue; }

                int turns;
                if (sum==0){
                    turns=0;
                }
                else {
                    turns = (i - max + sum - 1) / sum;
                }
                turns=Math.max(turns,0);
                i=i-turns*sum;

                int left=0;int right=arr.size()-1;
                while (left<right){
                    int mid=(left-1+right)/2;
                    if (arr.get(mid)>=i){
                        right=mid;
                    }
                    else{
                        left=mid+1;
                    }
                }
                int num=turns*n+inds.get(left);
                pw.print(num+" ");

            }
            pw.println();
        }
        pw.close();
    }

}
