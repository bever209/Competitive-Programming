#include <bits/stdc++.h>

#define pb push_back
#define f first
#define s second
#define mp make_pair
#define pq priority_queue

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vivi = vector<vi>;
using vb = vector<bool>;
using vll = vector<ll>;
using vpii = vector<pii>;
using str = string;

const ll inf = 2 * 1e18;

int seg(vi a){
    vi x;
    for (int i=1;i<a.size();++i){
        if (a[i]!=a[i-1]) x.pb(a[i]);
    }
    return x.size();
}

int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vi a(n);
    for (int i=0;i<n;++i) cin>>a[i];

    vi s1;vi s2;

    vi next(n);
    vi ind(n+1,n+1);
    for (int i=n-1;i>=0;--i){
        next[i]=ind[a[i]];
        ind[a[i]]=i;
    }

    s1.pb(-1);
    s2.pb(-1);
    int n1=n+1;int n2=n+1;
    for (int i=0;i<n;++i){
        if (s1.back()==a[i]){
            s2.pb(a[i]);n2=next[i];
        }
        else if (s2.back()==a[i]){
            s1.pb(a[i]);n1=next[i];
        }
        else{
            if (n1<n2){
                s1.pb(a[i]);n1=next[i];
            }
            else{
                s2.pb(a[i]);n2=next[i];
            }
        }
    }
    cout<<seg(s1)+seg(s2)<<endl;


    return 0;
}


