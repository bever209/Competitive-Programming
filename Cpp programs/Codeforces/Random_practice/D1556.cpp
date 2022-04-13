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

    int q(str a,int b,int c){
        ++b;++c;
        cout<<a<<" "<<b<<" "<<c<<endl;
        int x;cin>>x;
        return x;
    }
    int sum(int b,int c){
        return q("or",b,c)+q("and",b,c);
    }

    int main() {


        ios::sync_with_stdio(false);
        cin.tie(0);
        int n,k;cin>>n>>k;

        int a=sum(0,1);int b=sum(1,2);int c=sum(0,2);
        vi ans(n);

        ans[1]=(a+b-c)/2;
        ans[0]=(a-b+c)/2;
        ans[2]=(b+c-a)/2;
        for (int i=3;i<n;++i){
            int x=sum(i-1,i);
            ans[i]=x-ans[i-1];
        }
        sort(ans.begin(),ans.end());
        cout<<"finish "<<ans[k-1]<<endl;



        return 0;
    }

