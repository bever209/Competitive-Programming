package Template;

import java.util.*;

public class Sorting2DLists {
    static class Comp implements Comparator<int[]> {
        public int compare(int[] a, int[] b){
            for (int i = 0; i < a.length; ++i)
                if (a[i] != b[i]) return Integer.compare(a[i],b[i]);
            return 0;
        }
    }

}
