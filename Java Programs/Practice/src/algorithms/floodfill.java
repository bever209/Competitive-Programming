package algorithms;

import java.util.Arrays;
import java.util.Scanner;

public class floodfill {
    static int[][] grid;
    static int n;
    static int m;
    static int size;
    static boolean[][] check;

    public static void main(String[] args){
        Scanner s = new Scanner(System.in);
         n = 3;
         m=4;
        grid = new int[n][m];
        for (int i=0;i<grid.length;i++){
            Arrays.fill(grid[i],i);
        }

        check=new boolean[n][m];
        for (int i=0;i<check.length;i++){
            Arrays.fill(check[i],false);
        }
        grid[0][2]=3;
        for (int i=0;i<n;i++){
            for (int k=0;k<m;k++){

                if (!check[i][k]){
                    size=0;
                    fill(i,k,grid[i][k]);
                    System.out.println(size);
                }
            }
        }


    }
    public static void fill(int i,int j,int color){

        if (i<0 || i>=n||j<0||j>=m){

            return;
        }
        if (check[i][j]){
            return;
        }
        if (grid[i][j]!=color){
            return;
        }

        check[i][j]=true;
        size++;

        fill(i+1,j,color);
        fill(i-1,j,color);
        fill(i,j+1,color);
        fill(i,j-1,color);
    }
}
