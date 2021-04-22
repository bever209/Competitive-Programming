package data_structures;

public class sparse_table {////////////This is for range minimum queries.
    public static void main(String[] args){
        int[] list = {4,55,2,3,42,5,67,89,1,20,23,1343,23,2,33,5,6,29};
        int a = list.length;
        int b=a;
        int count=0;
        while (b>0){
            b=b/2;
            count++;
        }
        int[][] grid = new int[count][list.length];

        for (int i=0;i<=count;i++){
            int len = (int)Math.pow(2,i);
            for (int j=0;j+len<=a;j++){
                if (len==1){
                    grid[i][j]=list[j];
                }
                else{
                    grid[i][j]=Math.min(grid[i-1][j],grid[i-1][j+len/2]);
                }
            }
        }

        min(5,8,grid);////////////Indices are inclusive.

    }
    public static void min(int l, int r,int[][] grid){
        int a = r-l+1;
        int count=0;
        while (a>0){
            a=a/2;
            count++;
        }
        count--;
        int len = (int)Math.pow(2,count);
        System.out.println(Math.min(grid[count][l],grid[count][r-len+1]));

    }
}
