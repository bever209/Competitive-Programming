//package year_2019_2020;


import java.io.*;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class s_Open_1 {
    static long[][] arr;
    static int n;
    static int m;
    static class Comp implements Comparator<long[]> {
        public int compare(long[] a, long[] b){
            for (int i = 0; i < a.length; ++i)
                if (a[i] != b[i]) return Long.compare(a[i],b[i]);
            return 0;
        }
    }
    public static void main(String[] args) throws IOException {
        InputReader r = new InputReader();
        PrintWriter pw = new PrintWriter(new FileWriter("socdist.out"));

        n=r.nextInt();
        m=r.nextInt();
        arr=new long[m][2];
        for (int i=0;i<m;i++){
            arr[i][0]=r.nextInt();
            arr[i][1]=r.nextInt();
        }
        Arrays.sort(arr,new Comp());
        long low=1; long high=(long)Math.pow(10,18);
        while (low<high){
            long mid=(low+high+1)/2;
            boolean x=bsearch(mid);
            if (x){
                low=mid;
            }
            else{
                high=mid-1;
            }
        }
        pw.println(high);
        pw.close();

    }
    public static boolean bsearch(long gap){
        long num=arr[0][0];
        int left=n-1;
        int ind=0;
        while (left>0){
            long val=num+gap;
            for (int i=ind;i<arr.length;i++){
                if (val>=arr[i][0] && val<=arr[i][1]){
                    left--;ind=i;num=val;break;
                }
                if (arr[i][0]>val){
                    left--;ind=i;num=arr[i][0];break;
                }
                if (i==arr.length-1){
                    return false;
                }
            }
        }
        return true;

    }
    static class InputReader {
        BufferedReader reader;
        StringTokenizer tokenizer;
        public InputReader() throws FileNotFoundException {
            reader = new BufferedReader(new FileReader("socdist.in"));
            tokenizer = null;
        }
        String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }
        public int nextInt() { return Integer.parseInt(next()); }
        public long nextLong() { return Long.parseLong(next()); }
        public double nextDouble() { return Double.parseDouble(next()); }
    }
}
