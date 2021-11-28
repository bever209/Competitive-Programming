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

    int tc;
    cin>>tc;
    while (tc--){
        int n,k;
        cin>>n>>k;
        int arr[n];
        for (int i=0;i<n;++i){
            cin>>arr[i];
        }
        int arr2[n];
        for (int i=0;i<n;++i){
            arr2[i]=arr[i];
        }
        unordered_map<int,int> map;

        sort(arr2,arr2+n);
        for (int i=0;i<n;++i){
            map.insert({arr2[i],i});
        }
        int num=0;
        int ind=0;
        while (ind<n-1){
            int loc=map[arr[ind]];
            if (map[arr[ind+1]]==loc+1){
                ++ind;
            }
            else{
                ++num;++ind;
            }
        }


        if (num+1<=k){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }

    return 0;
}

