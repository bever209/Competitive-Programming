package Template;




import java.io.*;
import java.util.*;

public class FastInput {
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
    

    
        }

}
