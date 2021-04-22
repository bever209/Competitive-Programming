package algorithms;
///////////////////////////////////////////WORKS!
import java.util.ArrayList;
import java.util.Arrays;

public class bellman_ford {
    static class Pair{
        int a;
        int b;
        public Pair(int x, int y){
            a=x;
            b=y;
        }
    }
    static int[] prev = new int[5];
    static int[] dist = new int[5];
    static ArrayList<Pair>[] list=new ArrayList[5];
    public static void main(String[] args) {

        Arrays.fill(dist, -1);
        Arrays.fill(prev,-1);

        for (int i = 0; i < 5; i++) {
            list[i] = new ArrayList<Pair>();
        }
        list[0].add(new Pair(1, 2));
        list[0].add(new Pair(2, 5));
        list[2].add(new Pair(0,0));
        list[1].add(new Pair(3, 1));
        list[1].add(new Pair(2, -8));
        list[2].add(new Pair(4, 5));
        list[2].add(new Pair(3, 11));
        list[3].add(new Pair(4, 9));
        find(0,4);
    }
    public static void find(int ind1,int ind2){
        dist[ind1]=0;
        for (int i=0;i<5;i++){
            for (Pair j:list[i]){
                int temp = dist[i]+j.b;
                if (temp<dist[j.a] || dist[j.a]==-1){
                    dist[j.a]=temp;
                    prev[j.a]=i;
                }
            }
        }
        boolean check=true;
        for (int i=0;i<list.length;i++){
            for (Pair j:list[i]){
                if (dist[i]+j.b<dist[j.a]){
                    System.out.println("Error, negative cycle detected.");
                    check=false;
                    break;
                }
            }
            if (!check){
                break;
            }
        }
        if (check) {
            System.out.println(dist[ind2]);
        }
    }
}
