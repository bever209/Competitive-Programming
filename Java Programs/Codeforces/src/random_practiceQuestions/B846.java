package random_practiceQuestions;

// DOES NOT WORK, FIX LATER
import java.io.*;
import java.util.*;

public class B846 {
    static class InputReader {
        BufferedReader reader;
        StringTokenizer tokenizer;
        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 1000000);
            tokenizer = null; }
        //////////////////////////////////////////////////////////////////////////////////////////
        String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken(); }
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
        int n=r.nextInt();
        int k=r.nextInt();
        long M=r.nextLong();

        long[] arr=r.nextLongArr(k);
        long[] pref=new long[arr.length];
        long sum=0;
        for (int i=0;i<arr.length;i++){
            sum=sum+arr[i];
            pref[i]=sum;
        }
        long ans=0;
        for (int i=0;i<=n;i++){
            long num=M;
            long nowans=0;

            num=num-i*sum;

            if (num<0){
                break;
            }
            nowans=nowans+ (long) i *(k+1);

            int ind=0;
            int left=n-i;
            for (int j=0;j<pref.length;j++){
                if (pref[j]*left>num){
                    ind=j-1;break;
                }
                if (j==pref.length-1){
                    ind=j-1;
                }
            }
            if (ind>=0){
                nowans=nowans+ (long) (ind + 1) *left;
                num=num-pref[ind]*left;
                if (ind==arr.length-1){
                    nowans=nowans+left;
                }
            }
            ind++;
            if (ind<arr.length) {
                int count = 0;
                while (true) {
                    num = num - arr[ind];
                    left--;
                    if (left<0 || num < 0) {
                        break;
                    }
                    nowans++;
                    if (ind == arr.length - 1) {
                        nowans++;
                    }
                }
            }

            ans=Math.max(ans,nowans);
        }
        System.out.println(ans);
    }
}
