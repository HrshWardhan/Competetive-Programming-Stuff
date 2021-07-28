/// Name: Segment Tree
/// Description: Efficent Segment Tree
/// Detail: Sum
/// Guarantee: struct FU {
const long long int N = 2e5;
long long int n;
long long int t[2*N];
long long int combine(long long int a,long long int b){
    return a+b;
}
void build(){
    for(long long int i=n-1;i>0;i--){
        t[i]=combine(t[i<<1],t[i<<1|1]);
    }
}
void modify(long long int p,long long int value){
    for(t[p+=n]=value;p>1;p>>=1){
        t[p>>1]=combine(t[p],t[p^1]);
    } 
}
long long int query(long long int l,long long int r){
    long long int ret = 0;
    for(l+=n,r+=n;l<r;l>>=1,r>>=1){
        if(l&1) ret=combine(ret,t[l++]);
        if(r&1) ret=combine(t[--r],ret);
    }
    return ret;
}
