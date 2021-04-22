package round_712;


import java.io.*;
import java.util.*;

public class B {
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
            int length=r.nextInt();
            String a=r.next();
            String b=r.next();

            int count_0=0;
            int count_1=0;
            ArrayList<Integer> places=new ArrayList<>();
            for (int i=0;i<length;i++){
                if (a.charAt(i)=='0'){
                    count_0++;
                }
                else{
                    count_1++;
                }

                if (count_0==count_1){
                    places.add(i);
                }
            }
            boolean same=false;
            boolean different=false;
            boolean check=true;
            int prev=0;
            for (int i:places){
                same=false;different=false;
                for (int j=prev;j<=i;j++){
                    if (a.charAt(j)==b.charAt(j)){
                        same=true;
                    }
                    else{
                        different=true;
                    }
                }
                if (same && different){
                    check=false;break;
                }
                prev=i+1;
            }

            if (check){
                if (places.size()==0 && !a.equals(b)){
                    pw.println("NO");
                }
                else if (a.equals(b)){
                    pw.println("YES");
                }
                else {
                    boolean check2=true;
                    for (int i=places.get(places.size()-1)+1;i<a.length();i++){
                        if (a.charAt(i)!=b.charAt(i)){
                            check2=false;break;
                        }
                    }
                    if (check2) {
                        pw.println("YES");
                    }
                    else{
                        pw.println("NO");
                    }
                }
            }
            else{
                pw.println("NO");
            }



        }
        pw.close();



    }

}
