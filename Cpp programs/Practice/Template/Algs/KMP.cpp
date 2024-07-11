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


vi kmp(str a){
    vi x(a.size());
    for (int i=1;i<a.size();++i){
        int j=x[i-1];
        while (j>0 && a[j]!=a[i]) j=x[j-1];

        if (a[i]==a[j]) ++j;
        x[i]=j;

    }
    return x;
}

