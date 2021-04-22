package algorithms;
import java.util.*;
////////////////////////WORKS!!!!!
public class Dijkstra_algo {
    static class Pair{
        int a;
        int b;
        public Pair(int x, int y){
            a=x;
            b=y;
        }
    }
    static class Comp implements Comparator<Pair> {
        public int compare(Pair a, Pair b){
            return Integer.compare(a.b,b.b);
        }
    }

    static int[] dist = new int[5];
    static PriorityQueue<Pair> pq = new PriorityQueue<Pair>(new Comp());
    static ArrayList<Pair>[] list=new ArrayList[5];
    public static void main(String[] args){

        Arrays.fill(dist,-1);
        for (int i=0;i<5;i++){
            list[i]=new ArrayList<Pair>();
        }
        list[0].add(new Pair(1,6));
        list[0].add(new Pair(2,5));

        list[1].add(new Pair(3,1));
        list[1].add(new Pair(2,2));
        list[2].add(new Pair(4,5));
        list[2].add(new Pair(3,11));
        list[3].add(new Pair(4,9));
        find(0,3);
    }
    public static void find(int ind1, int ind2){
        dist[ind1]=0;
        pq.add(new Pair(ind1,0));
        while (!pq.isEmpty()){
            Pair pair = pq.poll();

            if (pair.b<dist[pair.a]||dist[pair.a]==-1) {
                dist[pair.a] = pair.b;
            }
            for (Pair j:list[pair.a]){
                if (dist[j.a]==-1){

                    pq.add(new Pair(j.a,pair.b+j.b));
                }
            }

        }

        System.out.println(dist[ind2]);
    }

}
