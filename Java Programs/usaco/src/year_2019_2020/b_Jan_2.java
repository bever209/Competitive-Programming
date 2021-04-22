package year_2019_2020;


import java.io.*;
import java.util.*;

public class b_Jan_2 {
    static class InputReader {
        BufferedReader reader;
        StringTokenizer tokenizer;
        public InputReader() throws FileNotFoundException {
            reader = new BufferedReader(new FileReader("C:\\Users\\User\\Documents\\Programs\\java_programs\\usaco\\src\\year_2019_2020\\photo.in"));
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

    public static void main(String[] args) throws IOException {
        InputReader r = new InputReader();
        PrintWriter pw = new PrintWriter(new FileWriter("photo.out"));

        int a=r.nextInt();
        //int[] ans=new int[a];
        int[] inp=new int[a-1];
        for (int i=0;i<a-1;i++){
            inp[i]=r.nextInt();
        }
        LinkedHashSet<Integer> set=new LinkedHashSet<>();
        for (int i=1;i<inp[0];i++){
            set.add(i);
            int val=i;
            for (int j:inp){
                set.add(j-val);
                val=j-val;

            }
            if (set.size()==a){
                StringBuilder s=new StringBuilder();
                boolean check=true;
                for (int k:set){
                    if (k<=0){
                        check=false;
                        break;
                    }
                    s=s.append(Integer.toString(k));
                    s=s.append(" ");
                }
                if (!check){
                    continue;
                }
                s.delete(s.length()-1,s.length());
                pw.println(s);

                break;
            }
            set.clear();
        }
        pw.close();




    }
}
