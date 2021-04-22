package Template;
import java.util.*;
import java.io.*;

public class File_FastInput {

    public static void main(String[] args) throws IOException{
        InputReader r = new InputReader();
        PrintWriter pw = new PrintWriter(new FileWriter("problemname.out"));

    }
    static class InputReader {
        BufferedReader reader;
        StringTokenizer tokenizer;
        public InputReader() throws FileNotFoundException {
            reader = new BufferedReader(new FileReader("problemname.in"));
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
