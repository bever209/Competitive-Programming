package fb_hacker_cup;
// doesn't work

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;

public class R_qual_2020_D1 {
    public static void main(String[] args) throws IOException {
        BufferedReader s = new BufferedReader(new FileReader("C:\\Users\\User\\Documents\\Programs\\java_programs\\Other_comps\\src\\fb_hacker_cup\\running_on_fumes_chapter_1_input (1).txt"));
        int a = Integer.parseInt(s.readLine());
        for (int i=1;i<=a;i++){
            String[] info = s.readLine().split(" ");
            int num_city=Integer.parseInt(info[0]);
            int max_cap = Integer.parseInt(info[1]);
            int[] list = new int[num_city-1];
            for (int j=0;j<num_city-1;j++){
                list[j]=Integer.parseInt(s.readLine());
            }
            s.readLine();

            long[] dp=new long[num_city];
            Arrays.fill(dp,-2);
            if (max_cap==num_city){
                System.out.println("Case #" + i + ": "+0);
            }
            else {
                for (int val = 0; val <= max_cap; val++) {
                    dp[val] = 0;
                }

                long x = get_min(list, max_cap, dp, num_city - 1);
                System.out.println("Case #" + i + ": " + x);
            }
        }
    }
    public static long get_min(int[] list,int max_cap,long[] dp,int ind){
        if (dp[ind]!=-2){
            return dp[ind];
        }
        ArrayList<Long> poss = new ArrayList<Long>();
        for (int i=ind-1;i>ind-max_cap-1;i--){
            if (list[i]!=0) {
                System.out.println(list.length);
                System.out.println(i);
                poss.add(get_min(list, max_cap, dp, i) + list[i]);
            }
        }
        if (poss.size()==0){
            Arrays.fill(dp,-1);
            Arrays.fill(list,0);
        }
        else {
            dp[ind] = Collections.min(poss);
        }

        return dp[ind];
    }
}
