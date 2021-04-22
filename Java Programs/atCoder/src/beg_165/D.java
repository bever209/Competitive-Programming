package beg_165;
import java.util.*;

public class D {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner a = new Scanner(System.in);
		String b = a.nextLine();
		String[] l = b.split(" ");
		
		long[] list = new long[3];
		for (int i=0;i<l.length;i++) {
			list[i]=Long.parseLong(l[i]);
		}
		long x = Math.min(list[1]-1, list[2]);
		
		long A = list[0];
		long B = list[1];
		
		long d = A*x/B;
		long e = x/B;
		e=e*A;
		System.out.println(d-e);
	}

}
