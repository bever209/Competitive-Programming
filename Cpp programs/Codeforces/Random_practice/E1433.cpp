#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(0);

    int x; cin>>x;

    long long ans=1;
    int y=x;
    while (y>0){
        ans*=y;--y;
    }
    ans=ans/(x*x/2);
    cout<<ans<<"\n";

    






    return 0;
}