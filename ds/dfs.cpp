/// Name: DFS
/// Description: Depth boi
/// Detail: 
/// Guarantee: struct FU {
vector<int>arr[100001];
ll n,u,v,w;
void dfs(int to,int from){
    for(auto i:arr[to]){
        if(i!=from){
            dfs(i,to);
        }
    }
}
