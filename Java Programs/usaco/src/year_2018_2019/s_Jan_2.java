package year_2018_2019;
// TL on last case but whatever

import java.io.*;
import java.util.*;

public class s_Jan_2 {
    static Character[][] arr;
    static boolean[][] visit;
    static int p=0;
    static int area=0;
    static int maxarea=0;
    static int cp=0;
    public static void main(String[] args) throws IOException {
        InputReader r = new InputReader();
        PrintWriter pw = new PrintWriter(new FileWriter("perimeter.out"));

        int a=r.nextInt();
        arr=new Character[a+2][a+2];
        for (int i=0;i<arr.length;i++){
            Arrays.fill(arr[i],'.');
        }
        for(int i=0;i<a;i++){
            String b=r.next();
            for (int j=0;j<b.length();j++){
                arr[i+1][j+1]=b.charAt(j);
            }
        }
        visit=new boolean[a+2][a+2];

        for (int i=0;i<a+2;i++){
            for (int j=0;j<a+2;j++){
                if (!visit[i][j] && arr[i][j]=='#'){
                    area=0;
                    p=0;
                    dfs(i,j);
                    if (area==maxarea){
                        cp=Math.min(cp,p);
                    }
                    else if (area>maxarea){
                        maxarea=area;
                        cp=p;
                    }


                }
            }
        }
        pw.println(maxarea+" "+cp);pw.close();

    }
    public static void dfs(int a,int b){
        visit[a][b]=true;
        area++;

        for (int i=-1;i<=1;i++){
            for (int j=-1;j<=1;j++){
                if (i==0 || j==0){
                    if (arr[a+i][b+j]=='.'){
                        p++;
                    }
                    int vala=a+i;
                    int valb=b+j;
                    if (!visit[vala][valb] && arr[vala][valb]=='#'){
                        dfs(vala,valb);
                    }
                }
            }
        }

    }
    static class InputReader {
        BufferedReader reader;
        StringTokenizer tokenizer;
        public InputReader() throws FileNotFoundException {
            reader = new BufferedReader(new FileReader("perimeter.in"));// Haven't renamed to file in my
            ///////////////////////////////////////////////////////////////////// directory
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
