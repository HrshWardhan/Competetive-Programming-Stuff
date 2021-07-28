/// Name: String Hash
/// Description: Rabin Carp
/// Detail:  jskdf
/// Guarantee: struct FU {
long long int p1=29,p2=31;
const long long int mod = 1e9+7;
long long int power(long long int x,long long int y){  
    long long int res = 1;
    x = x % mod;
    if (x == 0) return 0;
    while (y > 0){   
        if (y & 1)  
            res = (res*x) % mod;  
        y = y>>1;
        x = (x*x) % mod; 
    }  
    return res;
}  
long long int inv(long long int a){return power(a,mod-2);}
long long int add(long long int a,long long int b){return (a+b)%mod;}
long long int sub(long long int a,long long int b){return (a-b+mod)%mod;}
long long int mul(long long int a,long long int b){return (a*b)%mod;}
long long int divi(long long int a,long long int b){return (a*inv(b))%mod;}
struct hstring{
    string s;
    int n;
    vector<pair<long long int,long long int>>v;
    // constructor
    hstring(string a){
        s = a;
        n = s.size();
        v.resize(n+1);
        for(int i=0;i<n;i++){
            v[i+1].first = (v[i].first*p1 + s[i] - 'a')%mod;
            v[i+1].second = (v[i].second*p2 + s[i] - 'a')%mod;
        }
    }
    // hash for [i,j] 1 indexed in log n
    pair<long long int,long long int> get_hash(int i,int j){
        return {sub(v[j].first,mul(v[i-1].first,power(p1,j-i+1))),sub(v[j].second,mul(v[i-1].second,power(p2,j-i+1)))};
    }
    // compare 2 hstrings in log^2 0 on equal -1 if a is smaller 1 if a is larger
    int compare(hstring &a){
        int m = min(a.n,n);
        int start = 0, end = m,ans = 0,mid;
        while(start<=end){
            mid = (start + end + 1)/2;
            if(a.get_hash(0,mid)==get_hash(0,mid)){
                start = mid+1;
                ans = mid;
            }else{
                end = mid-1;
            }
        }
        if(a.n==n && ans==m) return 0;
        else if(ans<m) return -1 + 2*(s[mid]<a.s[mid]);
        return -1 + 2*(n<a.n);
    }
};         
