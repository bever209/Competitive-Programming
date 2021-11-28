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
#define int long long
    int t;cin>>t;
    for (int va=0;va<t;++va){
        int n;
        cin>>n;
        int arr[n];
        for (int i=0;i<n;++i){
            cin>>arr[i];
        }
        int sum=0;
        for (int i:arr){
            sum+=i;
        }
        int mod=sum%n;
        cout<<mod*(n-mod)<<endl;

    }

    return 0;
}