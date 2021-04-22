package random_practiceQuestions;


import java.io.*;
import java.util.*;

public class A623 {
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
        int n=r.nextInt();int m=r.nextInt();

        ArrayList<Integer>[] arr=new ArrayList[n];
        for (int i=0;i<n;i++){
            arr[i]=new ArrayList<>();
        }

        for (int i=0;i<m;i++){
            int a=r.nextInt()-1;int b=r.nextInt()-1;
            arr[a].add(b);arr[b].add(a);
        }
        String[] ans=new String[n];
        Arrays.fill(ans,"z");
        for (int i=0;i<n;i++){
            if (arr[i].size()==n-1){
                ans[i]="b";
            }
        }
        for (int i=0;i<n;i++){
            if (arr[i].size()!=n-1){
                ans[i]="a";
                for (int j:arr[i]){
                    if (!(ans[j].equals("b"))){
                        ans[j]="a";
                    }
                }
                break;
            }
        }
        for (int i=0;i<n;i++){
            if (!(ans[i].equals("a")||ans[i].equals("b"))){
                ans[i]="c";
            }
        }
        boolean check=true;
        for (int i=0;i<n;i++){
            for (int j:arr[i]){
                if (ans[i].equals("a")&&ans[j].equals("c")){
                    check=false;
                }
                if (ans[i].equals("c")&&ans[j].equals("a")){
                    check=false;
                }
            }
        }
        int[] type=new int[3];
        for (String i:ans){
            if (i.equals("a")){
                type[0]++;
            }
            else if (i.equals("b")){
                type[1]++;
            }
            else{
                type[2]++;
            }
        }
        for (int i=0;i<n;i++){
            int num=0;
            if (ans[i].equals("a")){
                num=type[0];
            }
            else if (ans[i].equals("b")){
                num=type[1];
            }
            else{
                num=type[2];
            }
            for (int j:arr[i]){
                if (ans[j].equals(ans[i])){
                    num--;
                }
            }
            if (num!=1){
                check=false;
                break;
            }

        }
        for (String i:ans){
            if (i.equals("z")){
                check=false;
                break;
            }
        }
        if (check){
            pw.println("YES");
            String x="";
            for (String i:ans){
                x=x+i;
            }
            pw.println(x);
        }
        else{
            pw.println("NO");
        }
        pw.close();
    }
}
