package algorithms2;
import java.util.*;
// works
public class Dijkstra {
    public static class Pair{
        int x;
        int y;
        public Pair(int a,int b){
            x=a;
            y=b;
        }
    }
    // When implementing, move the Pair class out of this class
    // also x value means weight and y value means node
    public static int[] calc(ArrayList<Pair>[] arr,int node){
        int inf=2009900000;
        int[] ans=new int[arr.length];Arrays.fill(ans,inf);ans[node]=0;
        PriorityQueue<Pair> q=new PriorityQueue<>(Comparator.comparingInt(o->-o.x));
        q.add(new Pair(0,node));
        boolean[] visit=new boolean[arr.length];
        while (!q.isEmpty()){
            int a=q.poll().y;
            if (!visit[a]){
                visit[a]=true;
                for (Pair i:arr[a]){
                    int b=i.y;int w=i.x;
                    if (ans[a]+w<ans[b]){
                        ans[b]=ans[a]+w;
                        q.add(new Pair(-ans[b],b));
                    }
                }
            }
        }

        return ans;
    }
}
