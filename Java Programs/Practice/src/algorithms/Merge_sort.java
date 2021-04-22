package algorithms;
// not made by me, copied from online and altered very little. make own later. But i understand how it works.
import java.util.Scanner;

public class Merge_sort {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		
		String[] a = s.nextLine().split(" ");
		int[] list = new int[a.length];
		s.close();
		
		for (int i=0;i<a.length;i++) {
			list[i]=Integer.parseInt(a[i]);
		}
	
		list = msort(list,0,list.length-1);
		for (int i:list) {
			System.out.println(i);
		}
		}
	
	public static int[] msort(int arr[], int l, int r) 
    { 
        if (l < r) { 
         
            int m = (l + r) / 2; 
  
           arr= msort(arr, l, m); 
           arr= msort(arr, m + 1, r); 
  
           
            arr=merge(arr, l, m, r); 
           return arr;
        } 
        else {
        	return arr;
        }
    } 	
	public static int[] merge(int arr[], int l, int m, int r) 
    {  
        int n1 = m - l + 1; 
        int n2 = r - m; 
  
        int L[] = new int[n1]; 
        int R[] = new int[n2]; 
  
        for (int i = 0; i < n1; i++) 
            L[i] = arr[l + i]; 
        for (int j = 0; j < n2; j++) 
            R[j] = arr[m + 1 + j]; 
  
        int i = 0, j = 0; 
  
        int k = l; 
        while (i < n1 && j < n2) { 
            if (L[i] <= R[j]) { 
                arr[k] = L[i]; 
                i++; 
            } 
            else { 
                arr[k] = R[j]; 
                j++; 
            } 
            k++; 
        } 
  
        while (i < n1) { 
            arr[k] = L[i]; 
            i++; 
            k++; 
        } 
  
        while (j < n2) { 
            arr[k] = R[j]; 
            j++; 
            k++; 
        } 
        return arr;
    } 
}
