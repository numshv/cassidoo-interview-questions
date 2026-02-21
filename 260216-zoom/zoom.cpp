#include <bits/stdc++.h>
using namespace std;

void print_matrix(vector<vector <int>>& matrix){
    cout << "[\n";
    int row = matrix.size();

    for(int i = 0 ; i < row; i++){
        cout << "[";
        int cur_row_size = matrix[i].size();
        for(int j = 0; j < cur_row_size; j++){
            cout << matrix[i][j] ;

            if(j != cur_row_size-1){
                cout << ",";
            }
        }
        cout << "]";
        if(i != row-1){
            cout << ",";
        }

        cout << "\n";
    }

    cout << "]";
}

vector<vector<int>> zoom(const vector<vector<int>>& matrix, int zoom_factor) {
    int n = matrix.size();
    int m = matrix[0].size();

    vector<vector<int>> result(n * zoom_factor, vector<int>(m * zoom_factor));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            for(int di = 0; di < zoom_factor; di++){
                for(int dj = 0; dj < zoom_factor; dj++){
                    result[i*zoom_factor + di][j*zoom_factor + dj] = matrix[i][j];
                }
            }
        }
    }

    return result;
}

int main(){
    vector<vector<int>> numbers;
    vector<vector<int>> result;
    int zoom_factor;
    string input_str;

    cout << "Input array of int that you want to zoom with no spacing. Format Example: [[1,2],[3,4]]\n> ";
    cin >> input_str;

    if(!(input_str.empty())){
        input_str.erase(0,1);
    }

    if(!(input_str.empty())){
        input_str.pop_back();
    }


    int cur_num = 0;
    bool is_neg = false;
    vector<int> cur_row;
    bool in_num = false;

    for(char c: input_str){

        if(c =='-'){
            is_neg = true;
        }

        if(isdigit(c)){
            cur_num = cur_num*10 + (c - '0');
            in_num = true;
        }

        else{
            if(in_num){
                if(is_neg) cur_num *= -1;
                cur_row.push_back(cur_num);

                cur_num = 0;
                is_neg =false;
                in_num = false;
            }

            if(c ==']'){
                numbers.push_back(cur_row);
                cur_row.clear();
            }
        }

    }

    cout << "\nInput the zoom amount (zoom factor). Example: 3\n> ";
    cin >> zoom_factor;

    result = zoom(numbers, zoom_factor);    
    cout << "\nResult:\n";
    print_matrix(result);

    return 0;
}