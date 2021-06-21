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
        int arr[n];
        for (int i=0;i<n;++i){
            cin>>arr[i];
        }

        int sum=0;
        for (int i:arr){
            sum+=i;
        }
        if (sum==n){
            cout<<0<<endl;
        }
        else if (sum<n){
            cout<<1<<endl;
        }
        else{
            cout<<sum-n<<endl;
        }

    }

    return 0;
}