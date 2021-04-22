package year_2020_2021;


import java.io.*;
import java.util.*;

public class s_Open_3 {
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

    static int n;
    static long max_papers;
    static long max_cite;
    static int[] arr;
    public static void main(String[] args){

         n=r.nextInt();
         max_papers=r.nextInt(); // k - number of papers
         max_cite=r.nextInt(); // l - number of cites in a paper

        arr=r.nextIntArr(n);

        Arrays.sort(arr);

        int left=0;
        int right=arr.length-1;
        while (left<right){
            int x=arr[left];
            arr[left]=arr[right];
            arr[right]=x;left++;right--;
        }

        left=0;
        right=n;
        while (left<right){
            int mid=(left+right+1)/2;
            if (poss(mid)){
                left=mid;
            }
            else{
                right=mid-1;
            }


        }
        pw.println(left);
        pw.close();



    }
    public static boolean poss(int n){

        long left=0;
        long right=1000000;
        while (left<right){
            long mid=(left+right+1)/2;
            ArrayList<Long> list=new ArrayList<>();
            for (int i=0;i<n;i++){
                list.add(Math.max(0,mid-arr[i]));
            }
            long max=0;long sum=0;
            for (long i:list){
                max=Math.max(i,max);
                sum+=i;
            }
            if (sum<=max_cite*max_papers && max<=max_papers){
                left=mid;
            }
            else{
                right=mid-1;
            }
        }
        return left>=n;

    }
}
