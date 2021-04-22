//package year_2018_2019;


import java.io.*;
import java.util.*;

public class s_Dec_3 {
    static boolean check=false;
    static boolean[][] visited;
    static int n;static int k;
    static Character[][] arr;
    static ArrayList<Pair> list=new ArrayList<>();
    public static void main(String[] args) throws IOException {
        InputReader r = new InputReader();
        PrintWriter pw = new PrintWriter(new FileWriter("mooyomooyo.out"));

        n=r.nextInt();
        k=r.nextInt();

        arr=new Character[n][10];
        for (int i=0;i<n;i++){
            String x=r.next();
            for (int j=0;j<10;j++){
                arr[i][j]=x.charAt(j);
            }
        }

        visited=new boolean[n][10];
        check=true;
        while (check){
            check=false;
            for (int i=0;i<n;i++){
                for (int j=0;j<10;j++){
                    if (!visited[i][j] && arr[i][j]!='0'){
                        for (int k=0;k<visited.length;k++){
                            Arrays.fill(visited[k],false);
                        }
                        floodfill(i,j);


                        if (list.size()>=k){
                            check=true;
                            for (Pair k:list){
                                arr[k.x][k.y]='0';
                            }

                        }
                        list.clear();

                    }
                }
            }


            for (int i=0;i<10;i++){
                int count=n-1;
                for (int j=n-1;j>=0;j--){
                    if (arr[j][i]!='0'){
                        Character y=arr[j][i];
                        arr[j][i]='0';
                        arr[count][i]=y;

                        count--;
                    }
                }

            }

        }
        for (int i=0;i<n;i++){
            String x="";
            for (int j=0;j<10;j++){
                x=x+arr[i][j];
            }
            pw.println(x);
        }
        pw.close();



    }
    public static void floodfill(int x, int y){
        list.add(new Pair(x,y));
        visited[x][y]=true;
        for (int i=-1;i<=1;i++){
            for (int j=-1;j<=1;j++){
                if (i==0 || j==0){
                    int new_x=x+i;int new_y=y+j;
                    if (valid(new_x,new_y)){
                        if (!visited[new_x][new_y] && arr[x][y]==arr[new_x][new_y]){
                            floodfill(new_x,new_y);
                        }
                    }
                }
            }
        }


    }
    public static boolean valid(int x,int y){
        return x>=0 && y>=0 && x<n && y<10;
    }



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
            reader = new BufferedReader(new FileReader("mooyomooyo.in"));
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
