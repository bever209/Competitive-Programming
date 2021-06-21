#include <bits/stdc++.h>

#define pb push_back
#define f first
#define s second
#define mp make_pair
#define pq priority_queue

using namespace std;
using ll = long long;
using pii = pair<int,int>;
using vi = vector<int>;

int main()
{


    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin>>t;
    for (int v=0;v<t;++v){
        int n;
        cin>>n;
        string x;
        cin>>x;
        ++n;
        int dpl[n];
        int dpr[n];
        for (int i=0;i<n;++i){
            dpl[i]=dpr[i]=0;
        }
        if (x.at(0)=='L'){
            dpl[1]=1;
        }
        for (int i=2;i<n;++i){
            if (x.at(i-1)=='L' && x.at(i-2)=='R'){
                dpl[i]=dpl[i-2]+2;
            }
            else if (x.at(i-1)=='L'){
                dpl[i]=1;
            }
        }
        if (x.at(n-2)=='R'){
            dpr[n-2]=1;
        }
        for (int i=n-3;i>=0;--i){
            if (x.at(i)=='R' && x.at(i+1)=='L'){
                dpr[i]=dpr[i+2]+2;
            }
            else if (x.at(i)=='R'){
                dpr[i]=1;
            }
        }
        for (int i=0;i<n;++i){
            cout<<dpl[i]+1+dpr[i]<<" ";
        }
        cout<<endl;
    }

    return 0;
}