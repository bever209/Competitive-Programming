package data_structures;
import java.util.*;
public class Queue_practice {
// involves stack. stack is a lot easier to be honest.
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Queue<Integer> a = new ArrayDeque<Integer>();
		Scanner s = new Scanner(System.in);
		String[] list = s.nextLine().split(" ");
		for (String val:list) {
			int v = Integer.parseInt(val);
			a.add(v);
		}
		PriorityQueue<Integer> pq = new PriorityQueue<>();
		pq.add(2);
		pq.add(4);
		pq.add(3);
		System.out.println(pq.peek());
		System.out.println(pq.poll());
		a = reverse(a);
		for (int val:a) {
			System.out.println(val);
		}
	}
	public static Queue<Integer> reverse(Queue<Integer> a) {
		Queue<Integer> re = new ArrayDeque<Integer>();
		Stack<Integer> mid = new Stack<Integer>();
		for (int val:a) {
			mid.push(val);
		}
		
		for (int i=0;i<mid.size();i=0) {
			re.add(mid.peek());
			mid.remove(mid.size()-i-1);
			//System.out.println(mid);
		}
		return re;
	}
}
