package beg_164;
import java.util.*;
public class C {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		int a = s.nextInt();
		String yvgubhij = s.nextLine();
		
		HashSet<String> set = new HashSet<String>();
		for (int i=0;i<a;i++) {
			String b = s.nextLine();
			set.add(b);
		}
		System.out.println(set.size());
	}

}
