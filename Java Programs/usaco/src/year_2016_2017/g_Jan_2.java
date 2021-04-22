package year_2016_2017;


import java.io.*;
import java.util.StringTokenizer;

public class g_Jan_2 {
    public static void main(String[] args) throws IOException {
        InputReader r = new InputReader();
        PrintWriter pw = new PrintWriter(new FileWriter("hps.out"));
        int num=r.nextInt();
        int k=r.nextInt();
        int[] move=new int[num];
        for (int i=0;i<num;i++){
            String s=r.next();
            if (s.charAt(0)=='H'){
                move[i]=0;
            }
            else if (s.charAt(0)=='P'){
                move[i]=1;

            }
            else{
                move[i]=2;
            }
        }

        int[][][] dp=new int[num+1][k+1][3];
        for (int i=1;i<=num;++i){
            for (int j=0;j<=k;++j){
                for (int state=0;state<3;++state){
                    if (j==0){
                        dp[i][j][state]=dp[i-1][j][state]+(move[i-1]==state?1:0);
                    }
                    else{
                        int s1=(state+1)%3;
                        int s2=(state+2)%3;
                        dp[i][j][state]=Math.max(Math.max(dp[i-1][j][state],dp[i-1][j-1][s1]),dp[i-1][j-1][s2])+(move[i-1]==state?1:0);
                    }

                }
            }
        }
        int ans=0;
        for (int i=0;i<3;i++){
            ans=Math.max(ans,dp[num][k][i]);
        }
        pw.println(ans);
        pw.close();



    }
    static class InputReader {
        BufferedReader reader;
        StringTokenizer tokenizer;
        public InputReader() throws FileNotFoundException {
            reader = new BufferedReader(new FileReader("C:\\Users\\User\\Documents\\Programs\\java_programs\\usaco\\src\\year_2016_2017\\hps.in"));
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
