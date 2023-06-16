#include<iostream>
#include<algorithm>

std::pair<int, int> find_best_cut(char arr[][5], int n, int m){
    static int map[5][5] = {};
    //find sum matrix
    for(int col = 0; col < m; col++){
        for(int row = 0; row < n; row++){
            map[row][col] = (arr[row][col] == '#') ? 1 : 0;
            map[row][col] += (row > 0) ? map[row-1][col] : 0;
            map[row][col] += (col > 0) ? map[row][col-1] : 0;
            map[row][col] -= ((row > 0) & (col > 0)) ? map[row-1][col-1] : 0;
        }
    }
    std::pair<int, int> coordinates;

    int best_outcome = -1;
    for(int col = 0; col < m-1; col++){
        int x = col;
        for(int row = 0; row < n-1; row++){
            int y = row;

            int minimum = {0};
            //Q1
            int Q1 = map[row][col];
            minimum = Q1;

            //Q2
            int Q2 = map[n-1][col] - Q1;
            minimum = std::min(minimum, Q2);

            //Q3
            int Q3 = map[row][m-1] - Q1;
            minimum = std::min(minimum, Q3);

            //Q4
            int Q4 = map[n-1][m-1] - Q2 - Q3 - Q1;
            minimum = std::min(minimum, Q4);

            if(minimum > best_outcome){
                coordinates.first = x;
                coordinates.second = y;
                best_outcome = minimum;
            }
        }
    }

    return coordinates;
}


void print(char arr[][5], int n, int m, int cutx, int cuty){
    for(int i=0;i<n;i++){
        for(int j=0; j<m;j++){
            std::cout << arr[i][j]<<" ";
            if (cutx == j){
                std::cout << "| ";
            }
        }
        if (cuty == i){
            std::cout << std::endl << "------------";
        }
        std::cout << std::endl;
    }
}


int main(){


    char arr[][5] = {
        {'.', '#', '.', '#', '#'},
        {'#', '#', '.', '.', '.'},
        {'.', '.', '#', '.', '#'},
        {'.', '.', '#', '.', '.'},
        {'#', '.', '.', '#', '.'}
        };

/*     char arr[][5] = {
        {'#', '#', '#', '#', '#'},
        {'#', '#', '#', '#', '#'},
        {'#', '#', '#', '#', '#'},
        {'#', '#', '#', '#', '#'},
        {'#', '#', '#', '#', '#'}
        };
 */
    int n=5, m=5;

    std::pair<int, int> coordinates = find_best_cut(arr, n, m);

    print(arr, n, m, coordinates.first, coordinates.second);

    return 0;
}