package algorithms;
import java.util.*;
public class Quick_sort {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		String[] a = s.nextLine().split(" ");
		ArrayList<Integer> list = new ArrayList<Integer>();
		s.close();
		for (int i=0;i<a.length;i++) {
			list.add(Integer.parseInt(a[i]));
		}
		qsort(list,0,list.size()-1);
		System.out.println(list);
		
	}
	public static void qsort(ArrayList<Integer> list,int f, int l){
		if (f<l) {
		int a = partition(list,f,l);
		qsort(list,f,a-1);
		qsort(list,a+1,l);
		
		}
		
		
	}
	
	public static int partition(ArrayList<Integer> list,int f,int l) {
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
