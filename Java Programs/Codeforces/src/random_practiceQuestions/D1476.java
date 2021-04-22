package random_practiceQuestions;


import java.io.*;
import java.util.*;

public class D1476 {
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
            int n=r.nextInt()+1;
            String x=r.next(); // has length n-1


            int[] arr=new int[n-1];
            for (int i=0;i<arr.length;i++){
                if (x.charAt(i)=='L'){
                    arr[i]=0;
                }
                else{
                    arr[i]=1;
                }
            }
            int[] leftmost=new int[n];
            int[] rightmost=new int[n];

            // leftmost first
            if (arr[0]==0){ leftmost[1]=0; }
            else{leftmost[1]=1;}

            for (int i=2;i<n;i++){
                if (arr[i-1]==0 && arr[i-2]==1){
                    leftmost[i]=leftmost[i-2];
                }
                else if (arr[i-1]==0){
                    leftmost[i]=i-1;
                }
                else{
                    leftmost[i]=i;
                }
            }
            rightmost[n-1]=n-1;
            if (arr[arr.length-1]==1){ rightmost[n-2]=n-1; }
            else{ rightmost[n-2]=n-2; }


            for (int i=n-3;i>=0;i--){
                if (arr[i]==1 && arr[i+1]==0){
                    rightmost[i]=rightmost[i+2];
                }
                else if (arr[i]==1){
                    rightmost[i]=i+1;
                }
                else{
                    rightmost[i]=i;
                }
            }

            for (int i=0;i<n;i++){
                System.out.print((rightmost[i]-leftmost[i]+1)+" ");
            }

            System.out.println();



        }


    }
}
