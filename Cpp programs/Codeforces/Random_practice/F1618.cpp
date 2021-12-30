#include <bits/stdc++.h>
#include <bitset>


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

bool check=false;

string to_bin(long long x)
{
    if(x == 0)
        return "";
    else
    {
        string s = to_bin(x / 2);
        s.push_back(char('0' + x % 2));
        return s;
    }
}

void in(string a,string b){
    int c=0;
    while (a.size()<b.size()){
        a=a+"1";++c;
    }
    for (int i=0;i<=c;++i){
        check=check || a==b;
        char z=a.at(a.size()-1);
        a=a.substr(0,a.size()-1);
        a=z+a;
    }

}

int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);

    ll a,b;cin>>a>>b;
    if (a==b) {cout<<"YES";return 0;}

    ll n1=a;
    while (n1%2==0){
        n1/=2;
    }
    ll n2=2*a+1;
    str x=to_bin(b);

    str y=to_bin(n1);
    str z=to_bin(n2);

    //cout<<x<<" "<<y<<" "<<z<<endl;
    in(y,x);
    in(z,x);

    reverse(y.begin(), y.end());
    reverse(z.begin(),z.end());
    in(y,x);
    in(z,x);

    if (check) {
        cout << "YES";
    }
    else{
        cout<<"NO";
    }


    return 0;
}

