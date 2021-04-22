package data_structures;
import java.util.*;
public class Linked_list_practice {
// all functions are basically built in 
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		String[] vals = s.nextLine().split(" ");
		LinkedList<Integer> list = new LinkedList<Integer>();
		
		for (String val:vals) {
			list.add(Integer.parseInt(val));
		}
		list.removeLast();
		System.out.println(list);

	}

}
