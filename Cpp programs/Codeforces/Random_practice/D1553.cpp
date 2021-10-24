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

    int tc;cin>>tc;
    while (tc--){
        string s,t;
        cin>>s>>t;
        if (t.length()>s.length()){
            cout<<"no"<<endl;
        }
        else if (t.length()==s.length()){
            if (t==s){
                cout<<"yes"<<endl;
            }
            else{cout<<"no"<<endl;}
        }
        else{
            int p1=s.length()-1;int p2=t.length()-1;
            while (p1>=0 && p2>=0){
                //cout<<p1<<" "<<p2<<endl;
                if (s[p1]==t[p2]){
                    --p2;--p1;
                }
                else{
                    p1-=2;
                }

            }
            if (p2<0){
                cout<<"yes"<<endl;
            }
            else{
                cout<<"no"<<endl;
            }
        }
    }

    return 0;
}

