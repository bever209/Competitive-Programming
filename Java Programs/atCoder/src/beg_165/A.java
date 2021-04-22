package beg_165;
import java.util.*;
public class A {

	public static void main(String[] args) {
		Scanner a = new Scanner(System.in);
		int b = a.nextInt();
		String xdrtcfvygbuh = a.nextLine();
		
		String c = a.nextLine();
		String[] list = c.split(" ");
		
		int f = Integer.parseInt(list[0]);
		int l = Integer.parseInt(list[1]);
		boolean check=true;
		for (int i=f;i<=l;i++) {
			if (i%b==0) {
				System.out.println("OK");
				
				check=false;
				break;
			}
		}
		if (check) {
			System.out.println("NG");
		}

	}

}
