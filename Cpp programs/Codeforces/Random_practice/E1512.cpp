#include <bits/stdc++.h>

#define pb push_back
#define f first
#define s second
#define mp make_pair
#define pq priority_queue

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using str = string;

const ll inf = 2 * 1e18;
vi arr;
vector<vi> dp;
int calc(int l,int r){ // 0-indexed
    if (dp[l][r]!=0){
        return dp[l][r];
    }
    if (l==r){
        dp[l][r]=arr[l];
        return arr[l];
    }
    for (int mid=l;mid<r;++mid){
        int a=calc(l,mid);
        int b=calc(mid+1,r);
        if (a==b && a>0){
            dp[l][r]=a+1;
            return a+1;
        }
    }
    dp[l][r]=-1;
    return -1;
}

int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);


    int n;
    cin>>n;
    arr.resize(n);
    for (int i=0;i<n;++i){
        cin>>arr[i];
    }

    dp.resize(n+1,vector<int>(n+1,0));
    vi dp2(n+1);


    for (int i=0;i<=n;++i){
        dp2[i]=i;
    }
    for (int i=1;i<=n;++i){
        for (int j=i;j<=n;++j){
            if (calc(i-1,j-1)>0){
                dp2[j]=min(dp2[j],dp2[i-1]+1);
            }
        }
    }

    cout<<dp2[n];



    return 0;
}

