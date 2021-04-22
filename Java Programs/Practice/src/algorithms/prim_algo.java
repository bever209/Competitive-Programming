package algorithms;

import java.util.*;

public class prim_algo {
    static class Comp implements Comparator<int[]> {
        public int compare(int[] a, int[] b){
            return Integer.compare(a[2],b[2]);
        }
    }


    static boolean[] taken = new boolean[5];
    static PriorityQueue<int[]> pq = new PriorityQueue<int[]>(new Comp());  //USED PRIORITY QUEUE!!!!!
    public static void main(String[] args){
        Arrays.fill(taken,false);

        pq.add(new int[]{0, 1, 9});
        pq.add(new int[]{1,3,1});
        pq.add(new int[] {1,2,2});
        pq.add(new int[] {0,2,5});
        pq.add(new int[] {0,3,2});
        pq.add(new int[] {2,4,4});
        pq.add(new int[] {3,4,9});
        pq.add(new int[] {2,3,11});

        prim();
    }
    public static void prim(){
        int sum=0;
        int count=0;
        taken[0]=true;
       while(count<4){
           if (!taken[pq.peek()[0]] || !taken[pq.peek()[1]]) {
                sum = sum + pq.peek()[2];
                count++;
                pq.poll();
                }
            else{
                break;
            }
        }
        System.out.println(sum);
    }
}
