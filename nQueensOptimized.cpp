
#include<iostream>
#include<vector>
#include<string>
using namespace std;

void find(int row , int n , vector<vector<string>>& ans , vector<string>& Board , vector<bool>& column , vector<bool>& rightDiagonal , vector<bool>& leftDiagonal ){
    if(row == n){
        ans.push_back(Board);
        return;
    }

    for(int j = 0 ; j < n ; j ++){
        if(column[j] == 0 && (leftDiagonal[j - row + n - 1] == 0 && rightDiagonal[j + row] == 0)){
            Board[row][j] = 'Q';
            column[j] = 1;
            leftDiagonal[j - row + n - 1] = 1;
            rightDiagonal[j + row] = 1;
            find(row + 1 , n , ans , Board , column , rightDiagonal , leftDiagonal);
            leftDiagonal[j - row + n - 1] = 0;
            rightDiagonal[j + row] = 0;
            Board[row][j] = '.';
            column[j] = 0;
        }
    }
}
vector<vector<string>> nQueens(int n){
    vector<vector<string>> ans;
    vector<string>Board(n);

    for(int i = 0 ; i < n ; i ++){
        for(int j = 0 ; j < n ; j ++){
            Board[i].push_back('.');
        }
    }
    vector<bool> column(n , 0);
    vector<bool> rightDiagonal( 2 * n - 1  , 0);
    vector<bool> leftDiagonal(2 * n - 1 , 0);
    find(0 , n , ans , Board , column , rightDiagonal , leftDiagonal);
    return ans;

}
void printBoard(vector<string>Board , int n){
    for(int i = 0 ; i < Board.size() ; i ++){
        for(int j = 0 ; j < n ; j ++){
            cout << Board[i][j]<<" ";
        }cout << endl;
    }
}
int main(){
    int n;
    cout << "Enter value of n \n";
    cin >> n;
    vector<vector<string>> ans = nQueens(n);
    if(ans.size() == 0){
        cout << "There are no possible solutions for 'n' equals to "<< n << endl;
        return 0;
    }
    cout << "Following are all the possible solutions: " << endl;

    for(int i = 0 ; i < ans.size() ; i ++){
        vector<string>Board = ans[i];
        printBoard(Board , n);

        cout << endl << endl;
    }
    return 0;
}
