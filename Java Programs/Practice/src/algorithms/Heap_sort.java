package algorithms;
import java.util.*;
import java.math.*;
public class Heap_sort {
// made by myself with a little help from the textbook
	// works!
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		String[] a = s.nextLine().split(" ");
		int[] list = new int[a.length];
		
		for (int i=0;i<a.length;i++) {
			list[i]=Integer.parseInt(a[i]);
		}
		ArrayList<Integer> output = hsort(list);
		for (int i:output) {
			System.out.println(i);
		}
		System.out.println(output);
		s.close();
	}
	public static ArrayList<Integer> hsort(int[] arr) {
		ArrayList<Integer> list = new ArrayList<Integer>();
		for (int i:arr) {
			list.add(i);
		}
		ArrayList<Integer> sort_l = new ArrayList<Integer>();
		int t = list.size();
		for (int j=(int)(list.size()/2);j>=0;j--) {
			list = make_max_heap(list,j);
			//System.out.println(list);
		}
		
		
		for (int i=0;i<t;i++) {
			//System.out.println(list);
			list = make_max_heap(list,0);
			int swap = list.get(0);
			list.set(0, list.get(list.size()-1));
			list.set(list.size()-1, swap);
			
			sort_l.add(0,list.get(list.size()-1));
			list.remove(list.size()-1);			
		}
		return sort_l;
		
	}
	public static ArrayList<Integer> make_max_heap(ArrayList<Integer> list, int j){
		int l = 2*j+1;
		int r = l+1;
		int largest=j;
		//System.out.println(list + " " + j + " " + l + " " + r);
		if (l<list.size() && list.get(l)>list.get(largest)) {
		largest = l;
		}
		if (r<list.size() && list.get(r)>list.get(largest)) {
		largest = r;
		}
		
		if (largest!=j) {
			
			Collections.swap(list, j, largest);
		list = make_max_heap(list,largest);
		
			
			return list;
		}
		else {
			return list;
		}
	}
}
