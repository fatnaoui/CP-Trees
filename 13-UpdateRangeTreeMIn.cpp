#include <bits/stdc++.h>
using namespace std;
#define ll int
#define F(i,a,b) for(int i=a;i<=b;i++)
#define LM INT_MAX

void BuildTree(ll *a,ll s,ll e,ll *tree,ll index){
    // base case
    if(s == e){
        tree[index] = a[s];
        return ;
    }
    ll middle = (s + e)/2;

    // Recursive case
    BuildTree(a,s,middle,tree,2*index);
    BuildTree(a,middle+1,e,tree,2*index+1);
    tree[index] = min(tree[2*index],tree[2*index+1]);
    return ;
}

ll query(ll ss,ll se, ll sq,ll eq,ll *tree,ll index){
    // complete overlap
    if((ss >= sq) && (eq >= se)){
        return tree[index];
    }
    // no overlap
    if((ss > eq) || (se < sq)){
        return LM;
    }
    ll middle = (ss + se)/2;
    // partial overlap
    ll left = query(ss,middle,sq,eq,tree,2*index);
    ll right = query(middle+1,se,sq,eq,tree,2*index+1);
    return min(left,right);
}

// Update 
void updateNode(ll s,ll e,ll *tree,ll i,ll increment,ll index){
    // case where it isn't in the range
    if((s > i) || (e < i)){
        return ;
    }
    // reach i
    if(s == e){
        tree[index] += increment;
        return;
    }
    ll middle = (s + e)/2;
    updateNode(s,middle,tree,i,increment,2*index);
    updateNode(middle+1,e,tree,i,increment,2*index+1);
    tree[index] = min(tree[2*index],tree[2*index+1]);
    return ;
}

void updateRange(ll s,ll e,ll *tree,ll l,ll r,ll increment,ll index){
    if((l > e) || (r < s)){
        return ;
    }
    if(s == e){
        tree[index] += increment;
        return ; 
    }
    ll middle = (s + e)/2;
    updateRange(s,middle,tree,l,r,increment,2*index);
    updateRange(middle+1,e,tree,l,r,increment,2*index+1);
    tree[index] = min(tree[2*index],tree[2*index+1]);
    return ;
}

int main() {
    ll a[] = {1,3,2,-5,6,4};
    ll n = sizeof(a)/sizeof(ll);
    ll *tree = new ll[4*n+1];
    BuildTree(a,0,n-1,tree,1);
    updateRange(0,n-1,tree,0,3,10,1);
    ll q; cin>>q;
    while(q--){
        ll l,r; cin>>l>>r;
        cout<<query(0,n-1,l,r,tree,1)<<endl;
    }
}
