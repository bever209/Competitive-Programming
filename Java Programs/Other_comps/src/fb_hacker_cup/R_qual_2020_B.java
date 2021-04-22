package fb_hacker_cup;
import java.util.*;
public class R_qual_2020_B {
    public static void main(String[] args){
        Scanner s=new Scanner(System.in);
        int a = s.nextInt();
        s.nextLine();
        for (int i=1;i<=a;i++){
            int length=s.nextInt();
            s.nextLine();
            String b=s.nextLine();
            int num_a=0;
            for (int j=0;j<b.length();j++){
                if ((b.substring(j,j+1)).equals("A")){
                    num_a++;
                }
            }
            if (length/2==num_a||length/2+1==num_a){
                System.out.println("Case #" + Integer.toString(i)+": "+"Y");
            }
            else{
                System.out.println("Case #" + Integer.toString(i)+": "+"N");
            }
        }
    }
}
