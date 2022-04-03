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

int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    int arr[n];
    for (int i=0;i<n;++i) cin>>arr[i];
    vector<bool> in(1e6+5);
    for (int i:arr) in[i]=true;
    vector<vi> b(1e6+5);

    for (int i=1;i<b.size();++i){
        int g=0;
        for (int j=i;j<b.size();j+=i){
            if (in[j]) g=gcd(g,j);
        }
        if (g==i) in[i]=true;
    }
    int c=0;
    for (int i=0;i<in.size();++i){
        if (in[i]==true)++c;
    }
    cout<<c-n;


    return 0;
}

