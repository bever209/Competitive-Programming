package algorithms;
import java.util.*;
// This is for binary search on arrays, not graphs   
public class Binary_search {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		
		String[] a=s.nextLine().split(" ");
		int[] list = new int[a.length];
		
		for (int i=0;i<a.length;i++) {
			list[i]=Integer.parseInt(a[i]);
		}
		int find = s.nextInt();
		Arrays.sort(list);
		
		System.out.println("Index is: " + bin_search(list,find,0,list.length-1));
		s.close();
	}
	public static int bin_search(int[] list, int find,int f, int l) {
		int mid = (f+l)/2 ;
		
		if (list[mid]==find) {
			return mid+1;
		}
		else {
			if (list[mid]>find) {
				return bin_search(list,find,f,mid-1);
			}
			else {
				return bin_search(list,find,mid+1,l);
			}
		}
	}

}
