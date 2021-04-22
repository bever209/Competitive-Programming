package algorithms;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;

public class min_distance_unweighted {
    static int[] distance = new int[6];
    static int[] pred = new int[6];
    static ArrayList<Integer>[] arr = new ArrayList[6];
    public static void main(String[] args){
        for (int i = 0; i < 6; i++) {
            arr[i] = new ArrayList<Integer>();
        }
        Arrays.fill(distance,-1);
        arr[0].add(1);
        arr[0].add(2);
        arr[1].add(0);
        arr[1].add(3);
        arr[2].add(0);
        arr[3].add(1);
        arr[4].add(3);
        arr[5].add(3);
        arr[5].add(4);
        arr[3].add(4);
        arr[3].add(5);
        arr[4].add(5);

        find(0,2);
    }
    public static void find(int s, int e){
        distance[s]=0;
        pred[s]=s;
        LinkedList<Integer> q = new LinkedList<Integer>();  //LINKED LIST IS FASTER THAN QUEUE! (IN THIS CASE)

        q.add(s);
        while(distance[e]==-1){
            int v = q.poll();
            for (int i:arr[v]){
                if (distance[i]==-1) {
                    q.add(i);
                    pred[i] = v;
                    distance[i] = distance[v] + 1;
                }
            }
        }

        System.out.println("Distance: "+distance[e]);
        while (pred[e]!=s){
            System.out.println(pred[e]);
            e=pred[e];
        }
        System.out.println(s);
    }
}
