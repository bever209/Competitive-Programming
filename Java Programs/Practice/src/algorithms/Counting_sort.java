package algorithms;
import java.util.*;
public class Counting_sort {
// Done, by myself and textbook
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		String[] a = s.nextLine().split(" ");
		int[] list = new int[a.length];
		s.close();
		
		for (int i=0;i<a.length;i++) {
			list[i]=Integer.parseInt(a[i]);
		}
		int[] k = csort(list);
		for (int i:k) {
			System.out.println(i);
		}
	}
	public static int[] csort(int[] list) {
		int max = 0;
		for (int i:list) {
			if (i>max) {
				max=i;
			}
		}
		int[] c = new int[max+1];
		for (int i=0;i<list.length;i++) {
			c[list[i]]=c[list[i]]+1;
		}
		for (int i=1;i<c.length;i++) {
			c[i]=c[i]+c[i-1];
		}
		
		int[] out = new int[list.length];

		for (int i=0;i<list.length;i++) {
			out[c[list[i]]-1] = list[i];
			c[list[i]]=c[list[i]]-1;
		}
		return out;
		
	}

}
