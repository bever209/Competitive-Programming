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


    int lcm=720720;
    for (int i=0;i<n;++i){
        for (int j=0;j<m;++j){
            int num=arr[i][j];
            if ((i+j)%2==0){
                arr[i][j]=lcm;
            }
            else{
                arr[i][j]=lcm+pow(num,4);
            }
        }
    }
    for (int i=0;i<n;++i){
        for (int j=0;j<m;++j){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }


    return 0;
}

