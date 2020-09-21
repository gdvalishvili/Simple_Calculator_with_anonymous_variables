#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
using namespace std;

int SumNums (int &x, int &y);                      //function prototype for addition  
int SubNums (int &x, int &y);                      //function prototype for subtraction
int MultNums (int &x, int &y);                     //function prototype for multiplication
double DivNums (int &x, int &y);                   //function prototype for division
int ModNums (int &x, int &y);                      //function prototype for module
int powNums (int &x, int &y);                      //function prototype for power
double sqrtNums (int &x, int &y);                  //function prototype for square root
string PrintResults (char *a, int *b, int *c);     //function prototype for Display results
 
int main(){

    int *num1 = new int;         //anonymous variable for first number
    int *num2 = new int;         //anonymous variable for second number
    char *oprd = new char;       //anonymous variable for operand
    char *ask = new char;        //anonymous variable for continue/exit from program

    cout<<"Simple Calculator!\n"<<endl;

    do {
        cout << "Enter the operand (+,-,*,/,%,^,"<<(char)-5<<") which you wish to perform for the operation: (enter 'D' for show description)"<<endl;  //(char)-5 = "√"
        cin>>*oprd;     //enter the operand for the operation

        //Description of operands
        if (*oprd == 'd' || *oprd == 'D' ) {
            cout<<"+"<< " - addition two numbers.          \t ex: a + b"<<endl;
            cout<<"-"<< " - subtraction two numbers.       \t ex: a - b"<<endl;
            cout<<"*"<< " - multiplication two numbers.    \t ex: a * b"<<endl;
            cout<<"/"<< " - division two numbers.          \t ex: a / b"<<endl;
            cout<<"%"<< " - module division two numbers.   \t ex: a % b "<<endl;
            cout<<"^"<< " - power two numbers.             \t ex: a ^ b"<<endl;
            cout<<(char)-5<< " - square root two numbers." <<setw(19)<<" ex: a " <<(char)-5 <<" b "<<endl;
            cout << "\nEnter the operand (+,-,*,/,%,^,"<<(char)-5<<") which you wish to perform for the operation:"<<endl;  //(char)-5 = "√"
            cin>>*oprd; 
        }
        //Check correction of entered operand
         if (*oprd != '+' && *oprd != '-' && *oprd != '*' && *oprd != '/' && *oprd != '%' && *oprd != '^' && *oprd != (char)-5){
            cout<<*oprd <<" is not valid, please enter valid operand"<<endl;    //print if operand is not correct
            break;                                                              //and stop wordking program
        }
        cout<<"Enter two numbers: (ex: a b)"<<endl;
        cin >> *num1;   //enter Number 1
        cin >> *num2;   //enter Number 2

    //check chosen operand (+,-,*,/,%,^,√) and make appropriate task
        if (*oprd == '+')                         
            cout<<PrintResults(oprd,num1,num2)<<SumNums(*num1,*num2)<<endl;
        else if (*oprd == '-')
            cout<<PrintResults(oprd,num1,num2)<<SubNums(*num1,*num2)<<endl;
        else if (*oprd == '*')
            cout<<PrintResults(oprd,num1,num2)<<MultNums(*num1,*num2)<<endl;
        else if (*oprd == '/') {
            if (*num2 == 0) {                           //In math, can't division on zero, therefore we use additional check
                cout<<"Wrong operation, you may not divide by zero"<<endl;
                break;                                  //If Second Number is 0, program stop working, otherwise it will continue to work
            }
                else
            cout<<PrintResults(oprd,num1,num2)<<DivNums(*num1,*num2)<<endl;
        }
        else if (*oprd == '%')
            cout<<PrintResults(oprd,num1,num2)<<ModNums (*num1,*num2)<<endl;
        else if (*oprd == '^')
            cout<<PrintResults(oprd,num1,num2)<<powNums (*num1,*num2)<<endl;
        else if (*oprd == (char)-5)
            cout<<PrintResults(oprd,num1,num2)<<sqrtNums (*num1,*num2)<<endl;
        else
            cout<<"Check Caracter Correction"<<endl;    //print if user entered any non valid caracter

        cout<<"Do you want ontinue? (Y/N)"<<endl;
        cin>>*ask;

    } while ( *ask == 'y' || *ask == 'Y' );
    cout<<"Exited!"<<endl;
}

//addition function
int SumNums (int &x, int &y) {
    return ( x + y );
}

//subtraction function
int SubNums (int &x, int &y) {
    return ( x - y );
}

//multiplication function
int MultNums (int &x, int &y) {
    return ( x * y );
}

//division function
double DivNums (int &x, int &y) {
    return ((double) x / y );
}

//module function
int ModNums (int &x, int &y) {
    return ( x % y );
}

//power function
int powNums (int &x, int &y){
    return pow(x, y);
}

//square root function
double sqrtNums (int &x, int &y) {
    return pow(x, 1./y);
}

//Display function
string PrintResults(char *a, int *b, int *c){
    return to_string(*b) + *a + to_string(*c) + string("=");
}