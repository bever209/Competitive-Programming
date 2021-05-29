#include <bits/stdc++.h>

#define pb push_back
#define f first
#define s second
#define mp make_pair

using namespace std;
using ll = long long;


const int mx = 2e5 + 5;
vector<ll> bit(1 + mx), arr(1 + mx); // arr contains actual values and bit is the BIT


void add(int ind, int v)
{
    for (; ind <= mx; ind += ind & (-ind))
    {
        bit[ind] += v;
    }
}
ll query(int ind)
{
    ll s = 0;
    for (; ind > 0; ind -= ind & (-ind))
    {
        s += bit[ind];
    }
    return s;
}
ll query(int l, int r)
{
    return query(r) - query(l - 1);
}

void set(int ind, int v)
{
    add(ind, -arr[ind]);
    arr[ind] = v;
    add(ind, arr[ind]);
}


int main()
{

    
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;
    string s;
    cin>>s;

    vector<int> list[26];
    for (int i=n-1;i>=0;--i){
        int ind=n-1-i;
        int b=s.at(i)-'a';
        list[b].pb(ind);
    }
    int x[n];
    for (int i=0;i<n;++i){
        int a=s.at(i)-'a';
        x[i]=list[a].front();
        list[a].erase(list[a].begin());
    }
    ll ans=0;
    /*for (int i:x){
        cout<<i<<" ";
    }
    cout<<endl;*/

    for (int i:x){
       // cout<<"hi "<<i<<endl;
        add(i+1,1);
        ans+=query(i+2,mx);
    }
    cout<<ans<<endl;
    

    return 0;
}