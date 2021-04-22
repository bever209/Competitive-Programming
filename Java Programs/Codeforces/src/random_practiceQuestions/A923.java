package random_practiceQuestions;


import java.io.*;
import java.util.StringTokenizer;

public class A923 {
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
    }
    static InputReader r = new InputReader(System.in);
    static PrintWriter pw = new PrintWriter(System.out);
    public static void main(String[] args){
        int n=r.nextInt();

        int k=findmax(n);
        int left=n-k+1;
        int ans=n;
        for (int i=left;i<=n;i++){
            int b=findmax(i);
            if (i==b){
                ans=Math.min(ans,i);
            }
            else{
                ans=Math.min(ans,i-b+1);
            }
        }
        System.out.println(ans);
    }
    public static int findmax(int n){
        int max=1;
        for (int i=2;i<Math.sqrt(n)+1 && n!=1;i++){
            if (n%i==0){
                while (n%i==0){
                    n=n/i;
                }
                max=Math.max(max,i);
            }
        }
        max=Math.max(max,n);
        return max;
    }
}
