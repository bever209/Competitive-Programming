package chapter4;
import java.util.*;
// 4.1-5 is this question
public class Exercise_4_1 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		String[] a = s.nextLine().split(" ");
		int[] list = new int[a.length];
		for (int i =0;i<a.length;i++) {
			String b = a[i];
			int c = Integer.parseInt(b);
			list[i]=c;
		}
		int total=0;
		int re_total=0;
		int r_f_index=0;
		int r_l_index=0;
		int f_index_2=0;
	
		
		for (int i=0;i<list.length;i++) {
			total=total+list[i];
			if (total>re_total) {
				re_total=total;
				r_f_index=f_index_2;
				r_l_index=i;
			}
			if(total<0) {// If negative, basically restart
				total=0;
				f_index_2=i+1;
			}
		}
		System.out.println("Total: " +re_total );
		System.out.println("First index: " + r_f_index );
		System.out.println("Last index: " + r_l_index);
	}

}
