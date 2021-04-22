package random_practiceQuestions;

// doesn't work
import java.io.*;
import java.util.*;

public class D1481 {
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
            int m=r.nextInt();

            String[] arr=new String[n];
            for (int i=0;i<n;i++){
                arr[i]=r.next();
            }
            boolean check=false;int ind1=-1;int ind2=-1;
            for (int i=0;i<n;i++){
                if (check){break;}
                for (int j=i;j<n;j++){
                    if (arr[i].charAt(j)==arr[j].charAt(i) && i!=j){
                        ind1=i+1;ind2=j+1;
                        check=true;break;
                    }
                }
            }
            if (check){
                pw.println("YES");
                for (int i=0;i<=m;i++){
                    if (i%2==0){
                        pw.print(ind1+" ");
                    }
                    else{
                        pw.print(ind2+" ");
                    }
                }
                pw.println();
            }
            else{
                if (m%2==1){
                    pw.println("YES");
                    for (int i=0;i<=m;i++){
                        if (i%2==0){
                            pw.print(1+" ");
                        }
                        else{
                            pw.print(2+" ");
                        }
                    }
                    pw.println();
                }
                else{
                    boolean[] hasa=new boolean[n];
                    Arrays.fill(hasa,false);
                    ArrayList<Integer>[] hasind=new ArrayList[n];
                    for (int i=0;i<n;i++){ hasind[i]=new ArrayList<>(); }
                    for (int i=0;i<n;i++){
                        String x=arr[i];
                        for (int j=0;j<n;j++){
                            if (x.charAt(j)=='a'){
                                hasind[i].add(j);hasa[i]=true;break;
                            }
                        }
                    }
                    ind1=-1;ind2=-1;int ind3=-1;check=false;
                    for (int i=0;i<n;i++){
                        String x=arr[i];
                        for (int j=0;j<n;j++){
                            if (x.charAt(j)=='a'){
                                if (hasa[j] && (hasind[j].size()>1 || (hasind[j].get(0)!=i))){
                                    ind1=i+1;ind2=j=1;check=true;
                                    if (hasind[j].get(0)==i){
                                        ind3=hasind[j].get(1); }
                                    else{ ind3=hasind[j].get(0); }
                                    break;
                                }
                            }
                        }
                        if (check){
                            break;
                        }
                    }
                    if (!check){
                        pw.println("NO");
                    }
                    else{
                        pw.println("YES");
                        if (m%4==2){
                            for (int i=1;i<=m+1;i++){
                                if (i%4==1){
                                    pw.print(ind1+" ");
                                }
                                else if (i%2==0){
                                    pw.print(ind2+" ");
                                }
                                else{
                                    pw.print(ind3+" ");
                                }
                            }
                        }
                        else{
                            for (int i=1;i<=m+1;i++){
                                if (i%4==0){
                                    pw.print(ind1+" ");
                                }
                                else if (i%2==1){
                                    pw.print(ind2+" ");
                                }
                                else{
                                    pw.print(ind3+" ");
                                }
                            }
                        }
                        pw.println();
                    }
                }
            }
        }
        pw.close();

    }

}
