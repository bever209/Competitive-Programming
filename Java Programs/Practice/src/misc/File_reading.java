package misc;
import java.io.*;

public class File_reading {

	public static void main(String[] args) throws Exception{
		// TODO Auto-generated method stub	
		String path = "C:\\Users\\User\\Documents\\Programs\\java_programs\\Practice\\src\\misc\\prac.txt";
		
		BufferedReader in = new BufferedReader(new FileReader(path));
		int a = Integer.parseInt(in.readLine());
		for (int x=0;x<a;x++) {
			String[] l = in.readLine().split(" ");
			int[] list = new int[l.length];
			for (int i=0;i<l.length;i++) {
				list[i]=Integer.parseInt(l[i]);
			}
			int sum=0;
			for (int i:list) {
				sum=sum+i;
			}
			System.out.println(sum);
		}
		in.close();
		
		
		
	}

}
