package beg_173;
import java.util.*;
public class B {
    public static void main(String[] args){
        Scanner s = new Scanner(System.in);
        int ac=0;
        int tle=0;
        int wa=0;
        int re=0;
        int num = s.nextInt();
        String tvguybhi = s.nextLine();
        for (int i=0;i<num;i++){
            String a = s.nextLine();
            if (a.equals("AC")){
                ac++;
            }
            if (a.equals("TLE")){
                tle++;
            }
            if (a.equals("WA")){
                wa++;
            }
            if (a.equals("RE")){
                re++;
            }
        }
        System.out.println("AC x " + Integer.toString(ac));
        System.out.println("WA x " + Integer.toString(wa));
        System.out.println("TLE x " + Integer.toString(tle));
        System.out.println("RE x " + Integer.toString(re));

    }
}
