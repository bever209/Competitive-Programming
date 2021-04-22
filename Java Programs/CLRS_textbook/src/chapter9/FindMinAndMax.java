package chapter9;
// O of 3*(floor of (n/2)) time. basically the fastest way.
import java.math.*;
public class FindMinAndMax {// 9-1.

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[] list = {5,11,2,3,6,5,4,7,88,99,1000,21,6325,4,2,1,5,9,5,-1,-2,-30,-9,-98,-520,-1,52,63,6,789};
		int max;
		int min;
		int i;
		if (list.length%2==0) {
			 i=2;
			max = Math.max(list[0],list[1]);
			min = Math.min(list[0], list[1]);
		}
		else {
			max = list[0];
			min=list[0];
			 i=1;
		}
		for (int j=i;j<list.length-1;j=j+2) {// maybe remove max and min and change to if statements but it doesnt rlly matter.
			if (list[j]>list[j+1]) {
			max = Math.max(max, list[j]);
			min = Math.min(min, list[j+1]);
			}
			else {
			min = Math.min(min, list[j]);
			max = Math.max(max, list[j+1]);}
		}
		System.out.println(max);
		System.out.println(min);

	}

}
