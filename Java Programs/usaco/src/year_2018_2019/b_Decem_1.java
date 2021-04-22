import java.io.*;
public class b_Decem_1 {

	public static void main(String[] args) throws Exception{
		// TODO Auto-generated method stub
		String path = "C:\\Users\\User\\Documents\\Programs\\java_programs\\usaco\\src\\year_2018_2019\\mixmilk.txt";
		BufferedReader in = new BufferedReader(new FileReader(path));
		
		int[] size = new int[3];
		int[] amount = new int[3];
		for (int i=0;i<3;i++) {

			String[] l = in.readLine().split(" ");
			size[i]=Integer.parseInt(l[0]);
			amount[i] = Integer.parseInt(l[1]);
		}
		
		in.close();
		for (int j=0;j<100;j++) {

			int i = j%3;
			if (i==0||i==1) {
				int a = Math.min(amount[i], size[i+1]-amount[i+1]);
				amount[i]=amount[i]-a;
				amount[i+1]=amount[i+1]+a;
			}
			else {
				int a = Math.min(amount[2], size[0]-amount[0]);
				amount[2]=amount[2]-a;
				amount[0]=amount[0]+a;
			}
		}
		FileWriter writer = new FileWriter("mixmilk.out");
		BufferedWriter out = new BufferedWriter(writer);

		for (int i:amount) {
			out.write(Integer.toString(i) + "\n");
		}
		out.close();

	}

}
