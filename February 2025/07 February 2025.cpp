/*
One morning, a printing press in SnoopCity encountered a problem. An article celebrating a girl's bravery mistakenly printed the name "Nancy" instead of "Sanvi."
To fix this, you need to replace every instance of "nancy" with "sanvi" in the given sentences.
The printing press uses a unique format where sentences are concatenated into a single word without spaces, such as "hernameisnancy" instead of "her name is nancy."
Note-The string consists of only lowercase words without any spaces.
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;
char arr[]={'n','a','n','c','y'};
std::string user_logic(const std::string& str) {
    string word=str;
    int n=str.size();
    for(int i=0;i<n;i++){
        bool Match=false;
        if(word[i]=='n'){
            int ind=0;
            Match=true;
            for(int j=i;j<i+5;j++){
                if(word[j]!=arr[ind++]) Match=false;
            }
        }
        if(Match){
            string s="sanvi";
            for(int j=0;j<5;j++){
                word[j+i]=s[j];
            }
            i+=4; //1 increment by loop
        }
    }

    return word;
}

int main() {
    int T;
    std::cin >> T;

    std::vector<std::string> testCases(T);
    for (int i = 0; i < T; ++i) {
        std::cin >> testCases[i];
    }

    for (const auto& word : testCases) {
        std::string result = user_logic(word);
        std::cout << result << std::endl;
    }

    return 0;
}