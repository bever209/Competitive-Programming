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
using str=string;

const ll inf=2*1e18;

int main()
{


    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin>>tc;
    while (tc--){
        int n;cin>>n;
        int arr[n][5];
        for (int i=0;i<n;++i){
            for (int j=0;j<5;++j){
                cin>>arr[i][j];
            }
        }
        int sup=0;
        for (int i=1;i<n;++i){
            int numsup=0;
            for (int j=0;j<5;++j){
                if (arr[i][j]<arr[sup][j]){
                    ++numsup;
                }
            }
            if (numsup>=3){
                sup=i;
            }

        }
        bool check=true;
        for (int i=0;i<n;++i){
            if (i!=sup){
                int numsup=0;
                for (int j=0;j<5;++j){
                    if (arr[i][j]<arr[sup][j]){
                        ++numsup;
                    }
                }
                if (numsup>=3){
                    check=false;break;
                }
            }
        }
        if (check){
            cout<<sup+1<<endl;
        }
        else{
            cout<<-1<<endl;
        }


    }


    return 0;
}

