package beg_171;
import java.util.*;
public class B {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		String[] a = s.nextLine().split(" ");
		int many = Integer.parseInt(a[1]);
		
		String[] l = s.nextLine().split(" ");
		int[] list = new int[l.length];
		for (int i=0;i<l.length;i++) {
			list[i]=Integer.parseInt(l[i]);		}
		
		Arrays.sort(list);
		int count=0;
		for (int i=0;i<many;i++) {
			count=count+list[i];
		}
		System.out.println(count);
	}

}
