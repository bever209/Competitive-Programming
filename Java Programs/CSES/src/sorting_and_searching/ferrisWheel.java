package sorting_and_searching;

import java.util.Arrays;
import java.util.Scanner;

public class ferrisWheel {
    public static void main(String[] args) {
        // TODO Auto-generated method stub
        Scanner s = new Scanner(System.in);
        String[] i = s.nextLine().split(" ");
        int num = Integer.parseInt(i[0]);
        int max_w = Integer.parseInt(i[1]);
        String[] l = s.nextLine().split(" ");
        int[] list  = new int[l.length];
        for (int j=0;j<l.length;j++){
            list[j]=Integer.parseInt(l[j]);
        }
        Arrays.sort(list);
        int ind1=0;
        int ind2=list.length-1;
        int count=0;
        while (ind1<=ind2){
            if (list[ind1]+list[ind2]>max_w){
                count++;
                ind2--;
            }
            else{
                count++;
                ind1++;
                ind2--;

            }
        }
        System.out.println(count);
    }
}
