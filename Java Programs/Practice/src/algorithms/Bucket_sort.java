package algorithms;
import java.util.*;
public class Bucket_sort {
////////////////////////////////////////////////// Only works for nums from 0-100, but can be easily modified by changing the /10 in like 27 to fit the 
////////////////////////////////////////////// largest number in array (look at the number of digits in that number and divide it by 10 until it is 1 digit long
//////////////////////////////////////////////// (with of course rounding)
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		String[] a = s.nextLine().split(" ");
		int[] list = new int[a.length];
		s.close();
		
		for (int i=0;i<a.length;i++) {
			list[i]=Integer.parseInt(a[i]);
		}
		ArrayList<Integer> l = bsort(list);
		System.out.println(l);
	}
	public static ArrayList<Integer> bsort(int[] list) {
		ArrayList<Integer>[] c = new ArrayList[10];  // got from online
        for (int i = 0; i < 10; i++) { 
            c[i] = new ArrayList<Integer>(); 
        } 
        
        for (int i:list) {
        	int j = i/10;
        	c[j].add(i);
        }
        for (int i=0;i<c.length;i++) {
        	c[i] = sort(c[i]);
        }
        ArrayList<Integer> total = new ArrayList<Integer>();
        for (ArrayList<Integer> i: c) {
        	for (int k: i) {
        		total.add(k);
        	}
        }
        return total;
	}
	public static ArrayList<Integer> sort(ArrayList<Integer> list){
		for (int i=0;i<list.size();i++) {
			for (int j=0;j<list.size();j++) {
				if (i!=j && (i<j && list.get(i)>list.get(j))){
					Collections.swap(list, i, j);
				}
			}
		}
		return list;
	}

}
