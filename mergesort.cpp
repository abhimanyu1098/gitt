#include<climits>
#include<iostream>
using namespace std;
void merge(int a[],int l,int r,int mid){
    int l_size=mid-l+1;
    int L[l_size+1];
    int r_size=r-mid;
    int R[r_size+1];
    for(int i=0;i<l_size;i++){
        L[i]=a[i+l];
    }
    for(int i=0;i<r_size;i++){
        R[i]=a[i+mid+1];
    }
    R[r_size]=L[l_size]=INT_MAX;
    int r_i=0;
    int l_i=0;
    for(int i=l;i<=r;i++){
        if(L[l_i]<=R[r_i]){
            a[i]=L[l_i];
            l_i++;
        }
        else{
            a[i]=R[r_i];
            r_i++;
        }
    }

}
void mergesort(int a[],int l,int r){
    int mid=(l+r)/2;
    if(l==r){
      return;
        
    }
    mergesort(a,l,mid);
    mergesort(a,mid+1,r);
    merge(a,l,r,mid);
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    mergesort(a,0,n-1);
    for(int i=0;i<n;i++){
        cout<<a[i];
    }
}