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
        if (n%2==0){
            for (int i=0;i<n;i+=2){
                cout<<i+2<<" "<<i+1<<" ";
            }
        }
        else{
            cout<<"3 1 2 ";
            for (int i=4;i<n;i+=2){
                cout<<(i+1)<<" "<<(i)<<" ";
            }
        }
        cout<<endl;
    }


    return 0;
}
