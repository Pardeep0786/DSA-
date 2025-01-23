//Recursion
#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

//Print the number form 1 to n with recursion 
void Printn(int n){
    if(n == 1){
        cout<< "1\n";
        return;
    }
    cout<< n << " ";
    Printn(n - 1);
}


//Find the factorial of number using recursion
int factorial(int n){
    if(n == 0){
        return 1;
    }

    return n * factorial(n - 1);
}


//Sum of number from 1 to n using recursion
int Sum(int n){
    if(n == 1){
        return 1;
    }
    return n + Sum(n - 1);
}


//Sort the array using recursion
int isSorted(vector <int> arr, int n){
    if(n == 0 || n == 1){
        return true;
    }

    return arr[n - 1 ] >= arr[n - 2] && isSorted(arr, n - 1);
}


//Print fibonacci series using recursion
int fib(int n){
    if(n == 0 || n == 1){
        return n;
    }

    return fib(n - 1) + fib(n - 2);
}


//Perform Binary Search on array using recursion
int BinarySearch(vector <int> arr, int st, int end, int tar){
    if(st <= end){
        int mid = st + (end - st)/2;
        if(tar == arr[mid]) return mid;
        else if(tar >= arr[mid]){
            return BinarySearch(arr, mid + 1, end, tar);
        }else{
            return BinarySearch(arr, st, mid - 1, tar);
        }
    }
    return -1;
}


//Print the subset of array using recursion
void PrintSubset(vector <int> &arr, vector <int> &ans, int i){
    if(i == arr.size()){
        for(int val : ans){
            cout<< val <<" ";
        }
        cout<< endl;
        return;
    }

    // include
    ans.push_back(arr[i]);
    PrintSubset(arr, ans, i + 1);

    // exclude
    ans.pop_back();
    PrintSubset(arr, ans, i + 1);
}


//rat in the maze

//helper function
void helperfun(vector<vector<int>> &mat, int row, int col, vector<string> &ans, string path){
    int n = mat.size();
    if(row < 0 || col < 0 || row >= n || col >= n || mat[row][col] == 0 || mat[row][col] == -1){
        return;
    }

    if(row == n - 1 && col == n - 1){
        ans.push_back(path);
        return;
    }

    mat[row][col] = -1;
    helperfun(mat, row + 1, col, ans, path+"D");
    helperfun(mat, row - 1, col, ans, path+"U");
    helperfun(mat, row, col - 1, ans, path+"L");
    helperfun(mat, row, col + 1 , ans, path+"R");
    mat[row][col] = 1;
}
//complete the function
vector<string> FindPath(vector<vector<int>> &mat){
    vector<string> ans;
    string path = "";

    helperfun(mat, 0, 0, ans, path);

    return ans;
}


//Sudoku Solver 

//isSafe function of Sudoku Solver
bool isSafe(vector<vector<char>>& board, int row, int col, char digit){
        //horizontally
        for(int j = 0; j < 9; j++){
            if(board[row][j] == digit){
                return false;
            }
        }

        //vertically
        for(int i = 0; i < 9; i++){
            if(board[i][col] == digit){
                return false;
            }
        }

        //grid
        int srow = (row / 3) * 3, scol = (col / 3) * 3;
        for(int i = srow; i<=srow+2; i++){
            for(int j = scol; j<=scol+2; j++){
                if(board[i][j] == digit){
                    return false;
                }
            }
        }

        return true;
    }
    
    //helper function of sudoku solver
    bool helper(vector<vector<char>>& board, int row, int col){
        if(row == 9){
            return true;
        }

        int nextrow = row, nextcol = col + 1;
        if(nextcol == 9){
            nextrow = row + 1;
            nextcol = 0;
        }

        if(board[row][col] != '.'){
            return helper(board, nextrow, nextcol);
        }

        //Place the digit in Sudoku
        for(char digit = '1'; digit <= '9'; digit++){
            if(isSafe(board, row, col, digit)){
                board[row][col] = digit;
            if(helper(board, nextrow, nextcol)){
                return true;
            }

            board[row][col] = '.';
        }
        }
        return false;
    }
    //Sudoku solver function
    void solveSudoku(vector<vector<char>>& board) {
        helper(board, 0, 0);
    }


//N-Queens

//isSafe Function of N-Queens
bool isSafe(vector<string> &board, int row, int col, int n){
        //horizontal
        for(int j = 0; j < n; j++){
            if(board[row][j] == 'Q'){
                return false;
            }
        }

        //Verticle
        for(int i = 0; i < n; i++){
            if(board[i][col] == 'Q'){
                return false;
            }
        }

        //left Diagonal
        for(int i = row, j = col; i >= 0 && j >= 0; i--, j--){
            if(board[i][j] == 'Q'){
                return false;
            }
        }

        //Right Diagonal
        for(int i = row, j = col; i >= 0 && j < n; i--, j++){
            if(board[i][j] == 'Q'){
                return false;
            }
        }

        return true;
    }
    
    //N-Queens function
    void nQueens(vector<string> &board, int row, int n, vector<vector<string>> &ans){
        if(row == n){
            ans.push_back({board});
            return;
        }

        for(int j = 0; j < n; j++){
            if(isSafe(board, row, j, n)){
                board[row][j] = 'Q';
                nQueens(board, row + 1, n, ans);
                board[row][j] = '.';
            }
        }
    }
    
    //In this function we call N-Queens function
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board (n, string(n, '.'));
        vector<vector<string>> ans;

        nQueens(board, 0, n, ans);

        return ans;
    }    
