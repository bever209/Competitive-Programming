package data_structures2;
// WORKS
public class SegTreeTopDown {
    public static int n; // SIZE OF ARRAY
    public static long[] t; // seg tree
    public static long[] arr; // actual values of the array
    public static long[] add; // lazy array

    // generally t has size 2*n
    public static void main(String[] args) {

        // MAKE SURE TO INITIALIZE ARRAY AND THEN CALL BUILD FUNCTION
        // t is 1-indexed
        // implements lazy propagation
    }

    // l and r are inclusive
    public static void build(){ build(1,0,n-1); }
    public static void build(int ind, int l, int r) { // build the tree
        if (l==r){ t[ind]=arr[l]; return;}
        int m=(l+r)/2;
        build(2*ind,l,m);build(2*ind+1,m+1,r);
        t[ind]=t[2*ind]+t[2*ind+1];
    }
    public static void push(int ind,int l,int r){
        if (l!=r){
            add[2*ind]+=add[ind];add[2*ind+1]+=add[ind];
        }
        t[ind]+=add[ind]*(r-l+1);
        add[ind]=0; }

    public static void add(int l, int r, long value) { // set value at position p
        add(l,r,value,0,n-1,1);
    }
    public static void add(int l, int r, long  value, int x, int y, int ind){// x and y are the left and right for the node we are on
        push(ind,x,y);
        if (r<x || l>y){ return; }
        if (l<=x && r>=y){ add[ind]+=value;push(ind,x,y);return; }
        int mid=(x+y)/2;
        add(l,r,value,x,mid,2*ind);
        add(l,r,value,mid+1,y,2*ind+1);
    }

    public static long query(int l, int r){ return query(l,r,0,n-1,1); }
    public static long query(int l, int r,int x, int y,int ind) {
        push(ind,x,y);
        if (r<x || l>y){ return 0; }
        if (l<=x && r>=y){ return t[ind];}
        int mid=(x+y)/2;
        return query(l,r,x,mid,2*ind)+query(l,r,mid+1,y,2*ind+1);
        // x and y denote the left and right of the node we are at
    }
}
