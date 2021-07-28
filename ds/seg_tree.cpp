/// Name: My Segment Tree
/// Description: Editable Segment tree
/// Detail: 
/// Guarantee: struct FU {
int curr = 1; // To maintain till where segment tree is filled
struct Vertex{
    int left=-1,right=-1; // index of Children
    long long int value=0; 
    long long int lazy = 0;
    ll l=0,r=0; // Range for which this vertex is responsible
    Vertex(){}
    // Constructor
    Vertex(vector<long long int> &arr,int a,int b,vector<Vertex>&SegTree){
        l = a;
        r = b;
        if(l==r){
            value = arr[l];
        }else{
            left=curr;curr++;
            SegTree.push_back(Vertex());
            SegTree[left] = Vertex(arr,a,(a+b)/2,SegTree);
            right=curr;curr++;
            SegTree.push_back(Vertex());
            SegTree[right] = Vertex(arr,(a+b)/2+1,b,SegTree);
            recalculate(SegTree);
        }
    }  
    // To Revaluevate this node after update
    void recalculate(vector<Vertex>&SegTree){
        if(left!=-1)
            value = SegTree[right].value+SegTree[left].value+(r-l+1)*lazy;
        else{
            value = value+lazy;
            lazy = 0;
        }
    }
    // To push Lazy update to children
    void push(vector<Vertex>&SegTree){
        SegTree[right].lazy+=lazy;
        SegTree[right].recalculate(SegTree);
        SegTree[left].lazy+=lazy;
        SegTree[left].recalculate(SegTree);
        lazy=0;
    }

    // Lazy update over a range
    void update(int a,int b,ll val,vector<Vertex>&SegTree){
        if(a<=l && b>=r){
            lazy+=val;
            recalculate(SegTree);
        }else if(a>r || b<l){
            return;
        }else{
            SegTree[left].update(a,b,val,SegTree);
            SegTree[right].update(a,b,val,SegTree);
            recalculate(SegTree);
        }
    }
    long long int query(int a,int b,vector<Vertex>&SegTree){
        if(a<=l && b>=r){
            return value;
        }else if(a>r || b<l){
            return 0;
        }else{
            push(SegTree);
            auto i = SegTree[left].query(a,b,SegTree);
            auto j = SegTree[right].query(a,b,SegTree);
            return i + j;
        }
    }  
};
struct SegmentTree{
    vector<Vertex>SegTree; // For Storing Vertexes
    SegmentTree(vector<ll> &arr){
        SegTree.push_back(Vertex());
        SegTree[0] = Vertex(arr,0,arr.size()-1,SegTree);
    }
    void update(ll a,ll b,ll val){
        SegTree[0].update(a,b,val,SegTree);
    }
    vector<int> query(ll a,ll b){
        SegTree[0].query(a,b,SegTree);
    }
};
