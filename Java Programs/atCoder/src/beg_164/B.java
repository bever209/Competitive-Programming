package beg_164;
import java.util.*;
public class B {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		String[] x = s.nextLine().split(" ");
		
		int a = Integer.parseInt(x[0]);
		int b = Integer.parseInt(x[1]);
		int c = Integer.parseInt(x[2]);
		int d = Integer.parseInt(x[3]);
		
		int diff1 = (int) a/d;
		if (a%d!=0) {
			diff1=diff1+1;
		}
		int diff2 = (int) c/b;
		if (c%b!=0) {
			diff2=diff2+1;
		}
		
		boolean g = diff1>=diff2;
		if (g) {
			System.out.println("Yes");
		}
		else {
			System.out.println("No");
		}
	}

}
