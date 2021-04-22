package data_structures;
import java.util.*;
public class bs_tree_inorder_traversal {

    public static void main(String[] args){
        ArrayList<Integer> list = new ArrayList<Integer>();
        // add in the values

        list.add(6);
        list.add(5);
        list.add(7);
        list.add(2);
        list.add(5);
        list.add(8);
        inorder(list,0);
    }
    public static void inorder(ArrayList<Integer> list,int ind){
        if (ind<list.size()-1){
        inorder(list,2*ind+1);
        System.out.println(list.get(ind));
        inorder(list,2*ind+2);}

    }
}
