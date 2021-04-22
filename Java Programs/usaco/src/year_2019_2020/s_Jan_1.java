package year_2019_2020;

// I don't know, this TLE on the final 4


import java.io.*;
import java.util.*;

public class s_Jan_1 {
    public static void main(String[] args) throws IOException {
        InputReader r = new InputReader();
        PrintWriter pw = new PrintWriter(new FileWriter("berries.out"));

        int n=r.nextInt();
        int k=r.nextInt();

        int[] arr=new int[n];int max=0;
        for (int i=0;i<arr.length;i++){
            arr[i]=r.nextInt();max=Math.max(max,arr[i]);
        }
        int[] arr2=new int[n];
        for (int i=0;i<arr2.length;i++){
            arr2[i]=arr[i];
        }

        int ans=0;
        for (int i=1;i<=max;i++){
            for (int j=0;j<arr2.length;j++){
                arr[j]=arr2[j];
            }
            int c=0;
            for (int j:arr){
                c+=j/i;
            }
            if (c<k/2){
                break;
            }

            int need=k/2;
            int ind=0;
            while (need>0){
                int numtimes=arr[ind]/i;
                numtimes=Math.min(numtimes,need);
                arr[ind]=arr[ind]-i*numtimes;
                need=need-numtimes;
                ind++;


            }



            int count=0;
            for (int j:arr){
                count+=j/i;
            }
            if (count<k/2){
                int sum=(count)*i;
                int left=(k/2)-count;
                for (int j=0;j<arr.length;j++){
                    arr[j]=arr[j]%i;
                }
                Arrays.sort(arr);
                for (int j=arr.length-1;j>=arr.length-left;j--){
                    sum+=arr[j];
                }
                ans=Math.max(ans,sum);

            }
            else{
                ans=Math.max(ans,(k/2)*i);
            }
        }
        pw.println(ans);
        pw.close();




    }
    static class InputReader {
        BufferedReader reader;
        StringTokenizer tokenizer;
        public InputReader() throws FileNotFoundException {
            reader = new BufferedReader(new FileReader("C:\\Users\\User\\Documents\\Programs\\java_programs\\usaco\\src\\year_2019_2020\\berries.in"));
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
