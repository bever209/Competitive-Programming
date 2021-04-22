//package round_714;



import java.io.*;
import java.util.StringTokenizer;

public class A {
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
            int n=r.nextInt();
            int k=r.nextInt();
            int max=((n-2+1)/2);
            if (k<=max){
                int[] ans=new int[n];
                ans[0]=1;int count=3;int ind=1;
                while (k>0){
                    ans[ind]=count;
                    ans[ind+1]=count-1;
                    count+=2;ind+=2;k--;
                }
                count--;
                for (int i=ind;i<n;i++){
                    ans[i]=count;count++;
                }
                for (int i:ans){
                    pw.print(i+" ");
                }
                pw.println();


            }
            else{
                pw.println(-1);
            }




        }
        pw.close();



    }

}
