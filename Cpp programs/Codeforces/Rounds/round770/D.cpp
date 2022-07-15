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

int q(int i,int j,int k){
    ++i;++j;++k;
    cout<<"? "<<i<<" "<<j<<" "<<k<<endl;
    int x;cin>>x;
    return x;
}
void answer(int i,int j){
    ++i;++j;
    cout<<"! "<<i<<" "<<j<<endl;
}

int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;cin>>tc;
    while (tc--) {
        int n;
        cin >> n;

        int ind1 = 0;
        int ind2 = 1;
        vi a(n);
        for (int i = 2; i < n; ++i) {
            a[i] = q(ind1, ind2, i);
        }
        int maxind = 0;
        int mx = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] > mx) {
                mx = a[i];
                maxind = i;
            }
        }


        ind1 = maxind; // is a rando if 0,1 are 0,max and is 0 or max otherwise
        vi x(n);
        for (int i = 0; i < n; ++i) {
            if (i != ind1 && i != ind2) {
                x[i] = q(ind1, ind2, i);
            }
        }

        int maxind2 = 0;// is a rando if 1,maxind are 0,max and is the other of 0 or max (other than maxind/1) otherwise
        int m = 0;
        for (int i = 0; i < n; ++i) {
            if (x[i] > m) {
                m = x[i];
                maxind2 = i;
            }
        }
        // one of maxind,maxind2 is 0 or max

        if (maxind2==0){
            int ex=2;
            for (int i=2;i<n;++i){
                if (i!=maxind) ex=i;
            }
            int absmx=0;
            for (int i:a){
                absmx=max(absmx,i);
            }
            for (int i:x){
                absmx=max(absmx,i);
            }
            int a1= q(0,1,ex);
            int a2= q(0,maxind,ex);
            if (a1==absmx){
                answer(0,1);
            }
            else if (a2==absmx){
                answer(0,maxind);
            }
            else{
                answer(1,maxind);
            }

        }
        else{
            answer(maxind,maxind2);
        }





    }


    return 0;
}

