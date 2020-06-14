#include <stdio.h>
#include <iostream>

using namespace std;

class A
{
public:
   A(int ii):I(ii)
    {
    }
    virtual ~A(){}

    // member function is const
    // member data cannot be changed in this function
    int sum_with_input(int input_data) const
    {
        int sum = I + J + data + input_data; 
        
        cout << "sum_with_input: " << sum << endl;
    }

    // function parameter is const
    // the const parameter cannot be changed in this function
    int sum_of_two_A(const A& ai) 
    {
        int sum = I + J + data + ai.I + ai.J + ai.data; 
        cout << "sum_of_two_A: " << sum << endl;
    }
public:
    // member data is const, object-wide const
    // init from initialize list 
    const int I; 
    
    // static data is const, class-wide const
    // init from definition 
    static const int J;

    int data;
    
    
};


// a const var whoese value is initialized at compile time
const int SIZE = 4;
// static const definition and initialization
const int A::J = 100;

int main()
{
    // actually, var s is a const char *, 
    // the memory content pointerd by s cannot be changed
    char* s = "Hello, world\n";
    cout << s << endl;
    // Error, manipulate the content of from a const string
    // s[0] = 'B'; 

    int ii = 3;
    int jj = 4;
    int* const pi = &ii;  // pi is read-only
    const int *pj = &jj; // *pj is read-only
    // error, assignment of read-only variable 'pi' 
    // pi = &jj;
    *pi = 6;
    // error, assignment of read-only variable '*pi' 
    // *pj = 5;
    // OK, pi us is not a read-only
    pj = &ii;

    A a1(10);
    A a2(20);
    a1.sum_with_input(101);
    a2.sum_of_two_A(a2);

    int b[SIZE]; //OK
    
    return 0;
}
