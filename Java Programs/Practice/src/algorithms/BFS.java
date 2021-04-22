package algorithms;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;

public class BFS {
    public static void main(String[] args) {
        ArrayList<Integer>[] arr = new ArrayList[4];
        for (int i = 0; i < 4; i++) {
            arr[i] = new ArrayList<Integer>();
        }
        arr[0].add(1);
        arr[0].add(2);
        arr[1].add(0);
        arr[1].add(3);
        arr[2].add(0);
        arr[3].add(1);
        search(0,arr);
    }
    public static void search(int node,ArrayList<Integer>[] list){
        int[] dist = new int[4];
        Arrays.fill(dist,-1);
        Queue<Integer> q = new LinkedList<Integer>();
        dist[node]=0;
        q.add(node);
        while (!(q.isEmpty())){
            int v =q.poll();
            for (int i:list[v]){
                if (dist[i]==-1){
                    dist[i]=dist[v]+1;
                    q.add(i);
                }
            }
        }
        for (int i:dist){
            System.out.println(i);
        }
    }
}
