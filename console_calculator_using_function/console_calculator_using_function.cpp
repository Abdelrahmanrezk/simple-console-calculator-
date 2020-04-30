#include <bits/stdc++.h>
#define ll long long
#include <string>
using namespace std;

const int N = 1e6+5 , M = 3 , nBits = 2e8 +5 , MM = (1 << 16) , MAX =  1111 , OO = 0x3f3f3f3f , MOD = 1000000007  , inf =  1 << 30;
ll  t , q , n , m , x,a,b,c;
ll arr[N],arr2[N];

char ch1[1000];
char ch2[1000];


void read_two_numbers(double &x, double &y){
    /*

    Arguments:
    x: is first number that user will enter and it will affected on the main function as we send
    y: second number that user will enter and it will affected on the main function as we send

    Validation:
    Check the user input because of strings or chars or even 0 for second number

    Return:
    No return but take care the argument is sending by refrence so once 
    any of these parameters will affect on the whole program

    */
    puts("Please Enter Two numbers");
    
        cin >> x >> y;
        if(cin.fail())
        {
            puts("You have Enter incorrect numbers please try again");
            cin.clear();
            cin.ignore(1000, '\n');
            return read_two_numbers(x,y); // recursion
        }else if(y == 0)
        {
            puts("Can not divide by 0 please try again two vaid numbers");
            cin.clear();
            cin.ignore(1000, '\n');
            return read_two_numbers(x,y); // recursion
        }
}
bool summation(double x, double y, double &sum){
   /*

    Arguments:
    x: is first number that user have enterd
    y: second number that user have enterd

    Validation:
    sum the two numbers into same variables which send as by reference
    Return:
    True if the operation done

    */
    sum = x + y;
    return true;
}
bool subtraction(double x, double y, double &sub){
    /*
    The same as summation function
    */
    sub = x - y;
    return true;
}
bool multiplication(double x, double y, double &multiply){
    /*
    The same as summation function
    */
    multiply = x * y;
    return true;
}
bool division(double x, double y, double &divs){
    /*
    The same as summation function
    */
    divs = x / y;
    return true;
}
int choice_operator(){
    /*
    Arguments:
    No argument send

    Validation:
    check which number the user choose and then validate this number as in range from 1 to 5,
    first check its valid number or not
    second check if its within the range [1-5]

    Return:
    the number that user choose which one of these [1 or 2 or 3 or 4 or 5]
    */
    puts("Please Enter 1 for summation(+)");
    puts("Or Enter 2 for subtraction(-)");
    puts("Or Enter 3 for multiplication(*)");
    puts("Or Enter 4 for division(/)");
    puts("Or Enter 5 for trying other two numbers");
    int choice;
    cin >> choice;
    if(cin.fail()){
        puts("You entered incorrect number please try again");
        cin.clear();
        cin.ignore(1000, '\n');
        return choice_operator();
    }else if(choice < 1 || choice > 5){
        puts("You entered correct number but invalid range which should be [1-5]");
        cin.clear();
        cin.ignore(1000, '\n');
        return choice_operator();
    }
    return choice;

}
double calculation_result(int choice, double x, double y, double &result){
    /*

    Argument:
    choice: the user choice number which in range[1-5]
    x: the number that user enter
    y: the number that user enter
    result: which will be affected on any of the choice operation

    Validation:
    check which one of these operation the user chosen, but in case of 5:
        return: 
            - the function that again enter two numbers
            - then again choice_operator function for new operation
            - return the same function calculation_result
    Return:
    result: which our referenced sending parameters that hold the change of calculation


    */
    if(choice == 1) summation(x,y, result);
    else if(choice == 2) subtraction(x,y, result);
    else if(choice == 3) multiplication(x,y, result);
    else if(choice == 4) division(x,y, result);
    else if(choice == 5) {
        read_two_numbers(x,y);
        int choice = choice_operator();
        return calculation_result(choice, x, y, result);

    }
        
    return result;
    
}
int main(){	
    double x=0, y=0, result = 0;
    read_two_numbers(x,y);
    int choice = choice_operator();
    result = calculation_result(choice, x, y, result);
    cout << result << endl;

return 0;
}