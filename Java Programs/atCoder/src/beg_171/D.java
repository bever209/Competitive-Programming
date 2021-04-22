package beg_171;
import java.util.*;
public class D {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		int a = s.nextInt();
		String rdxtcfvgybhjnj = s.nextLine();
		String[] l = s.nextLine().split(" ");
		
		ArrayList<Integer> list = new ArrayList<Integer>();
		for (String i: l) {
			list.add(Integer.parseInt(i));
		}
		int b = s.nextInt();
		String drcftgybhu = s.nextLine();
		
		int[] arr = new int[100000];
		
		int sum = 0;
		for (int val: list) {
			arr[val-1]=arr[val-1]+1;
			sum=sum+val;
		}
		
		
		for (int i=0;i<b;i++) {
			String[] swap = s.nextLine().split(" ");
			int change = Integer.parseInt(swap[0]);
			int to = Integer.parseInt(swap[1]);
			sum=sum+(to-change)*arr[change-1];
			System.out.println(sum);
			
			arr[to-1]=arr[to-1]+arr[change-1];
			arr[change-1]=0;
			
			
		}
		
	}

}
