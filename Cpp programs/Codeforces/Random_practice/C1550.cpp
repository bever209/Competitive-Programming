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

bool check(int a,int b,int c,int d){ // returns true if this sequence is good
    if (a<=b && b<=c) return false;
    if (a>=b && b>=c) return false;
    if (a<=b && b<=d) return false;
    if (a>=b && b>=d) return false;
    if (b<=c && c<=d) return false;
    if (b>=c && c>=d) return false;
    if (a<=c && c<=d) return false;
    if (a>=c && c>=d) return false;
    return true;
}
bool check(int a,int b,int c){
    if (a<=b && b<=c) return false;
    if (a>=b && b>=c) return false;
    return true;
}

int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;cin>>tc;
    while (tc--){
        int n;cin>>n;int arr[n];
        for (int i=0;i<n;++i) cin>>arr[i];
        int ans=0;
        for (int i=0;i<n;++i){
            int right=i+3;
            if (right>=n){
                --right;
                if (right<n){
                    if (check(arr[i],arr[i+1],arr[i+2])){
                        ans+=3;
                    }
                    else{
                        ans+=2;
                    }
                }
                else{
                    ans+=(n-i);
                }
            }
            else{
                if (check(arr[i],arr[i+1],arr[i+2],arr[i+3])){
                    ans+=4;
                }
                else{
                    --right;
                    if (check(arr[i],arr[i+1],arr[i+2])){
                        ans+=3;
                    }
                    else{
                        ans+=2;
                    }
                }
            }

        }
        cout<<ans<<endl;

    }


    return 0;
}

