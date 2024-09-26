#include <iostream>
#include <chrono>

using namespace std;
using namespace chrono;

int FibonacciRec(int n){
    if (n == 0 || n==1){return n;}
    else {
        {
            return FibonacciRec(n-1)+FibonacciRec(n-2);
            }
}
}

void FibFor(int n){
    int fib=0, fib2=1, fib3=0;
    //int num;
    for(int i=1; i<=n; ++i){
        if (i==0){
            cout<<fib<<" ";
        }
        if (i==1){
            //cout<<fib2<<" ";
        }
        fib3=fib+fib2;
        fib=fib2;
        fib2=fib3;
        //cout<<fib3<<" ";
        
    }
    cout<<fib3;
}

int main()
{
    //NOTE: Below is for For Recursive Fibonacci
    int fibo;
    int j=1;
    int r;
    cout<< "Enter Index for Recursive Fibonacci Sequence: "<<endl;
    cin>>fibo;
    cout<<"Index "<<fibo<<" of the Recursive Fibonacci Sequence: ";
auto start_time = chrono::high_resolution_clock::now(); //Start time
    while (j<=(fibo+1)){
        r = FibonacciRec(j);
        //cout<<FibonacciRec(j)<< " ";
        j++;
    }
    cout<<r<<endl;
    auto end_time = chrono::high_resolution_clock::now(); //End time
chrono::duration<double> elapsed = end_time - start_time; //Total time 
cout << "Elapsed time for Recursion Fibonacci: " << elapsed.count() << " seconds" << endl<<" "<<endl;

//NOTE: Below is for For Loop Fibonacci
    int n;
    cout<<"Enter Index of Iterative Fibonacci Sequence: "<<endl;
    cin>>n;
    cout<<"Index "<<n<<" of the Iterative Fibonacci Sequence: ";
auto start_time2 = chrono::high_resolution_clock::now(); //Start time
    FibFor(n);
auto end_time2 = chrono::high_resolution_clock::now(); //End time
chrono::duration<double> elapsed2 = end_time2 - start_time2; //Total time 
cout<<endl<< "Elapsed time for Iterative Fibonacci: " << elapsed2.count() << " seconds" << endl<<" "<<endl;

    return 0;
}


