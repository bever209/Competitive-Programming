//package year_2016_2017;


import java.io.*;
import java.util.*;

public class s_Open_3 {
    static String[] arr;
    public static void main(String[] args) throws IOException {
        InputReader r = new InputReader();
        PrintWriter pw = new PrintWriter(new FileWriter("where.out"));

        int n=r.nextInt();
        arr=new String[n];
        for (int i=0;i<arr.length;i++){ arr[i]=r.next(); }

        int ans=0;
        visit=new boolean[n][n];
        ArrayList<Rect> pcl=new ArrayList<>();

        for (int r1=0;r1<n;r1++){
            for (int c1=0;c1<n;c1++){
                for (int r2=r1;r2<n;r2++){
                    for (int c2=c1;c2<n;c2++){
                        if (is_pcl(r1,c1,r2,c2)){
                            pcl.add(new Rect(r1,c1,r2,c2));
                        }

                    }
                }
            }
        }


        for (int i=0;i<pcl.size();i++){
            for (int j=0;j<pcl.size();j++){
                if (i!=j){
                    if (pcl_in_pcl(pcl.get(i),pcl.get(j))){
                        break;
                    }
                }
                if (j==pcl.size()-1){
                    ans++;
                }
            }
        }
        pw.println(ans);pw.close();


    }
    static boolean[][] visit;
    public static boolean pcl_in_pcl(Rect x,Rect y){// x in y
        return x.a>=y.a && x.b >=y.b && x.c<=y.c && x.d<=y.d;

    }

    public static boolean is_pcl(int r1,int c1,int r2,int c2){
        HashSet<Character> set=new HashSet<>();
        for (int i=r1;i<=r2;i++){
            for (int j=c1;j<=c2;j++){
                set.add(arr[i].charAt(j));
            }
        }
        if (set.size()!=2){return false;}
        for (int i=0;i<visit.length;i++){ Arrays.fill(visit[i],false); }

        int[] cc=new int[27];
        for (int i=r1;i<=r2;i++) {
            for (int j = c1; j <= c2; j++) {
                if (!visit[i][j]){
                    cc[arr[i].charAt(j)-'A']++;
                    floodfill(i,j,r1,c1,r2,c2);
                }
            }
        }
        int count1=0;
        for (int i:cc){
            if (i==1){
                count1++;
            }
        }
        int count_more=0;
        for (int i:cc){
            if (i>1){
                count_more++;
            }
        }
        return count1 == 1 && count_more == 1;


    }
    public static void floodfill(int x,int y,int r1,int c1,int r2,int c2){
        visit[x][y]=true;
        for (int i=-1;i<=1;i++){
            for (int j=-1;j<=1;j++){
                if (i==0||j==0){
                    int new_r=x+i;int new_c=y+j;
                    if (valid(new_r,new_c,r1,c1,r2,c2)){
                        if (!visit[new_r][new_c] && arr[x].charAt(y)==arr[new_r].charAt(new_c)){
                            floodfill(new_r,new_c,r1,c1,r2,c2);
                        }
                    }
                }
            }
        }

    }
    public static boolean valid(int x, int y, int r1,int c1,int r2,int c2){ return x>=r1 && x<=r2 && y>=c1 && y<=c2; }

    public static class Rect{
        int a;int b;int c;int d;
        public Rect(int x1,int x2,int x3,int x4){
            a=x1;b=x2;c=x3;d=x4;
        }
    }

    static class InputReader {
        BufferedReader reader;
        StringTokenizer tokenizer;
        public InputReader() throws FileNotFoundException {
            reader = new BufferedReader(new FileReader("where.in"));
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
    public static class Pair{
        int x;
        int y;
        public Pair(int a,int b){
            x=a;
            y=b;
        }
    }
}
