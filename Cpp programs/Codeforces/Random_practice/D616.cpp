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

    int n,k;
    cin>>n>>k;
    int arr[n];
    for (int i=0;i<n;++i){
        cin>>arr[i];
    }
    int left=0;int right=0;
    pii ans={left,right};
    unordered_map<int,int> map;
    while (right<n){
        if (map.size()<=k){
            int a=arr[right];
            auto x=map.find(a);
            if (x!=map.end()){
                ++map[a];
            }
            else{
                map[a]=1;
            }
            if (map.size()<=k){
                int len1=ans.s-ans.f+1;
                int len2=right-left+1;
                if (len2>len1){
                    ans.f=left;ans.s=right;
                }
            }
            ++right;
        }
        while (map.size()>k){
            int x=arr[left];
            --map[x];
            if (map[x]==0){
                map.erase(x);
            }
            ++left;
        }


    }
    if (ans.s==n){
        cout<<ans.f+1<<" "<<ans.s<<endl;
    }
    else{
        cout<<ans.f+1<<" "<<ans.s+1<<endl;
    }

    return 0;
}