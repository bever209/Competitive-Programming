package data_structures;
//works, and is inclusive.
public class segment_tree {
    public static void main(String[] args){
        int[] list = {3,1,5,12,14,4,22,9,8,10};
        int a = list.length;
        int count=0;
        while (a>0){
            a=a/2;
            count++;
        }
        count++;

        int[] segment = new int[(int) Math.pow(2,count)];

        segment = create(list,segment,0,0,list.length-1);
        System.out.println(find(segment,0,0,list.length-1,1,3));

    }
    public static int[] create(int[] list, int[] segment, int node, int s,int e){
        if (s==e){

            segment[node]=list[s];
        }
        else{
            int mid=(s+e)/2;
            segment=create(list,segment,2*node+1,s,mid);

            segment=create(list,segment, 2*node+2,mid+1,e);
            segment[node]=segment[node*2+1]+segment[node*2+2];
        }
        return segment;
    }
    public static int find(int[] segment, int node,int snode, int lnode, int l, int r){

        if (r<snode||l>lnode){
            return 0;
        }
        if (snode>=l && lnode<=r){

            return segment[node];
        }
        else{
            int mid = (snode+lnode)/2;
            int a = find(segment,2*node+1,snode,mid,l,r);

            int b = find(segment,2*node+2,mid+1,lnode,l,r);

            return a+b;
        }
    }

}
