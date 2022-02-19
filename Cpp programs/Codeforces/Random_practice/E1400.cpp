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
vector<vi> mn;
int solve(int l,int r,int sub){
    if (l==r) {
        if (sub==arr[l]) return 0;
        return 1;
    }
    if (l>r) return 0;

    int ans=r-l+1;
    int ind=mn[l][r];
//    cout<<l<<" "<<r<<" "<<ind<<endl;

    ans=min(ans,arr[ind]-sub+solve(l,ind-1,max(arr[ind],sub))+solve(ind+1,r,max(arr[ind],sub)));
    return ans;




}

int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    arr.resize(n);
    for (int i=0;i<n;++i) cin>>arr[i];
    mn.resize(n,vi(n));
    for (int i=0;i<n;++i){
        mn[i][i]=i;
        for (int j=i+1;j<n;++j){
            mn[i][j]=mn[i][j-1];
            if (arr[j]<arr[mn[i][j]]){
                mn[i][j]=j;
            }
        }
    }

    cout<<solve(0,n-1,0);



    return 0;
}

