package random_practiceQuestions;



import java.io.*;
import java.util.*;

public class C1482 {
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
            int n=r.nextInt();int m=r.nextInt();

            int[] ans=new int[m];
            ArrayList<Integer>[] arr=new ArrayList[m];
            for (int j=0;j<m;j++){
                int a=r.nextInt();
                ArrayList<Integer> x=new ArrayList<>();

                for (int i=0;i<a;i++){
                    x.add(r.nextInt());
                }
                arr[j]=x;
                ans[j]=x.get(0);

            }
            int[] fr =new int[n+2];
            for (int i:ans){
                fr[i]++;
            }
            int f=-1;
            for (int i=0;i<fr.length;i++){
                if (fr[i]>(m+1)/2){
                    f=i;break;
                }
            }
            if (f==-1){
                pw.println("YES");
                for (int i:ans){
                    pw.print(i+" ");
                }
                pw.println();
            }
            else{
                int extra=fr[f]-(m+1)/2;
                for (int i=0;i<arr.length && extra>0;i++){
                    if (arr[i].get(0)==f){
                        ans[i]=arr[i].get(arr[i].size()-1);
                        fr[f]--;fr[ans[i]]++;extra=fr[f]-(m+1)/2;

                    }
                }


                boolean check=false;
                for (int i=0;i<fr.length;i++){
                    if (fr[i]>(m+1)/2){
                        check=true;break;
                    }
                }
                if (check){
                    pw.println("NO");
                }
                else{
                    pw.println("YES");
                    for (int i:ans){
                        pw.print(i+" ");
                    }
                    pw.println();

                }
            }


        }
        pw.close();





    }
}
