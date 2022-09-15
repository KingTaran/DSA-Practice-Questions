int t[21][5005] ;
class Solution{
    public:
int Solve(vector<int>&A , int i , int FirstSum, int SecondSum )
{   
    if(i==A.size())
    {
        if(FirstSum==SecondSum) return 0 ;
        else return -100000;
    }

    if(t[i][abs(FirstSum-SecondSum)]!=-1) return t[i][abs(FirstSum-SecondSum)] ;
    
    return t[i][abs(FirstSum-SecondSum)] = max(A[i]+Solve(A,i+1,FirstSum+A[i],SecondSum) ,          max(A[i]+Solve(A,i+1,FirstSum,SecondSum+A[i]) , Solve(A,i+1,FirstSum,SecondSum))) ;
    
}

int tallestBillboard(vector<int>& rods) {
    int Sum=0 ;
    for(auto x:rods) Sum+=x ;
    memset(t,-1,sizeof(t)) ;
    return Solve(rods,0,0,0)/2 ;
}
};