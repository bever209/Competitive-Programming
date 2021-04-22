package kickstart;



import java.io.*;
import java.util.*;

public class round_B_1 {
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
            String s=r.next();
            Character[] arr=new Character[n];
            for (int i=0;i<n;i++){
                arr[i]=s.charAt(i);
            }

            int left=0;
            int right=n-1;
            while (left<right){
                Character x=arr[left];
                arr[left]=arr[right];
                arr[right]=x;

                left++;right--;
            }
            int[] ans=new int[n]; //reverse aat the end

            for (int i=0;i<n;i++){
                int a=1;Character prevchar=arr[i];
                for (int j=i+1;j<n;j++){
                    if ((int)prevchar>(int)arr[j]){
                        prevchar=arr[j];a++;
                    }
                    else{
                        break;
                    }
                }
                ans[i]=a;
            }
            left=0;right=n-1;
            while (left<right){
                int x=ans[left];
                ans[left]=ans[right];
                ans[right]=x;
                left++;right--;
            }

            pw.print("Case #"+(v+1)+": ");
            for (int i:ans){
                pw.print(i+" ");
            }
            pw.println();
        }
        pw.close();




    }
}
