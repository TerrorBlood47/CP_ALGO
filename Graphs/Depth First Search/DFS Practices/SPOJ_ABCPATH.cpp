// link - https://www.spoj.com/problems/ABCPATH/

//ans still not accepted, but all the custom test cases are satisfied
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll dist[51][51] ;

ll dfs(char c, vector<vector<char>>&g, int i, int j,ll len, ll ans){

    if(i<0 || i>=g.size() || j<0 || j>=g[0].size()) return ans;

    //if(g[i][j]=='#') return 0;

    if(dist[i][j] > len) return ans;

    if(c != g[i][j]) {
        //g[i][j] = '#';
        return ans;
    }

    
    char a = g[i][j];
    char b;
    
    if(a != 'Z') {
        b = char((int)a+1);
    }
    else{
        b = 'A';
    }
    //cout<<ans<<endl;
    //g[i][j] = '#';

    //int ans = 0;
    ans++;
    dist[i][j] = ans;

    ans = max(ans , dfs(b, g, i, j+1 , dist[i][j],dist[i][j]));
    ans = max(ans , dfs(b, g, i, j-1,dist[i][j],dist[i][j]));
    ans = max(ans, dfs(b, g, i+1, j,dist[i][j], dist[i][j]));
    ans = max(ans , dfs(b, g, i-1, j ,dist[i][j], dist[i][j]));
    ans = max(ans , dfs(b, g, i+1, j+1, dist[i][j], dist[i][j]));
    ans = max(ans , dfs(b, g, i+1, j-1, dist[i][j], dist[i][j]));
    ans = max(ans, dfs(b, g, i-1, j+1, dist[i][j], dist[i][j]));
    ans = max(ans, dfs(b, g, i-1, j+1, dist[i][j], dist[i][j]));


    return ans;
}

void print(vector<vector<char>>&g){

    for(int i=0; i<g.size(); i++){
        for(int j=0; j<g[0].size(); j++){
            cout<<g[i][j]<<" ";
        }
        cout<<endl;
    }
}


int main(){

int t = 1;
while(47){
    int h,w;
    
    scanf("%d%d",&h,&w);

    if(h==0 and w==0)return 0;

    vector<vector<char>> g(h);

    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            char c;
            cin>>c;
            g[i].push_back(c);
            dist[i][j] = 0;
        }
    }
    ll ans = 0;

    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){

            if(g[i][j] == 'A' and dist[i][j]==0){

                //if(g[i][j] != '#'){
                    ll m = dfs(g[i][j], g, i , j, dist[i][j], 0);
                    //cout<<"m = "<<m<<" i = "<<i<<" j ="<<j <<endl;
                    ans = max(ans,m );

                    ///print(g);
                    
                //}
            }
            
            
        }
    }

    printf("Case %d: %lld\n",t,ans);
    
    t++;
}

return 0;
}