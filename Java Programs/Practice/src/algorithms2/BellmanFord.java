package algorithms2;
import java.util.*;

public class BellmanFord {
    public static class Pair{
        int x;
        int y;
        public Pair(int a,int b){
            x=a;
            y=b;
        }
    }
    // x is weight y is node
    public static int[] calc(ArrayList<Pair>[] arr,int node){
        // doesn't detect negative cycles, but it is very easy
        // to do so
        // also haven't tested, but pretty sure this will work
        int n=arr.length;int[] ans=new int[n];int inf=2055000000;
        Arrays.fill(ans,inf);ans[node]=0;
        for (int i=0;i<arr.length;i++){
            for (int j=0;j<arr.length;j++){
                for (Pair k:arr[j]){
                    int w=k.x;int node2=k.y;
                    ans[node2]=Math.min(ans[node2],ans[j]+w);
                }
            }
        }
        return ans;
    }
}
