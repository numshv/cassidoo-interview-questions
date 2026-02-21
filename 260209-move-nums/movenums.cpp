#include <bits/stdc++.h>
using namespace std;

void moveNToEnd(vector<int>* numbers, int target_number){

    int n_target = count(numbers->begin(), numbers->end(), target_number);
    numbers->erase(remove(numbers->begin(), numbers->end(), target_number), numbers->end());
    numbers->insert(numbers->end(), n_target, target_number);

    cout << "Answer: [";

    for(auto it = numbers->begin(); it != numbers->end(); ++it){
        if(it != numbers->begin()){
            cout << ",";
        }
        cout << *it;
    }

    cout << "]";

}

int main(){
    vector<int> numbers;
    string input;
    int temp_num, target_num;

    cout << "Enter list of numbers separated by commas (e.g., 10,20,30,40): ";
    getline(cin, input);
    stringstream ss(input);

    while (ss >> temp_num){
        numbers.push_back(temp_num);
        if(ss.peek() == ','){
            ss.ignore();
        }
    }

    cout << "Enter the target number that you want to move to the end: ";
    cin >> target_num;

    moveNToEnd(&numbers, target_num);

    return 0;
}