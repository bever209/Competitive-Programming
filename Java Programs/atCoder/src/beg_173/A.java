package beg_173;
import java.util.*;
public class A {
    public static void main(String[] args){
        Scanner s = new Scanner(System.in);
        int a = s.nextInt();
        int b = a%1000;
        System.out.println((1000-b)%1000);

    }
}
