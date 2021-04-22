package algorithms;
// WORKS
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;

public class bipartite_check {
    static ArrayList<Integer>[] arr;
    static boolean[] visit;
    static int[] color;
    public static void main(String[] args){
        arr = new ArrayList[5];
        for (int i = 0; i < 5; i++) {
            arr[i] = new ArrayList<Integer>();
        }
        visit = new boolean[5];
        color = new int[5];
        Arrays.fill(color,-1);
        color[0]=0;
        Arrays.fill(visit,false);
        arr[0].add(1);
        arr[0].add(2);
        arr[1].add(0);
        arr[2].add(0);
        arr[0].add(4);
        arr[4].add(0);
        //arr[3].add(4);
        //arr[4].add(3);
       //arr[3].add(0);
        //arr[0].add(3);
        check(0);

    }
    public static void check(int node){//BFS type code
        boolean is_b=true;
        Queue<Integer> q = new LinkedList<Integer>();
        q.add(node);
        while (!(q.isEmpty())&&is_b){
            int v =q.poll();
            for (int i:arr[v]){
                if (!visit[i]){
                    if (color[i]==-1){
                        color[i]=1-color[v];
                        q.add(i);
                    }
                    else{
                        if (color[i]==color[v]){
                            is_b=false;
                            break;

                        }
                }

                }
            }
        }
        System.out.println(is_b);

    }
}
