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

    int n;int m;
    cin>>n>>m;
    if (n==1){
        if (m!=0){
            cout<<-1<<endl;
        }
        else{
            cout<<"1 3"<<endl;
        }
        return 0;
    }
    if (m<0 || m>=n-1){
        cout<<-1;return 0;
    }
    cout<<"1 1000000"<<"\n";
    int val=2;
    int nums=m+1;int c=n-1;
    while (nums>0){
        --nums;
        cout<<val<<" "<<val+1<<"\n";
        ++val;--c;++val;
    }
    int ind=1e8;
    while (c>0){
        --c;
        cout<<ind<<" "<<ind+1<<"\n";++ind;++ind;
    }



    return 0;
}

