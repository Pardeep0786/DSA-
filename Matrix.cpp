//2-D Array/Matrix
#include <iostream>
#include <vector>
using namespace std;

void HigestColSum(int mat[][3], int rows, int cols){
    int Maxsum = INT16_MIN;
    for(int i = 0; i < cols; i++){
        int maxsumc = 0;
        for(int j = 0; j < rows; j++){
            maxsumc += mat[j][i];
        }
        Maxsum = max(Maxsum, maxsumc);
    }
    cout<<Maxsum;
    
}

void DiagnolSum(int mat[][3], int n){
    int sum = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j){
                sum += mat[i][j];
            } else if(j == n - i - 1){
                sum += mat[i][j];
            }
        }
    }
    cout<< sum;
}
bool IsBinary(vector <vector<int>> mat, int target, int row){
    int n = mat[0].size();
    int st = 0, end = n - 1;

    while(st <= end){
        int mid = st + (end - st)/2;
        if(target == mat[row][mid]){
            return true;
        }else if(target >= mat[row][mid]){
            st = mid + 1;
        }else{
            end = mid - 1;
        }
    }
}
bool BinarySerchInMat(vector <vector<int>> mat, int target, int m, int n){
    int stRow = 0, endRow = m - 1;

    while(stRow <= endRow){
        int midRow = stRow + (endRow - stRow)/2;

        if(target >= mat[midRow][0] && target <= mat[midRow][n - 1]){
            return IsBinary(mat, target, midRow);
        }else if(target >= mat[midRow][n - 1]){
                stRow = midRow + 1;
        }else{
            endRow = midRow - 1;
        }
    }
    return false;
}

bool SerchTarget(vector <vector<int>> mat, int target, int m, int n){
    int r = 0, c = n - 1;

    while(r < m && c >= 0){
        if(target == mat[r][c]){
            return true;
        }else if(target < mat[r][c]){
            c--;
        }else{
            r++;
        }
    }
    return false;
}

vector<int> spiralOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> ans;
    int srow = 0, scol = 0, erow = m - 1, ecol = n - 1;

    while(srow <= erow && scol <= ecol){

        //top
        for(int j = scol; j <= ecol; j++){
            ans.push_back(mat[srow][j]);
        }

        //right
        for(int i = srow + 1; i <= erow; i++){
            
            ans.push_back(mat[i][ecol]);
        }

        //bottom
        for(int j = ecol - 1; j >= scol; j--){
            if(srow == erow){
                break;
            }
            ans.push_back(mat[erow][j]);
        }

        //left
        for(int i = erow - 1; i >= srow+1; i--){
            if(scol == ecol){
                break;
            }
            ans.push_back(mat[i][scol]);
        }
        srow++; erow--; scol++; ecol--;
    }
    return ans;
        
    }



