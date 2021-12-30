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

    int tc;cin>>tc;
    while (tc--){
        int n;cin>>n;
        int arr[n];
        for (int i=0;i<n;++i){
            cin>>arr[i];
        }
        if (n>3){
            cout<<"YES\n";
        }
        else{
            if (n==1){
                cout<<"YES\n";
            }
            else if (n==2){
                if (arr[0]>arr[1]){
                    cout<<"NO\n";
                }
                else{
                    cout<<"YES\n";
                }
            }
            else if (n==3){
                bool check=false;
                for (int t=0;t<4;++t){
                    bool works=true;
                    for (int i=t+1;i<t+n;++i){
                        if (arr[(i-1+n)%n]>arr[(i+n)%n]){
                            works=false;break;
                        }
                    }
                    if (works){
                        check=true;break;
                    }
                }
                if (check){
                    cout<<"YES\n";
                }
                else{
                    cout<<"NO\n";
                }

            }
        }
    }


    return 0;
}

