#include<iostream>
#include<set>
#include<vector>
#include<math.h>
using namespace std;
void ver(vector<vector<int> >&grid,int row,int col,vector<vector<vector<int> > >&check){
    for (int i = 1; i <=9 ; i++)
    {
        if(grid[i][col]!=0){
            for (int j=0;j<check[row][col].size();j++)
            {
                if(check[row][col][j]==grid[i][col]){
                    check[row][col].erase(check[row][col].begin()+j);
                    break;
                }
            }
            
        }
    } 
}
void hori(vector<vector<int> >&grid,int row,int col,vector<vector<vector<int> > >&check){
    for (int i = 1; i <=9 ; i++)
    {
        if(grid[row][i]!=0){
            for (int j=0;j<check[row][col].size();j++)
            {
                if(check[row][col][j]==grid[row][i]){
                    check[row][col].erase(check[row][col].begin()+j);
                    break;
                }
            }
        }
    }
    
}
void box(vector<vector<int> >&grid,int row,int col,vector<vector<vector<int> > >&check){
    int i=1,j=1;
    if(row<=9) i=7;
    if(row<=6) i=4;
    if(row<=3) i=1;
    if(col<=9) j=7;
    if(col<=6) j=4;
    if(col<=3) j=1;
    int a=i,b=j;
    for(i=a;i<a+3;i++){
        for(j=b;j<b+3;j++){
            // cout<<grid[i][j]<<" ";
            if(grid[i][j]!=0){
            for(int l=0;l<check[row][col].size();l++)
            {
                if(check[row][col][l]==grid[i][j]){
                    check[row][col].erase(check[row][col].begin()+l);
                    break;
                }
            }
            }
            
        }
        // cout<<endl;
    }
}
bool hor(vector<vector<int> >&grid,int row,int col,vector<vector<vector<int> > >&check,int x){
    for (int i = 1; i <=9; i++)
    {
        if(grid[row][i]!=0){
            if(grid[row][i]==x) return 0;
        }
        else{
            for ( int j = 0; j < check[row][i].size(); j++)
            {
                if(i!=col&&x==check[row][i][j]) return 0;
            }
            
        }
    }
    return 1;
}
bool ve(vector<vector<int> >&grid,int row,int col,vector<vector<vector<int> > >&check,int x){
    for (int i = 1; i <=9; i++)
    {
        if(grid[i][col]!=0){
            if(grid[i][col]==x) return 0;
        }
        else{
            for ( int j = 0; j < check[i][col].size(); j++)
            {
                if(i!=row&&x==check[i][col][j]) return 0;
            }
            
        }
    }
    return 1;
}
bool boxes(vector<vector<int> >&grid,int row,int col,vector<vector<vector<int> > >&check,int x){
    int i,j;
    if(row<=9) i=7;
    if(row<=6) i=4;
    if(row<=3) i=1;
    if(col<=9) j=7;
    if(col<=6) j=4;
    if(col<=3) j=1;
    int a=i,b=j;
    for(i=a;i<a+3;i++){
        for(j=b;j<b+3;j++){
            if(grid[i][j]!=0){
                if(grid[i][j]==x) return 0;
            } 
            else{
                for (int l = 0; l< check[i][j].size(); l++)
                {
                    if(i!=row||j!=col&&x==check[i][j][l]) return 0;
                }
                
            }
        }
    }
    return 1;
}
void solve(vector<vector<int> >&grid,vector<vector<vector<int> > >&check){
int row,col;
for ( row = 1; row <=9; row++)
    {
        for ( col = 1; col <=9; col++)
        {
            if(grid[row][col]==0){
                hori(grid,row,col,check);
                ver(grid,row,col,check);
                box(grid,row,col,check);
                if(check[row][col].size()==1){
                    grid[row][col]=check[row][col][0];
                    // solve(grid,check);
                }
            }
            if(grid[row][col]==0){
                for (int i=1;i<=9;i++)
                {
                    if(hor(grid,row,col,check,i)) {
                        grid[row][col]=i;break;
                    }
                    if(ve(grid,row,col,check,i)){
                        grid[row][col]=i;break;
                    }
                    if(boxes(grid,row,col,check,i)){
                        grid[row][col]=i;break;
                    }
                }
                
            }
        }
        
    }
    for ( row = 1; row <=9; row++)
    {
        for ( col = 1; col <=9; col++)
        {
            if(grid[row][col]==0) solve(grid,check);
        }
    }
    return ;
}
int main()
{
    int row,col;
    vector<vector<int> > grid(10,vector<int>(10,0));
    for ( row = 1; row <=9; row++)
    {
        for ( col = 1; col <=9; col++)
        {
            cin>>grid[row][col];
        }
        
    }
    vector<vector<vector<int> > >check(10,vector<vector<int> >(10,vector<int>(9,0)));
    for ( row = 1; row <=9; row++)
    {
        for ( col = 1; col <=9; col++)
        {
            if(grid[row][col]==0){
                for(int i=1;i<=9;i++)
                check[row][col][i-1]=i;
            }
            else check[row][col][0]=0;
        }
        
    }
    solve(grid,check);
    for ( row = 1; row <=9; row++)
    {
        for ( col = 1; col <=9; col++)
        {
            cout<<grid[row][col]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}
