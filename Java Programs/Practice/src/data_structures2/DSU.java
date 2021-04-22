package data_structures2;

public class DSU {
    // when using you can keep in this class as
    // parent and height are already predetermined so it is probably
    // easier but make sure to think about it in real time
    static int[] parent;static int[] height;
    public static void init(int n){
        parent=new int[n];height=new int[n];
        for (int i=0;i<n;i++){ parent[i]=i;height[i]=0; }
    }
    public static int find(int node){
        if (parent[node]!=node){parent[node]=find(parent[node]); }
        return parent[node];
    }
    public static void union(int a, int b){
        int roota=find(a); int rootb=find(b);
        if (height[roota]>height[rootb]){
            parent[rootb]=roota;
            height[roota]=Math.max(height[roota],1+height[rootb]);
        }
        else{
            parent[roota]=rootb;
            height[rootb]=Math.max(height[rootb],1+height[roota]);
        }
    }
}
