#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    freopen("gymnastics.in","r",stdin);
	freopen("gymnastics.out","w",stdout);

    int n;int k;
    cin>>k>>n;
    
    int arr[k][n];

    for (int i=0;i<k;++i){
        for (int j=0;j<n;++j){
            cin>>arr[i][j];
        }
    }
    int ans=0;

    for (int i=1;i<=n;++i){
        for (int j=1;j<=n;++j){
            if (i==j) continue;
            bool check=true;int ind1;int ind2;
            for (int a=0;a<k;++a){
                for (int b=0;b<n;++b){
                    if (arr[a][b]==i){ind1=b;}
                    if (arr[a][b]==j){ind2=b;}
                }
                if (ind1>ind2){
                    check=false;
                }
            }
            if (check){ans++;}
        }
    }
    cout<<ans;









    return 0;
}