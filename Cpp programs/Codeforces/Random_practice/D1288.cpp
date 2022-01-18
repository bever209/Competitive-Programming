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

    int n,m;cin>>n>>m;
    int arr[n][m];
    for (int i=0;i<n;++i){
        for (int j=0;j<m;++j){
            cin>>arr[i][j];
        }
    }

    int low=0;
    int high=1e9;pii ans;
    while (low<high){
        int mid=(low+1+high)/2;
        set<int> s;
        vi order;
        for (int i=0;i<n;++i){
            int num=0;
            for (int j=0;j<m;++j){
                if (arr[i][j]>=mid){
                    num+=pow(2,j);
                }

            }
            order.pb(num);
            s.insert(num);
        }
        int n1,n2;
        bool check=false;
        for (int i:s){
            for (int j:s){
                if ((i|j)==pow(2,m)-1){
                    check=true;n1=i;n2=j;
                    break;
                }
            }
            if (check) break;
        }

        if (check){
            low=mid;
            for (int i=0;i<order.size();++i){
                if (order[i]==n1){
                    ans.f=i;
                }
                else if (order[i]==n2){
                    ans.s=i;
                }
            }
        }
        else{
            high=mid-1;
        }
    }
    cout<<ans.f+1<<" "<<ans.s+1<<endl;

    return 0;
}

