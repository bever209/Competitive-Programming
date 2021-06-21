#include <bits/stdc++.h>

#define pb push_back
#define f first
#define s second
#define mp make_pair
#define pq priority_queue

using namespace std;
using ll = long long;
using pii = pair<int,int>;

int main()
{

    
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;
    int arr[n];
    for (int i=0;i<n;++i){
        cin>>arr[i];
    }

    pq<int> q;
    ll sum=0;int ans=0;
    for (int i=0;i<n;++i){
        if (arr[i]>=0){
            q.push(-arr[i]);
            sum+=arr[i];
            ++ans;
        }
        else{
            if (arr[i]+sum<0){
                if (q.size()>0) {
                    int val = -q.top();
                    if (val < arr[i]) {
                        q.pop();
                        sum -= val;
                        q.push(-arr[i]);
                        sum += arr[i];
                    }
                }
            }
            else{
                q.push(-arr[i]);
                ++ans;sum+=arr[i];
            }
        }
    }
    cout<<ans<<endl;

    return 0;
}