package beg_163;

import java.util.*;

public class B {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		String[] a = s.nextLine().split(" ");
		
		int b = Integer.parseInt(a[0]);
		
		String[] list = s.nextLine().split(" ");
		int count=0;
		for (String i: list) {
			int k = Integer.parseInt(i);
			count=count+k;
		}
		if (b-count<0) {
			System.out.println(-1);
		}
		else {
			System.out.println(b-count);
	}
	}
}
