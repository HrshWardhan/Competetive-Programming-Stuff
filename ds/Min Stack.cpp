/// Name: MIn Stack
/// Description: Codeforces Edu 89 E 
/// Detail: For each element what range is it min in
/// Guarantee: struct FU {
	ll val[2][n];
    stack<pair<int,int>>s;
    for(int i=0;i<n;i++){
        while(s.size()>0 && s.top().F>arr[i]){
            auto j = s.top();
            s.pop();
            val[1][j.second]=i-1;
        }
        s.push({arr[i],i});
    }
    while(s.size()>0){
        auto i = s.top();
        s.pop();
        val[1][i.S]=n-1;
    }
    for(int i=n-1;i>=0;i--){
        while(s.size()>0 && s.top().F>arr[i]){
            auto j = s.top();
            s.pop();
            val[0][j.second]=i+1;
        }
        s.push({arr[i],i});
    }
    while(s.size()>0){
        auto i = s.top();
        s.pop();
        val[0][i.S]=0;
    }