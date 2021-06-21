#include <bits/stdc++.h>

#define pb push_back
#define f first
#define s second
#define mp make_pair
#define pq priority_queue

using namespace std;
using ll = long long;
using pii = pair<int,int>;
struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1,T2> &p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);

        // Mainly for demonstration purposes, i.e. works but is overly simple
        // In the real world, use sth. like boost.hash_combine
        return 1000000*h1+h2;
    }
};


int main()
{


    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin>>t;
    for (int v=0;v<t;++v){
        int n;
        cin>>n;
        string s;
        cin>>s;
        unordered_map<pair<ll,ll>,ll,pair_hash> m;
        ll num_d=0;
        ll num_k=0;
        for (int i=0;i<n;++i){
            if (s.at(i)=='D'){
                num_d++;
            }
            else{
                num_k++;
            }
            ll gcd=__gcd(num_d,num_k);
            ll d=num_d;
            ll k=num_k;
            num_d/=gcd;
            num_k/=gcd;
            if (m.find({num_d,num_k})==m.end()){
                m[{num_d,num_k}]=1;
                cout<<"1 ";
            }
            else{
                ll num=m[{num_d,num_k}];
                ++num;
                cout<<num<<" ";
                m[{num_d,num_k}]=num;
            }
            num_d=d;
            num_k=k;
        }
        cout<<endl;



    }

    return 0;
}