package chapter9;
import java.util.*;
import java.math.*;
// Works!
//Finds the ith smallest value in an unsorted array.
// not the one with the optimal worst case time. 
public class IthSmallest {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		ArrayList<Integer> list = new ArrayList<Integer>();
		list.add(7);
		list.add(8);
		list.add(3);
		list.add(78);
		list.add(1);
		list.add(16);
		list.add(9);
		list.add(8);
		int val = select(list,0,list.size()-1,2);//Can replace 5 with whatever as long it is in the list range
		System.out.println(val);		
	}
	public static int select(ArrayList<Integer> list, int f, int l, int i) {
		if (f==l) {
			return list.get(f);
		}
		int q = partition(list,f,l);
		int k = q-f+1;
		if (i==k) {
			return list.get(q);
		}
		if (i<k) {
			return select(list,f,q-1,i);
		}
		return select(list,q+1,l,i-k);
		
	}
	public static int partition(ArrayList<Integer> list,int f,int l) {
		int piv = (int) (Math.random() * (l-1-f)) + f;
		Collections.swap(list, l, piv);
		int a = list.get(l);
		int i=f-1;
		for (int j=f;j<l;j++) {
			if (list.get(j)<=a) {
				
				i++;
				Collections.swap(list, i, j);				
			}
		}
		Collections.swap(list,i+1,l);
		return i+1;
		
	}
}
