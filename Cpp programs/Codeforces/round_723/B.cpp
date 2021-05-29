#include <bits/stdc++.h>

#define pb push_back
#define f first
#define s second
#define mp make_pair

using namespace std;
using ll = long long;

int main()
{

    
    ios::sync_with_stdio(false);
    cin.tie(0);


    int t;
    cin>>t;
    for (int v=0;v<t;++v){
        int n;
        cin>>n;
        if (n%11==0){
            cout<<"YES"<<endl;continue;
        }

        if (n>111*11){
            cout<<"YES"<<endl;continue;
        }
        bool check=false;
        while (true){
            if (n%11==0){
                check=true;break;
            }
            n=n-111;
            if (n<0){
                break;
            }
        }
        if (check){
            cout<<"YES"<<endl;continue;
        }
        else{
            cout<<"NO"<<endl;continue;

        }

    }

    return 0;
}