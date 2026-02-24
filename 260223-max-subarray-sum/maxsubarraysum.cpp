#include <bits/stdc++.h>
using namespace std;

int max_subarray_sum(vector<int> &nums){
    int cur_sum = nums[0];
    int max_sum = nums[0];
    int len = nums.size();

    for(int i = 1; i < len; i++){
        cur_sum = max(nums[i], cur_sum + nums[i]);
        max_sum = max(max_sum, cur_sum);
    }

    return max_sum;
}

int main(){
    vector<int> in_nums;
    string str_nums;
    int temp_num;

    cout << "Enter array of int separated with a comma and a space. e.g. '1, 2, 3, 4'\n";
    cout << "> ";
    getline(cin, str_nums);
    stringstream ss(str_nums);

    while(ss >> temp_num){
        in_nums.push_back(temp_num);
        char peeked = ss.peek();
        if(peeked == ',' || peeked == ' '){
            ss.ignore();
        }
    }

    cout << "Max subarray sum: " << max_subarray_sum(in_nums);


    return 0;
}