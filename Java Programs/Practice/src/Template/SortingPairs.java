package Template;

import java.util.*;

public class SortingPairs {
    public static class Pair{
        int x;
        int y;
        public Pair(int a,int b){
            x=a;
            y=b;
        }
    }

    // sorting class is below
    static class Comp implements Comparator<Pair> {
        public int compare(Pair a, Pair b){
            if (a.x==b.x){
                return Integer.compare(a.y,b.y);
            }
            return Integer.compare(a.x,b.x);
        }
    }
}
