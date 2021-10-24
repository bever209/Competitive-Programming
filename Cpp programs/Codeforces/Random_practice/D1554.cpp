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
        int n;
        cin>>n;
        int k=n/2;
        if (n==1){
            cout<<'a';cout<<endl;continue;
        }

        if (n%2==1){
            for (int i=0;i<k;++i){
                cout<<'a';
            }
            cout<<"bc";
            for (int i=0;i<k-1;++i){
                cout<<'a';
            }
        }
        else{
            for (int i=0;i<k;++i){
                cout<<'a';
            }
            cout<<"b";
            for (int i=0;i<k-1;++i){
                cout<<'a';
            }
        }
        cout<<endl;
    }


    return 0;
}

