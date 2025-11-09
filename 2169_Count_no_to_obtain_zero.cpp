#include<bits/stdc++.h>
using namespace std;

int  CountOperation(int num1 , int num2){
    int count = 0;
    while(num1 > 0 && num2 > 0){
        if(num1>=num2){
            num1-=num2;
            count++;
        }
        else{
            num2-=num1;
            count++;
        }
    }
    return count;
}
// better apporch  
// int countOperations(int num1, int num2) {
//         int count = 0;

//         while(num1 > 0 && num2 > 0) {
//             count += num1/num2;

//             num1 %= num2;

//             swap(num1, num2);
//         }

//         return count;
//     }
// optimal 
// int countOperations(int num1, int num2) {
//         if(num1 == 0 || num2 == 0)
//             return 0;

//         if(num1 < num2)
//             swap(num1, num2);

        
//         return num1/num2 + countOperations(num1%num2, num2);
//     }

int main() {
    int num1,num2;
    cout<<"Give  the num 1"<<endl;
    cin>>num1;
    cout<<"Give the num2"<<endl;
    cin>>num2;

    int result = CountOperation(num1, num2);
    cout<<"The totaloperation is "<<result<<endl;
}