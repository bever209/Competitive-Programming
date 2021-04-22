package Template;

public class NumberTheory {

    //////////// MAKE SURE TO MAKE EVERYTHING LONGS!!!!

    public static void main(String[] args){

    }

    public static long gcd(long a, long b){
        if (a==0){return b;}
        return gcd(b%a,a);
    }
    public static long[] egcd(long a, long b){
        if (a==0){
            return new long[] {b,0,1};
        }
        long[] arr=egcd(b%a,a);
        return new long[] {arr[0],arr[2]-b/a*arr[1],arr[1]};
    }
    public static long lcm(long a,long b){
        return a*b/gcd(a,b);
    }
    public static long InverseUsingExtendedGCD(long a, long b){return (b+egcd(a,b)[1])%b;}
    public static long InverseUsingTotient(long a, long b){
        long exp=b;
        long count=2;
        long x=b;
        while (count<=Math.sqrt(x)){
            if (b%count==0){
                exp=exp/count*(count-1);
                while (b%count==0){
                    b=b/count;
                }
            }
            count++;
        }
        if (b>0){exp=exp/b * (b-1);}
        return pow(a,exp-1,b)%b;
    }
    public static long pow(long a, long exp,long mod){ long ans=1;while (exp>0){ans=(ans*a)%mod;exp--;} return ans;}


}
