package beg_163;

import java.util.*;

public class D {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		String[] a = s.nextLine().split(" ");
		long n = Long.parseLong(a[0]);
		long k = Long.parseLong(a[1]);
		n=n+1;
		long ways=0;
		for (long i=k;i<=n;i++) {
			ways=ways+((i*(2*n-i-1)/2) - ((i-1)*i/2) + 1);
			ways = ways%(1000000007);
		}
		System.out.println(ways);
	}

}
