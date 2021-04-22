package data_structures2;

public class SegTree {
    public static int n; // SIZE OF ARRAY
    public static long[] t; // ARRAY
    // generally t has size 2*n
    public static void main(String[] args){

        // MAKE SURE TO INITIALIZE ARRAY AND THEN CALL BUILD FUNCTION
        // I think this is correct
        // does not implement lazy propagation, and this is bottom up
    }
    public static void build() { // build the tree
        for (int i = n - 1; i > 0; --i) t[i] = t[i << 1] + t[i << 1 | 1];
    }

    public static void set(int p, long value) { // set value at position p
        for (t[p += n] = value; p > 1; p >>= 1) t[p >> 1] = t[p] + t[p ^ 1]; }


    public static long query(int l, int r) { // l and r are inclusive
        r++;long res = 0;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if ((l & 1) != 0) res += t[l++];
            if ((r & 1) != 0) res += t[--r];
        }
        return res;
    }
}
