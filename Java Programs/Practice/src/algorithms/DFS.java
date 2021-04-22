package algorithms;

import java.util.ArrayList;

public class DFS {
    public static void main(String[] args){
        ArrayList<Integer>[] arr = new ArrayList[4];
        for (int i=0;i<4;i++){
            arr[i]=new ArrayList<Integer>();
        }


        int[] check = new int[4];
        for (int i=0;i<check.length;i++){
            check[i]=-1;
        }
        for (int i=0;i<4;i++){
            if (check[i]==-1){
                check[i]=1;
                count++;
                search(i,arr,check);
            }
        }
        System.out.println(count);
    }
    static int count=0;
    public static void search(int node,ArrayList<Integer>[] list, int[] check){
        check[node]=1;
        //System.out.println(node);
        for (int i:list[node]){
            if (check[i]==-1){
                check[i]=1;
                search(i,list,check);

            }

        }
    }
}
