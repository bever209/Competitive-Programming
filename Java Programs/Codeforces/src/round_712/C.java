package round_712;


import java.io.*;
import java.util.*;

public class C {
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

            int count=0;
            for (int i=0;i<n;i++){
                if (s.charAt(i)=='1'){
                    count++;
                }
            }
            if (count%2==1){
                pw.println("NO");
            }
            else{
                int num_0=0;
                int num_1=0;
                ArrayList<Integer> ans1=new ArrayList<>();
                ArrayList<Integer> ans2=new ArrayList<>();
                for (int i=0;i<n;i++){
                    if (s.charAt(i)=='1'){
                        num_1++;
                        if (num_1<=count/2){
                            ans1.add(1);
                            ans2.add(1);
                        }
                        else{
                            ans1.add(-1);
                            ans2.add(-1);
                        }
                    }
                    else{
                        num_0++;
                        if (num_0%2==0){
                            ans1.add(-1);
                            ans2.add(1);
                        }
                        else{
                            ans1.add(1);
                            ans2.add(-1);
                        }
                    }


                }
                if (isRBS(ans1) && isRBS(ans2)){
                    pw.println("YES");
                    for (int i=0;i<ans1.size();i++){
                        if (ans1.get(i)==1){
                            pw.print("(");
                        }
                        else{
                            pw.print(")");
                        }
                    }
                    pw.println();
                    for (int i=0;i<ans2.size();i++){
                        if (ans2.get(i)==1){
                            pw.print("(");
                        }
                        else{
                            pw.print(")");
                        }
                    }
                    pw.println();
                }
                else{
                    pw.println("NO");
                }

            }

        }
        pw.close();



    }
    public static boolean  isRBS(ArrayList<Integer> a){
        int count=0;int min=100000000;
        for (int i=0;i<a.size();i++){
            count+=a.get(i);
            min=Math.min(count,min);
        }
        return count==0 && min>=0;
    }

}
