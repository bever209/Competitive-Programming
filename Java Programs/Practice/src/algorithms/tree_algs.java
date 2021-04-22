package algorithms;
///////////////////General algorithms.
import java.util.ArrayList;

public class tree_algs {
    static ArrayList<Integer>[] arr;
    static int max=0;
    static int max_node=0;
    public static void main(String[] args){
        arr = new ArrayList[5];
        for (int i=0;i<5;i++){
            arr[i]=new ArrayList<Integer>();
        }
        arr[2].add(1);
        arr[1].add(2);
        arr[2].add(0);
        arr[0].add(2);
        arr[1].add(3);
        arr[3].add(1);
        arr[0].add(4);
        arr[4].add(0);
        max=0;
        find();
        System.out.println(max);
    }
    public static void find(){//Diameter of tree.
        dfs(0,-1,0);
        dfs(max_node,-1,0);
    }

    public static void dfs(int now,int before,int count){//DFS on tree + node furthest away.
        if (count>max){
            max_node=now;
            max=count;
        }
        for (int i:arr[now]){
            if (i!=before){
                dfs(i,now,count+1);
            }
        }
    }
}
