package round_712;


import java.io.*;
import java.util.*;

public class D {
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
   // static PrintWriter pw = new PrintWriter(System.out);
    public static void main(String[] args){
        int n=r.nextInt();

        int odd_row=1;
        int odd_col=1;
        int even_row=1;
        int even_col=2;
        int area=n*n;

        for (int i=0;i<area;i++){
            int x=r.nextInt(); // use sysout when printing

            if (x!=3 && odd_row<=n){
                System.out.println(3+" "+odd_row+" "+odd_col);
                System.out.flush();
                odd_col+=2;
            }
            else if (x!=2 && even_row<=n){

                System.out.println(2+" "+even_row+" "+even_col);
                System.out.flush();
                even_col+=2;
            }
            else{
                if (even_row<=n){
                    System.out.println(1+" "+even_row+" "+even_col);
                    System.out.flush();
                    even_col+=2;
                }
                else if (odd_row<=n){
                    System.out.println(1+" "+odd_row+" "+odd_col);
                    System.out.flush();
                    odd_col+=2;
                }
            }
            if (odd_col>n){
                odd_row++;
                odd_col=odd_row%2;
                if (odd_col==0){odd_col=2;}
            }
            else if (even_col>n){
                even_row++;
                even_col=even_row%2+1;

            }






        }



    }

}
