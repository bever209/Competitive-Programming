package algorithms;
import java.util.*;
public class Radix_sort {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		String[] a = s.nextLine().split(" ");
		int[] list = new int[a.length];
		s.close();
		
		for (int i=0;i<a.length;i++) {
			list[i]=Integer.parseInt(a[i]);
		}
		list = rsort(list);
		for (int i:list) {
			System.out.println(i);
		}
	}
	public static int[] rsort(int[] list) {
		int max = 0;
		for (int i:list) {
			if (i>max) {
				max=i;
			}
		}
		for (int exp=1;(max/exp)>0;exp=exp*10){
			list = csort(list,exp);
		}
		return list;
	}
	public static int[] csort(int[] list,int exp) {
		int[] c = new int[10];
		for (int i=0;i<list.length;i++) {
			c[(list[i]/exp)%10]=c[(list[i]/exp)%10]+1;
		}
		for (int i=1;i<c.length;i++) {
			c[i]=c[i]+c[i-1];
		}
		
		int[] out = new int[list.length];

		for (int i=list.length-1;i>=0;i--) {
			out[c[(list[i]/exp)%10]-1] = list[i];
			c[(list[i]/exp)%10]=c[(list[i]/exp)%10]-1;
		}
		return out;
		
	}

}
