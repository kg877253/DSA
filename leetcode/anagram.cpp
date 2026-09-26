#include <bits/stdc++.h>
using namespace std;

// bool isanagram(string s , string t ){
//     if(s.size()!= t.size()) return false;

//     int freq[26]={0};

//     for(int i =0; i< s.size();i++){
//         int alphabet= s[i]-'a'; //'a' - 'a'=0 so freq[0]++ for 'a' --now freq[0] will be 1 and so on
//         int alphabet2= t[i] -'a'; //'n' - 'a'=13 so freq[13]++ for 'n' --now freq[13] will be 1 and so on
//         freq[alphabet]++;
//         freq[alphabet2]--;

//     }

//     for(int i =0 ;i<26;i++){
//         if(freq[i]!=0) return false;
//     }
//     return true;
// }

bool isanagramornot(string s , string t ){
    if(s.size()!=t.size()) return false;

    int freq[26]={0};

    for(int i =0 ;i<s.size();i++){
        int alphabet=s[i]-'a';
        int alphabet2=t[i]-'a';

        freq[alphabet]++;
        freq[alphabet2]--;
    }

    for(int i=0; i<26 ;i++){
        if(freq[i]!=0) return false;
    }

    return true;
}

int main(){
    string s = "anagram";
    string t = "nagaram";

    if(isanagramornot(s,t)){
        cout<<"Yes this is an anagram"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
}