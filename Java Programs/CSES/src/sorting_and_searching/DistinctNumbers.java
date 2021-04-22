package sorting_and_searching;
import java.util.*;
public class DistinctNumbers {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		String ubdin = s.nextLine();
		String l = s.nextLine();
		String[] list = l.split(" ");
		HashSet<String> set = new HashSet<String>();
		for (String i: list) {
			set.add(i);
		}
		System.out.println(set.size());

	}

}
