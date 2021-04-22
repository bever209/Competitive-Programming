package year_2016_2017;

import java.io.*;

public class b_Feb_2 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("C:\\Users\\User\\Documents\\Programs\\java_programs\\usaco\\src\\year_2016_2017\\circlecross.in"));
        String a = br.readLine();
        String[] list = "A B C D E F G H I J K L M N O P Q R S T U V W X Y Z".split(" ");
        int count=0;
        for (int i=0;i<list.length;i++){
            for (int j=i;j<list.length;j++){
                if (i!=j){
                    int w = find(a,list[i]);
                    int x = sind(a,list[i]);
                    int y = find(a,list[j]);
                    int z = sind(a,list[j]);
                    if ((w<y&&x>y&&z>x)||(y<w&&z>w&&x>z)){
                        count++;
                    }
                }
            }
        }
        BufferedWriter out = new BufferedWriter(new FileWriter("circlecross.out"));
        out.write(Integer.toString(count));
        out.close();

    }
    public static int find(String a,String b){
        int ind=0;
        for (int i=0;i<a.length();i++){
            if (b.equals(a.substring(i,i+1))){
                ind=i;
                break;
            }
        }
        return ind;
    }
    public static int sind(String a, String b){
        int ind=0;
        int num=0;
        for (int i=0;i<a.length();i++){
            if (b.equals(a.substring(i,i+1))){
                num++;
                ind=i;
                if (num==2){
                    break;
                }
            }
        }
        return ind;

    }
}
