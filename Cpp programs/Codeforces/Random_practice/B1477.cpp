#include <bits/stdc++.h>

#define pb push_back
#define f first
//#define s second
#define mp make_pair
#define pq priority_queue

using namespace std;
using ll = long long;
using pii = pair<int,int>;
using vi = vector<int>;


const int N = 2e5 + 5; // limit for array size
const int n = 1;
ll tree[4 * N + 5];
ll arr[N];
ll lazy[4 * N + 5];
int mx=1e9;

void push(int node, int l, int r)
{
    if (lazy[node]<0){
        return;
    }
    tree[node] = lazy[node]*(r-l+1);
    if (l != r)
    {
        lazy[2 * node + 1] = lazy[node];
        lazy[2 * node + 2] = lazy[node];
    }

    lazy[node] = -1;
}
void comb(int node)
{
    tree[node] = (tree[node * 2 + 1]+ tree[2 * node + 2]);
}

void construct(int node, int l, int r)
{
    if (l == r)
    {
        tree[node] = arr[l];
    }
    else
    {
        int mid = (l + r) / 2;
        construct(node * 2 + 1, l, mid);
        construct(node * 2 + 2, mid + 1, r);
        comb(node);
    }
}
void construct()
{
    construct(0, 0, n - 1);
}

void set_val(int node, int l, int r, ll val, int lq, int rq)
{
    push(node, l, r);
    if (l > rq || r < lq)
    {
        return;
    }
    if (l >= lq && r <= rq)
    {
        lazy[node] = val;
        push(node, l, r);
        return;
    }
    int mid = (l + r) / 2;

    set_val(node * 2 + 1, l, mid, val, lq, rq);
    set_val(node * 2 + 2, mid + 1, r, val, lq, rq);
    comb(node);
}

void set_val(ll val, int lq, int rq)
{
    set_val(0, 0, n - 1, val, lq, rq);
}

ll query(int node, int l, int r, int lq, int rq)
{
    push(node, l, r);
    if (l > rq || r < lq)
    {
        return 0;
    }
    if (l >= lq && r <= rq)
    {
        return tree[node];
    }

    int mid = (l + r) / 2;

    return (query(node * 2 + 1, l, mid, lq, rq)+ query(node * 2 + 2, mid + 1, r, lq, rq));
}

ll query(int lq, int rq)
{
    return query(0, 0, n - 1, lq, rq);
}


int main()
{


    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin>>t;
    for (int i=0;i<4*N+5;++i){
        lazy[i]=-1;
    }
    for (int va=0;va<t;++va){

        int q;
        cin>>n>>q;
        string s;
        string e;
        cin>>s>>e;
        for (int i=0;i<s.length();++i){
            if (e[i]=='1'){
                arr[i]=1;
            }
            else{
                arr[i]=0;
            }
        }
        construct();
        vector<pii> ops;
        for (int i=0;i<q;++i){
            int a,b;
            cin>>a>>b;--a;--b;
            ops.pb({a,b});
        }
        bool check=true;
        for (int i=q-1;i>=0;--i){
            int a,b;
            a=ops[i].first;
            b=ops[i].second;
            int sum=query(a,b);
            int len=b-a+1;
            if (sum>len-sum){
                set_val(1,a,b);
            }
            else if (sum<len-sum){
                set_val(0,a,b);
            }
            else{
                check=false;break;
            }
        }
        bool check2=true;
        for (int i=0;i<n && check;++i){
            if (s[i]=='1' && query(i,i)==0){
                check2=false;break;
            }
            if (s[i]=='0' && query(i,i)==1){
                check2=false;break;
            }
        }
        if (check && check2){
            cout<<"YES"<<"\n";
        }
        else{
            cout<<"NO"<<"\n";
        }
        for (int i=0;i<4*n+5;++i){
            lazy[i]=-1;
            tree[i]=0;
            if (i<n){
                arr[i]=0;
            }
        }
    }

    return 0;
}
