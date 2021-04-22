package beg_171;
import java.util.*;
import java.lang.*;
public class A {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		char a = s.nextLine().charAt(0);
		
		boolean b = Character.isUpperCase(a);
		
		if (b) {
			System.out.println("A");
		}
		else {
			System.out.println("a");
		}
		
		
	}

}
