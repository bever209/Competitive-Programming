package Template;

import java.util.Scanner;

public class Input {
    //HAS ALL OF THE INPUTS INTO ONE THING
    public static void main(String[] args) {
        // TODO Auto-generated method stub
        Scanner s = new Scanner(System.in);
        int a = s.nextInt();
        s.nextLine();
        for (int p = 0; p < a; p++) {
            int b=s.nextInt();
            s.nextLine();
            String[] l=s.nextLine().split(" ");
            int[] list=new int[l.length];
            for (int i=0;i<list.length;i++){
                list[i]=Integer.parseInt(l[i]);
            }
        }
    }
}
