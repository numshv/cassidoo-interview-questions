#include <bits/stdc++.h>
using namespace std;

int majority_element(vector<int> &nums){
    int cur_major;
    int cur_major_count = 0;

    for (int num: nums){
        if(cur_major_count== 0){
            cur_major = num;
            cur_major_count++;
        } else{
            if(cur_major == num){
                cur_major_count++;
            } else {
                cur_major_count --;
            }
        }
    }

    return cur_major;
}

int main(){
    vector<int> num_in;
    string num_in_str;
    int temp_num;

    cout << "Enter the array. Each element separated by a comma and a space. (e.g. 2, 2, 1, 1, 2, 2)\n> " ;
    getline(cin, num_in_str);
    stringstream ss(num_in_str);

    while(ss >> temp_num){
        num_in.push_back(temp_num);

        if(ss.peek() == ' ' || ss.peek() == ','){
            ss.ignore();
        }
    }

    cout << "Majority element: " << majority_element(num_in);
}