#include <iostream>
#include <vector>
#include <algorithm>
#include <ranges>
using namespace std;

int main(){
    vector<string> words;
    for (string temp; cin>>temp;)
        words.push_back(temp);

    cout<<"\nNumber of words: " << words.size() << '\n';

    ranges::sort(words);

    vector<string> disliked = {"broccoli", "cabbage", "radish", "coriander"};

    int flag;

    for (int i = 0; i < words.size(); ++i)
        if (i == 0 || words[i-1] != words[i]){
            flag = 0;
            for (string dislike : disliked)
                if (words[i] == dislike){
                    cout << "BLEEP" << '\n';
                    flag = 1;
                }
            if (flag == 0)
                cout << words[i] << '\n';
        } 
    return 0;
}