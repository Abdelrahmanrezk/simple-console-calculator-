#include <bits/stdc++.h>
#define ll long long
#include <string>
using namespace std;

const int N = 1e6+5 , M = 3 , nBits = 2e8 +5 , MM = (1 << 16) , MAX =  1111 , OO = 0x3f3f3f3f , MOD = 1000000007  , inf =  1 << 30;
ll  t , q , n , m , x,a,b,c;
ll arr[N],arr2[N];

char ch1[1000];
char ch2[1000];
int main(){	

    puts("|\t\t Simple Console Calculator\t\t\t|");
    goToEnterTwoNubers:
    puts("Please enter two numbers");
    double num1, num2, res=0;
    int operator_choice = 0;
    
    cin >> num1 >> num2;
    if(cin.fail()){
        puts("something going wrong with your input");
        cin.clear();
        cin.ignore(10000, '\n');
        goto goToEnterTwoNubers;
    }else if(num2 == 0){
         puts("Can not divide by 0");
        cin.clear();
        cin.ignore(10000, '\n');
        goto goToEnterTwoNubers;
    }

    goToOperationChoise:
    puts("Please enter Operation which [1 for +] OR [2 for -] OR [3 for *] OR [4 for /] [5 for enter another two numbers]");
    cin >> operator_choice;
    if(cin.fail()){
        puts("something going wrong with your operator choice");
        cin.clear();
        cin.ignore(10000, '\n');
        goto goToOperationChoise;
    }else if(operator_choice < 1 || operator_choice > 5){
         puts("Please choose in range [1-5]");
        cin.clear();
        cin.ignore(10000, '\n');
        goto goToOperationChoise;
    }

    switch (operator_choice)
    {
    case 1:
        res = (num1+num2);
        printf("%.2lf\n", res);
        break;
    case 2:
        res = (num1-num2);
        printf("%.2lf\n", res);
        break;
    case 3:
        res = (num1*num2);
        printf("%.2lf\n", res);
        break;
    case 4:
        res = (num1/num2);
        printf("%.2lf\n", res);
        break;
    case 5:
        goto goToEnterTwoNubers;
        break;
    }
return 0;
}