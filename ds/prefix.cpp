/// Name: Prefix Funcion
/// Description:
/// Detail:
/// Guarantee: struct FU {
struct prefix{
    string s;
    int n;
    vector<int>p;
    prefix(string &a){
        s = a;
        n = s.size();
        p.resize(n);  
        for(int i=1;i<n;i++){
            int j = p[i-1];
            while(j>0 && s[i]!=s[j])
                j = p[j-1];
            if(s[i]==s[j])
                j++;
            p[i]=j;
        }
    }
};