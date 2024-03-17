long values(int *a,int n,int tar,int ind){
    if(ind==0){
        return tar%a[ind]==0;
    }
    long ntake=values(a,n,tar,ind-1);
    long take=0;
    if(a[ind]<=tar){
        take=values(a,n,tar-a[ind],ind);
    }
    return take+ntake;
}
long countWaysToMakeChange(int *a, int n, int tar)
{
    return values(a,n,tar,n-1);
}
