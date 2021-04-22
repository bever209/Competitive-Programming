package year_2019_2020;
// works for all except last test case. don't know why. find out later.
import java.io.*;
import java.util.*;

public class b_Dec_2 {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new FileReader("C:\\Users\\User\\Documents\\Programs\\java_programs\\usaco\\src\\year_2019_2020\\whereami.in"));
        int a = Integer.parseInt(in.readLine());
        String s = in.readLine();
        ArrayList<String> list = new ArrayList<String>();
        for (int i=0;i<s.length();i++){
            list.add(s.substring(i,i+1));
        }
        ArrayList<String> sublist1 =new ArrayList<String>();
        ArrayList<String> sublist2 =new ArrayList<String>();
        ArrayList<String> block = new ArrayList<String>();
        boolean check=false;
        int ans=0;
        for (int i=1;i<list.size();i++){
            for (int j=0;j<list.size()-i+1;j++){

                sublist1.clear();
                sublist2.clear();
                block.clear();
                for (int k=0;k<j;k++){
                    sublist1.add(list.get(k));
                }
                for (int k=i+j;k<list.size();k++){
                    sublist2.add(list.get(k));
                }

                for (int k=j;k<i+j;k++){
                    block.add(list.get(k));
                }

                if (!contain(sublist1,block)&&!contain(sublist2,block)){
                    if (j==list.size()-i){
                        check=true;
                        ans=i;
                    }
                }
                else{
                    break;
                }

            }
            if (check){
                break;
            }
        }
        if (!check){
            ans=list.size();
        }
        String c = list.get(0);
        int count=0;
        for (String p:list){
            if (p.equals(c)){
                count++;
            }
        }
        if (count==list.size()){
            ans=list.size();
        }
        BufferedWriter out = new BufferedWriter(new FileWriter("whereami.out"));
        out.write(Integer.toString(ans));
        out.close();
    }
    public static boolean contain(ArrayList<String> sublist,ArrayList<String> block){
        ArrayList<String> list = new ArrayList<String>();
        int a = block.size();
        for (int i=0;i< sublist.size()-a+1;i++){
            list.clear();
            for (int j=i;j<i+a;j++){
                list.add(sublist.get(j));
            }
            if (block.equals(list)){
                return true;
            }
        }
        return false;

    }
}
