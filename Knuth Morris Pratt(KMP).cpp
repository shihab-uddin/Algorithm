#include<bits/stdc++.h>
using namespace std;

vector<int> createLpsArray(string pattern){
    vector<int> lps(pattern.length()); // Size of LPS array is length of pattern
    //Firstly we need to set Tracker at index 0 and index 1. And we have to start from those.
    int i = 0;
    for(int j = 1; j < pattern.length(); ){
        if(pattern[i] == pattern[j]){
            lps[j] = i + 1; // If we get match So we have gotten a substring which is suffix and also a prefix
            j++; i++; // If we get match 'i' and 'j' both will increase
        }else{
            if(i != 0){
                i = lps[i - 1]; // If we get mismatch we will go to one left item of lps Array and we can start form new i again.
            }else{
                lps[j] = i; // We didn't get match so lps[j] = i, Since i = 0 and j will increase.
                j++;
            }
        }
    }
    return lps; // Finally we will return LPS array.
}

void kmp(string text, string pattern){
    bool found = false;
    vector<int> lps = createLpsArray(pattern);
    int i = 0, j = 0; //i -->text, j -->pattern
    while(i < text.length()){
        if(text[i] == pattern[j]){ // If text index and pattern index get match then i, j both will point next location
            i++, j++;
        }else{
            if(j != 0){
                j = lps[j-1]; // If not matches then move 1 item left of lps array and again start matching from that.
            }else{
                i++; // Value of lps[j] = 0. That means there is no same prefix or suffix.
            }
        }
        if(j == pattern.length()){
            cout<<"Found at Index : "<<(i - pattern.length())<<endl;
            found = true;
            j = lps[j-1];
        }
    }
    if(!found){
        cout<<"Not Found"<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string text, pattern;
    getline(cin, text);
    getline(cin, pattern);
    kmp(text, pattern);
    return 0;
}

/*
-> Input :
   I saw a saw to saw a saw.
   saw

-> Output :
   Found at Index : 2
   Found at Index : 8
   Found at Index : 15
   Found at Index : 21
*/
