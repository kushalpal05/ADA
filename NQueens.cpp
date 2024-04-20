/*
  Given N queens and these queens needs to be placed in n x n matrix such that :- 
    No two queens are placed in the same row.
    No two queens are placed in the same column.
    No two queens are in the same diagonal
  We can solve this problem using backtracking, whenever we place a new queen in a particular row we backtrack and check if all the conditions are being satisfied if we do so
*/
#include <bits/stdc++.h>
using namespace std ;
class NQueen
{
  int n ;
  vector<int> x ;
  public :
  NQueen(int n)
  {
    this->n = n ;
    x.resize(n+1,0) ;
  }
  bool place(int k , int i)
  {
    for(int j=1; j<=k-1 ; j++)
    {
      if(x[j]==i || abs(j-k)==abs(x[j]-i))
      return false; 
    }
    return true ;
  }
  void NQ(int k)
  {
    for(int i=1; i<=n ; i++)
    {
      if(place(k,i))
      {
        x[k]=i ;
        if(k==n)
        {
          for(int i=1 ; i<=n ; i++)
          {
            for(int j=1 ; j<=n ; j++)
            {
              if(x[i]==j) cout << " Q "  ;
              else cout << " * " ;
            }
            cout << endl ;
          }
          cout << endl;
          return ;
        }
        else NQ(k+1);
      }
    }
  }
};
int main()
{
  int n;
  cout << "Enter number of queens :- " ; cin >> n ;
  NQueen N(n); 
  N.NQ(1) ;
}