package algorithms2;
import java.util.*;

public class Topo_Sort { // use as class or just only take sort function
    /////////////////////// also remember that this must be a DAG
    static int[] indeg;
    static ArrayList<Integer>[] arr;
    public static void init(ArrayList<Integer>[] a){
        int n=a.length;
        indeg=new int[n];arr=a;
        for (ArrayList<Integer> i:arr){
            for (int j:i){
                indeg[j]++;
            }
        }
    }
    public static ArrayList<Integer> sort(){
        ArrayList<Integer> ans=new ArrayList<>();
        Queue<Integer> q=new ArrayDeque<>();
        for (int i=0;i<indeg.length;i++){
            if (indeg[i]==0){
                q.add(i);
                ans.add(i);
            }
        }
        while (!q.isEmpty()){
            int node=q.poll();
            for (int next:arr[node]){
                indeg[next]--;
                if (indeg[next]==0){
                    q.add(next);
                    ans.add(next);
                }
            }
        }
        return ans;
    }
}
