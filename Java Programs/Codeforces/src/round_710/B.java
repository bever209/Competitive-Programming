package round_710;


import java.io.*;
import java.util.StringTokenizer;

public class B {
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
            int n=r.nextInt();int k=r.nextInt();
            String s=r.next();
            int first=-1;int last=0;
            for (int i=0;i<s.length();i++){
                if (s.charAt(i)=='*'){
                    if (first==-1){
                        first=i;
                    }
                    last=i;
                }
            }

            if (last-first>k){
                int ans=2;
                int next=0;
                for (int i=first+1;i<=last;i++){
                    if (last-first>k){

                        if (i-first>k){

                            first=next;ans++;
                        }

                        if (s.charAt(i)=='*'){
                            next=i;
                        }

                    }
                    else{ break; }
                }
                pw.println(ans);

            }
            else{
                if (first==last){
                    pw.println(1);
                }
                else{
                    pw.println(2);
                }
            }

        }
        pw.close();





    }
}
