package data_structures;

public class fenwick_trees {
    public static void main(String[] args) {
        int[] list = {3, 1, 5, 12, 14, 4, 22, 9, 8, 10};
        int[] fenwick = create(list);
        System.out.println(find_sum(fenwick,8));
    }
    public static int[] create(int[] list){//good
        int[] x = new int[list.length];
        for (int i=1;i<=list.length;i++){
            int a = (i)&(-(i));

            int sum=0;
            for (int j=i;j>=i-a+1;j--){
                sum=sum+list[j-1];
            }
            x[i-1]=sum;
        }
        return x;
    }
    public static int find_sum(int[] list, int ind){//works
        int count=0;

        while (ind>0){
            count=count+list[ind-1];
            ind=ind-((ind)&(-(ind)));
        }
        return count;
    }
}
