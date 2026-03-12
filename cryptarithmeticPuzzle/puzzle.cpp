#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>


using namespace std;

unordered_map<char,int> pairing; 
unordered_set<char> uniqueChars;
unordered_set<char> leadingChars;
vector<int> S;
vector<int> U = {0,1,2,3,4,5,6,7,8,9};
string word1;
string word2;
string result;
bool solutionFound = false;



bool isSolve(unordered_map<char,int> &pairingM, string w1, string w2, string r){
    long w1Val = 0;
    long w2Val = 0;
    long rVal  = 0;
    
    for(char c : w1){
        w1Val = w1Val * 10 + pairingM[c];
    }
    for(char c: w2){
        w2Val = w2Val * 10 + pairingM[c];
    }

    for(char c: r){
        rVal = rVal * 10 +pairingM[c];
    }

    if(w1Val+w2Val == rVal){
        solutionFound = true;
    cout<<"\n°❀⋆.ೃ࿔*:･ Solution Found! ◝(ᵔᗜᵔ)◜ °❀⋆.ೃ࿔*:･";
    cout<<"\n____________________________________\n"<<endl;
    cout<<w1<<" + "<<w2<<" = "<<r<<endl;
    cout<<w1Val<<" + "<<w2Val<<" = "<<rVal<<endl;
    cout<<"____________________________________"<<endl;
        return true;
    }

    return false;
}


void Solve(int k, vector<int> & s , vector<int>& u ,vector<char>&letters){

    if(solutionFound)
    return;
    
    if(k == 0 ){

        //building map
        for(size_t i = 0;i<letters.size();i++){
            pairing[letters[i]] = s[i];
        } 
        
        //checking leading character's values are not 0
        for(char c : leadingChars){
            if(pairing[c] == 0){
                return;
            }
            
        }

        //checking if values are a solution
        if(isSolve(pairing,word1,word2,result)){

        }
         return;
    }  

    else{
        for(size_t i = 0; i< u.size();i++){
            int num = u[i];

            s.push_back(num);
            
            vector<int> newU = u;
            newU.erase(newU.begin()+ static_cast<long>(i));

            Solve(k-1,S,newU,letters);

            s.pop_back();
        }
    }

}

int main(){
   
    cout<<"Enter word 1: ";
    cin>>word1;

    cout<<"Enter word 2: ";
    cin>>word2;

    cout<<"Enter result: ";
    cin>>result;

    //storing leading character
    leadingChars.insert(word1[0]);
    leadingChars.insert(word2[0]);
    leadingChars.insert(result[0]);

    //storing all unique chars into a set
    for(char c: word1){
        uniqueChars.insert(c);
    }

    for(char c: word2){
        uniqueChars.insert(c);
    }
    for(char c: result){
        uniqueChars.insert(c);
    }

    //checking if puzzle can be solve or not
    if(uniqueChars.size()>10){
        cout<<"Cannot solve the puzzle, too many characters"<<endl;
        return -1;
    }

    //creating a vector of the unique characters to be able to use index
    vector<char> letters(uniqueChars.begin(),uniqueChars.end());


    Solve(static_cast<int>(letters.size()),S,U,letters);

    if(!solutionFound)
    cout<<"No solution exists for this puzzle • ᴖ •"<<endl;

  

    return 0;
}
 