package algorithms;

import java.util.ArrayList;

public class floyd_t_and_h {
    static ArrayList<Integer>[]arr;
    public static void main(String[] args) {
        arr = new ArrayList[8];
        for (int i = 0; i < 8; i++) {
            arr[i] = new ArrayList<Integer>();
        }
        arr[0].add(1);
        arr[1].add(3);
        arr[3].add(6);
        arr[6].add(7);
        arr[7].add(2);
        arr[2].add(4);
        arr[4].add(0);
        alg();
    }
    public static void alg(){
        int a = arr[1].get(0);
        int b = arr[1].get(0);
        b=arr[b].get(0);
        while (a!=b){
            a=arr[a].get(0);
            b=arr[b].get(0);
            b=arr[b].get(0);
        }

        a=1;
        while (a!=b){
            a=arr[a].get(0);
            b=arr[b].get(0);
        }
        b = arr[a].get(0);
        int length=1;
        while (a!=b){
            b=arr[b].get(0);
            length++;
        }
        System.out.println(length); ////GIVES THE LENGTH OF THE CYCLE.
    }
}
