#include<bits/stdc++.h>
using namespace std;
bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();
        int i = 0;

        while(i < n-1) {
            if(bits[i]==1){
                i+=2;
            }else{
                i++;
            }
        }

        return i == n-1;
    }

int main(){
    vector<int> n = {1001000};
    int result = isOneBitCharacter(n);
    int Updateresult = isalpha(result);
    cout<<Updateresult<<endl;
}