package year_2016_2017;


import java.io.*;
import java.util.*;

public class s_Feb_3 {
    static boolean[][] can_visit;
    static int n;
    static ArrayList<Pair>[][] list;
    public static void main(String[] args) throws IOException {
        InputReader r = new InputReader();
        PrintWriter pw = new PrintWriter(new FileWriter("countcross.out"));

        n=r.nextInt();
        int num_cows=r.nextInt();
        int num_roads=r.nextInt();

       list=new ArrayList[n+1][n+1];
       for (int i=0;i<n+1;i++){
           for (int j=0;j<n+1;j++){
               list[i][j]=new ArrayList<>();
           }
       }

        for (int i=0;i<num_roads;i++){
            int r1=r.nextInt();int c1=r.nextInt();
            int r2=r.nextInt();
            int c2=r.nextInt();

            list[r1][c1].add(new Pair(r2,c2));
            list[r2][c2].add(new Pair(r1,c1));
        }


        ArrayList<Pair> cows=new ArrayList<>();
        for (int i=0;i<num_cows;i++){
            cows.add(new Pair(r.nextInt(),r.nextInt()));
        }

        int ans=0;
        can_visit=new boolean[n+1][n+1];

        for (int i=0;i<cows.size();i++){
            for (int j=0;j<can_visit.length;j++){
                Arrays.fill(can_visit[j],false);
            }

            floodfill(cows.get(i).x,cows.get(i).y);
            for (int j=i+1;j<cows.size();j++){
                if (!can_visit[cows.get(j).x][cows.get(j).y]){
                    ans++;
                }
            }


        }
        pw.println(ans);
        pw.close();




    }
    public static void floodfill(int r,int c){
        can_visit[r][c]=true;
        for (int i=-1;i<=1;i++){
            for (int j=-1;j<=1;j++){
                if (i==0 || j==0){
                    int new_r=r+i;int new_c=c+j;
                    if (valid(new_r,new_c)){
                        boolean check=false;
                        for (Pair k:list[r][c]){
                            if (k.x==new_r && k.y==new_c){
                                check=true;break;
                            }
                        }
                        if (!check && !can_visit[new_r][new_c]){
                            floodfill(new_r,new_c);
                        }
                    }
                }
            }
        }

    }

    public static boolean valid(int r,int c){ return r>0 && c>0 && r<=n && c<=n; }




    public static class Pair{
        int x;
        int y;
        public Pair(int a,int b){
            x=a;
            y=b;
        }
    }
    static class InputReader {
        BufferedReader reader;
        StringTokenizer tokenizer;
        public InputReader() throws FileNotFoundException {
            reader = new BufferedReader(new FileReader("countcross.in"));
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
