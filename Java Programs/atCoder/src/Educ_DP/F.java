package Educ_DP;

/////// TLE BECAUSE OF JAVA I THINK
import java.io.*;
import java.util.*;

public class F {
    static class InputReader {
        BufferedReader reader;
        StringTokenizer tokenizer;
        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }
        String next() { // reads in the next string
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }
        public int nextInt() { return Integer.parseInt(next()); } // reads in the next int
        public long nextLong() { return Long.parseLong(next()); } // reads in the next long
        public double nextDouble() { return Double.parseDouble(next()); } // reads in the next double
    }
    static InputReader r = new InputReader(System.in);
    static PrintWriter pw = new PrintWriter(System.out);
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
    public static void main(String[] args){

        String x=r.next();
        String y=r.next();

        ArrayList[][] list=new ArrayList[x.length()][y.length()];


        for (int i=0;i<x.length();i++){
            for (int j=0;j<y.length();j++){
                list[i][j]=new ArrayList();
                boolean b = x.charAt(i) == y.charAt(j);
                if (i!=0 && j!=0){
                    if (b){
                        list[i][j]= (ArrayList) list[i-1][j-1].clone();
                        list[i][j].add(x.charAt(i));
                    }
                    else {
                        if (list[i][j - 1].size() > list[i - 1][j].size()) {
                            list[i][j] = (ArrayList) list[i][j - 1].clone();
                        }
                        else{
                            list[i][j] = (ArrayList) list[i - 1][j].clone();
                        }
                    }
                }
                else if (i == 0 && j==0) {
                    if(b) {
                        list[i][j].add(x.charAt(i));
                    }
                }
                else if (i==0){
                    if (b){
                        list[i][j].add(x.charAt(i));
                    }
                    else{
                        list[i][j]= (ArrayList) list[i][j-1].clone();
                    }
                }
                else if (j==0){
                    if (b){
                        list[i][j].add(x.charAt(i));
                    }
                    else{
                        list[i][j]= (ArrayList) list[i-1][j].clone();
                    }
                }

            }
        }
        for (Object i:list[x.length()-1][y.length()-1]){
            pw.print(i);
        }
        pw.close();
    }
}
