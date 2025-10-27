#include<bits/stdc++.h>
using namespace std;

int numberOfBeams(vector<string>& bank) {
        int n  = bank.size();

        int prev = 0;
        int result =  0;

        for(int i  =  0; i<n; i++){
            int curr =  0;
            for(char &ch : bank[i]){
                if(ch == '1'){
                    curr++;
                }
            }

            result += prev*curr;
            if(curr!=0){
                    prev =  curr;
            }
        }
        return result;
    }

int main(){
    vector<string> bank1 = {
        "011001",
        "000000",
        "010100",
        "001000"
    };

    cout<<"Output :- "<<" "<<numberOfBeams(bank1)<<endl;
}