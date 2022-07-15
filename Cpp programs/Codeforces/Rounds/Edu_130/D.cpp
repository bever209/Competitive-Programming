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
char f(int ind){
    cout<<"? 1 "<<(ind+1)<<endl;
    char x;cin>>x;
    return x;
}
int s(int l,int r){
    cout<<"? 2 "<<(l+1)<<" "<<(r+1)<<endl;
    int x;cin>>x;
    return x;
}

int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    str ans="";
    for (int i=0;i<n;++i) ans+='?';

    vi prev_same(n,-1); // if there is no previous one that is same, it is -1, otherwise it is that index
    vi latest(26,n+1); // index of latest seen char from 'a' to 'z'

    char x=f(0);
    latest[x-'a']=0;
    ans[0]=x;
    for (int i=1;i<n;++i){
        vector<pair<int,char>> a;
        for (int i=0;i<26;++i){
            if (latest[i]<n) a.pb({latest[i],i+'a'});
        }
        sort(a.begin(),a.end());
        int len=a.size();
        int low=0;
        int high=len-1;
        while (low<high){
            int mid=(low+high+1)/2; // change accordingly
            int nn=s(a[mid].f,i);
            if (nn==1+len-mid){
                high=mid-1;
            }
            else{
                low=mid;
            }
        }
        if (s(a[low].f,i)==1+len-low){
            char aa=f(i);
            ans[i]=aa;
        }
        else{
            ans[i]=a[low].s;
        }
        latest[ans[i]-'a']=i;
    }
    cout<<"! "<<ans<<endl;

    return 0;
}

