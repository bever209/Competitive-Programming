package year_2019_2020;
////// GET TO WORK, INDEX ISSUES


import java.io.*;
import java.util.*;

public class s_Jan_3 {
    public static class Pair{
        int x;
        int y;
        public Pair(int a,int b){
            x=a;
            y=b;
        }
    }

    static int[] place;
    static ArrayList<Pair>[] arr;
    static int n;
    static int mid;
    public static void main(String[] args) throws IOException {
        InputReader r = new InputReader();
        PrintWriter pw = new PrintWriter(new FileWriter("wormsort.out"));

        n = r.nextInt();
        int m = r.nextInt();
        place = new int[n];

        for (int i = 0; i < n; i++) {
            place[i] = r.nextInt() - 1;
        }
        int minhole = 1000000001;
        int maxhole = 0;
        arr = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            arr[i] = new ArrayList<>();
        }
        for (int i = 0; i < m; i++) {
            int a = r.nextInt() - 1;
            int b = r.nextInt() - 1;
            int c = r.nextInt();
            arr[a].add(new Pair(b, c));
            arr[b].add(new Pair(a, c));
            maxhole = Math.max(maxhole, c);
            minhole = Math.min(minhole, c);
        }


        int[] ind_of_place=new int[n];
        for (int i=0;i<n;i++){
            ind_of_place[place[i]]=i;
        }

        int left=0;
        int right=1000000001;
        while (left<right){
            mid=(left+right+1)/2;
            boolean c=valid();

            if (c){
                left=mid;
            }
            else{
                right=mid-1;
            }

        }
        if (right==1000000001){
            pw.println(-1);
        }
        else {
            pw.println(left);
        }
        pw.close();


    }

    static int[] comp;
    static int count;
    public static boolean valid(){
        comp=new int[n];

        count=1;
        for (int i=0;i<comp.length;i++){
            if (comp[i]==0){
                comp[i]=count;
                dfs(i);
            }
            count++;
        }
        for (int i=0;i<comp.length;i++){
            if (comp[i]!=comp[place[i]]){
                return false;
            }
        }
        return true;

    }
    public static void dfs(int ind){
        for (Pair i:arr[ind]){
            int node=i.x;int big=i.y;
            if (big>=mid && comp[node]==0){
                comp[node]=count;dfs(node);
            }
        }
    }



    static class InputReader {
        BufferedReader reader;
        StringTokenizer tokenizer;
        public InputReader() throws FileNotFoundException {
            reader = new BufferedReader(new FileReader("C:\\Users\\User\\Documents\\Programs\\java_programs\\usaco\\src\\year_2019_2020\\wormsort.in"));
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
