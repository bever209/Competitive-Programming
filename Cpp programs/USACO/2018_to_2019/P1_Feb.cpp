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
using vb = vector<bool>;
using vll = vector<ll>;
using vpii = vector<pii>;
using str = string;
using vd=vector<double>;

const ll inf = 2 * 1e18;

int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("cowdate.in","r",stdin);
    freopen("cowdate.out","w",stdout);

    int n;cin>>n;
    vd x(n+1);
    for (int i=0;i<n;++i) cin>>x[i+1];

    for (int i=0;i<n;++i) x[i+1]=1.0*x[i+1]/1e6;

    vd a(n+1);
    a[0]=1;
    for (int i=1;i<=n;++i){
        a[i]=a[i-1]*(1-x[i]);
    }
    vd b(n+1);
    for (int i=1;i<=n;++i){
        b[i]=b[i-1]+(x[i]/(1-x[i]));
    }

    vi val(n+1);
    for (int i=1;i<=n;++i){
        double xx=1/x[i];
        int aa=(int)xx;
        val[i]=aa;
    }
    double ans=0;
    for (auto i:x) ans=max(ans,i);

    /*for (int i=1;i<=n;++i){
        for (int j=i;j<=n;++j){
            ans=max(ans,(a[j]/a[i-1])*(b[j]-b[i-1]));
        }
    }*/

    int j=1;double sum=0;
    for (int i=1;i<=n;){
        while (j<=n && sum<1){
            ans=max(ans,(a[j]/a[i-1])*(b[j]-b[i-1]));
            sum+=(x[j]/(1-x[j]));++j;
        }
        ans=max(ans,(a[j]/a[i-1])*(b[j]-b[i-1]));
        sum-=(x[i]/(1-x[i]));
        ++i;
        j=max(j,i);


    }
    cout<<(int)(ans*1e6)<<endl;



    return 0;
}

