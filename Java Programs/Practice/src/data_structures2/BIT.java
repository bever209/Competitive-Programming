package data_structures2;

public class BIT {
    static int n; // size of the array
    static long[] fwt; // generally set it to something like n+5
    static long[] arr;
    public static void main(String[] args){
        // Note that fwt is a static array
        // And when making the tree, use the add function
        // i.e. add the number to the certain index
        // And when finding sum of range, use query

        // use arr to store actual values of array
        // and when using set, make sure to change the value after the set call

        // ALSO NOTE THAT IT IS 1-INDEXED, MAKE A 0-INDEXED VERSION LATER
    }
    public static long query(int a, int b) {
        return sum(b) - sum(a - 1);
    } // range [a,b]
    public static long sum(int i) {
        long sum = 0;
        while (i > 0) {
            sum += fwt[i];
            i -= (i & -i); //least important bit
        }
        return sum;
    }
    public static void set(int i,long v){add(i,v-arr[i]);}
    public static void add(int i, long v) {
        while (i <=n) {
            fwt[i] += v;
            i += (i & -i);
        }
    }
}
