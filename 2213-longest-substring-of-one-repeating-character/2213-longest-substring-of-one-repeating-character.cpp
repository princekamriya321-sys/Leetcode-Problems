class Solution {
public:
struct Node{
    int pre = 0;
    int suf = 0;
    int maxlen = 0;
    char leftchar = 0;
    char rightchar = 0;
};
int n;
vector<Node> segtree;
Node merge(const Node&L,const Node&R,int leftlen,int rightlen){
    Node res;
    res.leftchar = L.leftchar;
    res.rightchar = R.rightchar;
    res.pre = L.pre;
    if(L.pre == leftlen && L.rightchar == R.leftchar){
        res.pre = L.pre + R.pre;
    }
    res.suf = R.suf;
    if(R.suf == rightlen && L.rightchar == R.leftchar){
        res.suf = L.suf + R.suf;
    }
res.maxlen = max(L.maxlen,R.maxlen);
if(L.rightchar == R.leftchar){
    res.maxlen = max(res.maxlen,L.suf+ R.pre);
}
return res;
}
void buildsegmenttree(int i,int l,int r,string &s){
    if(l == r){
        segtree[i] = {1,1,1,s[l],s[l]};
        return;
    }
    int mid = l + (r-l)/2;
buildsegmenttree(2*i+1,l,mid,s);
buildsegmenttree(2*i+2,mid+1,r,s);
segtree[i] = merge(segtree[2*i+1],segtree[2*i+2],mid-l+1,r - mid);
}
void update(int i,int l,int r,int pos,char ch){
    if(l == r){
        segtree[i] = {1,1,1,ch,ch};
        return;
    }
    int mid = l + (r-l)/2;
    if(pos <= mid){
        update(2*i+1,l,mid,pos,ch);
    } else {
        update(2*i+2,mid+1,r,pos,ch);
    }
    segtree[i] = merge(segtree[2*i+1],segtree[2*i+2],mid-l+1,r - mid);
}
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        n = s.size();
        segtree.assign(4*n,Node());
        buildsegmenttree(0,0,n-1,s);
        int k = queryIndices.size();
        vector<int> result(k);
        for(int i =0; i<k; i++){
int pos = queryIndices[i];
char ch = queryCharacters[i];
update(0,0,n-1,pos,ch);
result[i] = segtree[0].maxlen;
        }
        return result;
    }
};