//package year_2020_2021;


import java.io.*;
import java.util.Arrays;
import java.util.HashSet;
import java.util.StringTokenizer;

public class s_Open_2_copy { // check for integer overflow
    static class InputReader {
        BufferedReader buffreader;
        StringTokenizer strtokenizer;
        public InputReader(InputStream inputstr) {
            buffreader = new BufferedReader(new InputStreamReader(inputstr), 1000000);strtokenizer = null; }
        //////////////////////////////////////////////////////////////////////////////////////////
        String next() {
            while (strtokenizer == null || !strtokenizer.hasMoreTokens()) {
                try { strtokenizer = new StringTokenizer(buffreader.readLine()); }
                catch (IOException e) { throw new RuntimeException(e); }
            }
            return strtokenizer.nextToken(); }
        ///////////////////////////////////////////////////////////////////////////////////////////
        public int nextInt() { return Integer.parseInt(next()); }
        public long nextLong() { return Long.parseLong(next()); }
        public double nextDouble() { return Double.parseDouble(next()); }
        public int[] nextIntArr(int n){
            int[] arr=new int[n];
            for (int i=0;i<n;i++){arr[i]=nextInt();}
            return arr;}
        public long[] nextLongArr(int n){
            long[] arr=new long[n];
            for (int i=0;i<n;i++){arr[i]=nextLong();}
            return arr;}
        public String[] nextStringArr(int n){
            String[] arr=new String[n];
            for (int i=0;i<n;i++){arr[i]=next();}
            return arr;}
    }
    static InputReader r = new InputReader(System.in);
    static PrintWriter pw = new PrintWriter(System.out);
    static HashSet<String> set=new HashSet<>();
    public static void main(String[] args){
        int t=r.nextInt();
        for (int v=0;v<t;v++){
            set.clear();
            int n=r.nextInt();
            int[] arr=r.nextIntArr(n);


            if (n==4){
                four(arr);
                pw.println(set.size());
            }
            else if (n==5){
                five(arr);
                pw.println(set.size());
            }
            else if (n==6){
                six(arr);
                pw.println(set.size());
            }
            else{
                seven(arr);
                pw.println(set.size());
            }
            for (String i:set){
                //System.out.println(v+" "+i);
            }







        }
        pw.close();







    }
    public static int four(int[] arr){
        int ans=0;Arrays.sort(arr);

        int[] x=new int[5];
        for (int i=0;i<arr.length;i++){ x[i]=arr[i]; }


        x[4]=arr[0]+arr[1]+arr[2];
        if (x[4]%2==0){
            x[4]=x[4]/2;ans+=five(x);        }
        System.out.println(Arrays.toString(arr));

        x[4]=arr[3]+arr[2]+arr[1];

        if (x[4]%2==0){x[4]=x[4]/2;
            ans+=five(x);}

        x[4]=arr[0]+arr[1]+arr[2];
        ans+=five(x);

        x[4]=arr[2]-arr[0];
        ans+=five(x.clone());

        x[4]=arr[3]-arr[0];
        ans+=five(x);

        x[4]=arr[2]-arr[1];
        ans+=five(x);


        x[4]=arr[3]-arr[1];
        ans+=five(x);


        int a=arr[0];
        int b=arr[1]-arr[0];
        int c=arr[3]-a-b;
        x[4]=a;ans+=five(x);
        x[4]=b;ans+=five(x);
        x[4]=c;ans+=five(x);
        x[4]=a+b;ans+=five(x);
        x[4]=b+c;ans+=five(x);
        x[4]=a+c;ans+=five(x);

        a=arr[0];
        b=arr[2]-arr[0];
        c=arr[3]-a-b;
        x[4]=a;ans+=five(x);
        x[4]=b;ans+=five(x);
        x[4]=c;ans+=five(x);
        x[4]=a+b;ans+=five(x);
        x[4]=b+c;ans+=five(x);
        x[4]=a+c;ans+=five(x);



        return ans;





    }
    public static int five(int[] arr){


        Arrays.sort(arr);int ans=0;
        int[] x=new int[6];
        for (int i=0;i<5;i++){
            x[i]=arr[i];
        }
        x[5]=(arr[4]+arr[3]+arr[2]);
        if (x[5]%2==0) { x[5]=x[5]/2;ans += six(x); }
        x[5]=(arr[0]+arr[1]+arr[2]);ans+=six(x);


        int a=arr[4]-arr[3];
        int b=arr[0];
        if (b==a){ b=arr[1]; }

        int c=arr[4]-a-b;

        x[5]=a;ans+=six(x);x[5]=b;ans+=six(x);x[5]=c;ans+=six(x);
        x[5]=a+b;ans+=six(x);x[5]=b+c;ans+=six(x);x[5]=a+c;ans+=six(x);
        return ans;




    }
    public static int six(int[] arr){

        int ans=0;
        Arrays.sort(arr);
        int[] x=new int[7];
        for (int i=0;i<6;i++){
            x[i]=arr[i];
        }

        x[6]=arr[0]+arr[1]+arr[2];ans+=seven(x); // a+b+c missing
        int a=arr[5]-arr[4];int b=arr[5]-arr[3];int c=arr[5]-a-b;
        x[6]=a;ans+=seven(x);x[6]=b;ans+=seven(x);x[6]=c;ans+=seven(x); // a or b or c missing
        x[6]=a+b;ans+=seven(x);x[6]=b+c;ans+=seven(x);x[6]=a+c;ans+=seven(x); // pairwise sum missing
        return ans;



    }

    public static int seven(int[] arr){
        Arrays.sort(arr);
        int a=arr[0];
        int b=arr[1];
        int c=arr[arr.length-1]-a-b;

        int[] x=new int[]{a,b,c,a+b,b+c,a+c,a+b+c};
        Arrays.sort(x);
        if (equals(x,arr) && x[0]>0){
            set.add(a+" "+b+" "+c+" "+(a+b)+" "+(a+c)+" "+(b+c)+" "+(a+b+c));
            //System.out.println(Arrays.toString(arr));
            return 1;
        }
        return 0;


    }
    public static boolean equals(int[] arr1,int[] arr2){
        for (int i=0;i<arr1.length;i++){
            if (arr1[i]!=arr2[i]){
                return false;
            }
        }
        return true;
    }
    public static boolean in(int[] arr,int num){
        for (int i:arr){
            if (i==num){
                return true;
            }
        }
        return false;
    }
}
