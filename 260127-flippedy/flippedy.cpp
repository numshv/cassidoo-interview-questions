#include <bits/stdc++.h>
using namespace std;

int vowel_counter(string word){
    int n_vowels = 0;
    string vowels = "aeiou";
    for(char c: word){
        if(vowels.find(c) != string::npos){
            n_vowels++;
        }
    }

    return n_vowels;
}

void flippedy(string sentence){
    int n_vowels;
    int i = 0;
    string result = "";
    
    stringstream ss(sentence);


    for (auto w = istream_iterator<string>(ss);
        w != istream_iterator<string>(); w++ ){
        
        string word = *w;
        
        // count n_vowels from the first word
        if(i == 0){
            n_vowels = vowel_counter(word);
        }

        // logic for non-first word
        else{
            if(n_vowels == vowel_counter(word)){
                reverse(word.begin(), word.end());
            }
            result.append(" ");
        }

        result.append(word);
        i++;
    }


    cout << "Final Result: " << result;

}

int main(){

    string sentence;
    
    cout << "Enter the sentence: ";
    getline(cin, sentence);

    flippedy(sentence);
    return 0;
}