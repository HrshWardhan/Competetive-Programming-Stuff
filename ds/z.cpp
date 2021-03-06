/// Name: Z Funcion
/// Description:
/// Detail:
/// Guarantee: struct FU {
struct z_function{
    int n;
    string s;
    vector<int>z;
    z_function(string &a){
        n = a.size();
        s = a;
        z.resize(n);
        for(int i=1,l=0,r=0;i<n;i++){
            if(i<=r)
                z[i] = min(r-i+1,z[i-l]);
            while(i+z[i]<n && s[z[i]]==s[i+z[i]]){
                ++z[i];
            }
            if(i+z[i]-1>r)
                l = i, r = i + z[i] - 1;
        }
    }
};