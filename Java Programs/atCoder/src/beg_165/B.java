package beg_165;
import java.util.*;

public class B {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner a = new Scanner(System.in);
		long b = a.nextLong();
		
		int i=0;
		long total=100;
		while (total<b) {
			long c =  total/100;
			total=total+c;
			//System.out.println(total);
			i++;
		}
		System.out.println(i);
	}

}
