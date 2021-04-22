package beg_166;
import java.util.*;
public class F {

	public static void main(String[] args) {
		Scanner a = new Scanner(System.in);
		
		String b = a.nextLine();
		String[] l = b.split(" ");
		int[] list = new int[4];
		
		
		for (int i=0;i<l.length;i++) {
			list[i]=Integer.parseInt(l[i]);
		}
		int[] vals = {list[1],list[2],list[3]};
		String[] choices = new String[list[0]];
		
		boolean check=true;
		for (int j=0;j<choices.length;j++) {
			String pair = a.nextLine();
			if (pair.equals("AB")) {
				if (vals[0]>vals[1]) {
					choices[j]="round_Educ_93.B";
					vals[0]--;
					vals[1]++;
				}
				else {
					choices[j]="A";
					vals[1]--;
					vals[0]++;
				}
			}
			else if (pair.equals("BC")) {
				if (vals[1]>vals[2]) {
					choices[j]="C";
					vals[1]--;
					vals[2]++;
				}
				else {
					choices[j]="round_Educ_93.B";
					vals[2]--;
					vals[1]++;
				}
			}
			else if (pair.equals("AC")) {
				if (vals[0]>vals[2]) {
					choices[j]="C";
					vals[0]--;
					vals[2]++;
				}
				else {
					choices[j]="A";
					vals[2]--;
					vals[0]++;
				}
			}
			if (vals[0]<0 || vals[1]<0 || vals[2]<0) {
				System.out.println("No");
				check=false;
			}
		}
		if (check) {
			System.out.println("Yes");
			for (int m =0;m<choices.length;m++) {
				System.out.println(choices[m]);
			}
		}
		a.close();
	}
}