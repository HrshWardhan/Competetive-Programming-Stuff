/// Name: BFS
/// Description: Breadth boi
/// Detail: 
/// Guarantee: struct FU {
int n,m,u,v,x,y,z;
vector<int>arr[200001];
int a[200001];
bool vis[200001]{0};
void reset(){
    for(int i = 0;i<=n;i++){
        arr[i].clear();
    }
}
void ff(){
    for(int i=0;i<=n;i++)vis[i]=0;
}
void bfs(int to){
    queue<pair<int,int>>q;
    q.push({to,0});
    ff();
    vis[to]=1;
    int ret = 0;
    while(q.size()>0){
        auto i = q.front();
        q.pop();
        a[i.first]=i.second;
        for(auto j:arr[i.first]){
            if(!vis[j]){
                q.push({j,i.second+1});
                vis[j]=1;
            }
        }
    }
}
