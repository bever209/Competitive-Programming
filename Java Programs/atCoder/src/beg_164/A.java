package beg_164;
import java.util.*;
public class A {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		String[] a = s.nextLine().split(" ");
		int b = Integer.parseInt(a[0]);
		int c = Integer.parseInt(a[1]);
		
		if (c>=b) {
			System.out.println("unsafe");
		}
		else {
			System.out.println("safe");
		}
	}

}
