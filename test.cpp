
//define zone------------------------------------------------------------------
#include <iostream>
#include "array_tools.h"
#include "integral.h"
#include <cmath>



//methods zone-----------------------------------------------------------------
using namespace std; 




//support methods zone --------------------------------------------------------




void readMatrixSize(int* countLine, int* countColumn)
{
    cout << "Enter Line count:";
    cin >> *countLine;
    cout <<"Enter Column count:";
    cin >> *countColumn;
}



/*
It isn't worked. Require BOOST, or refactoring the "integral" function definition ( I do not know,how)
So, TODO.
double (*readFunc())(double)
{
    
    

  //reading function. In fact, this is sort of hell.
  // I'm so sorry for this, but I can't find way to return lambda-function,
  // with it's capture variables. Any way I founded will make real hell in my code. 
  //So, it's worked. May be...   

    function<function<double (double)> ()> lambdaGen =
        [] (double x) -> function<double (double)>
    {
      
    
        int choice = 0;    
        while (choice > 3 || choice < 1 )
        {   
            cout << "Select template for function: " << endl;

            cout << "1: a * sin ^ b (c * x)" << endl;
            cout << "2: a * cos ^ b (c * x)" << endl;
            cout << "3: ax^n + bx^(n-1) +  ... + (lastIndex)x + (constant)" << endl;
            cin >> choice; 

        }


        switch (choice)
        {
            case 1:
            {
                double a,b,c;

                cout << "Enter a: ";
                cin >> a; 
                cout << "Enter b: ";
                cin >> b; 
                cout << "Enter c: ";
                cin >> c; 
                auto func = [a, b, c](double x)->double {
                return a * pow(sin(c * x),b); };

            return func;

            }break;

            case 2:
            {
                double a,b,c;

                cout << "Enter a: ";
                cin >> a; 
                cout << "Enter b: ";
                cin >> b; 
                cout << "Enter c: ";
                cin >> c; 

                auto func =  [a, b, c](double x)->double {
                return a * pow(cos(c * x),b); };


                return func;

            } break;
            
            case 3:
            {
                int n;
                cout << "Now you should enter the hightest power, integer." << endl;  
                cout << " And then you should enter sequence of coefficent, float, ";
                cout << "begin with \"a\" and end with \"(const)\" " << endl;
                cout << "Enter the highest power: ";
                cin >> n;
                cout << "Enter the sequence of coefficent:" << endl; 

                int* coef = new int[n+1];
                for (int i = n; i >= 0; i-- )
                {
                    cout << "power " << i << ": ";
                    cin  >> coef[i];
                }

                auto func = [coef,n](double x ) -> double {
                
                double acum = coef[0];
                double xx = 1;  
                for (int i = 1; i <= n; i++)
                {
                    acum += xx * x * coef[i];
                }
                return acum;
            };

            return func;


            } break;

        }
  };
    return lambdaGen();
} 

*/


//main methods zone------------------------------------------------------------




void test_printlArray()
{
    cout << "the \"println matrix \" is tested..." << endl;

    int countColumn; 
    int countLine ;
    readMatrixSize(&countLine, &countColumn);

    cout << "the array is generated...";
    int*  matrix= genRandomMatrix(countLine, countColumn);
    cout << "done." << endl;

    cout << "array will printed by navite tools:" << endl;
    for (int i = 0; i < countLine; i++)
    {
        for (int j = 0; j < countColumn; j++)
        {
            cout << matrix[i * countColumn + j] << ' ' ;
        }
        cout << endl;
    }
    cout << endl <<endl <<endl;
    
    cout << "the array will printed by \" printlnMatrix \"  "  << endl; 
    printlnMatrix<int>(matrix, countLine, countColumn);
    cout << "done." << endl;

    cout << "End of testing. " << endl;
}


void test_genZigZagMatrix()
{
    int countColumn;
    int countLine; 
    readMatrixSize(&countLine, &countColumn);
    


    cout << "the array is generated...";
    int* matrix = genZigZagMatrix(countLine,countColumn);
    cout << "done." << endl;
    cout << "the array will printed by \" printlnMatrix \"  "  << endl; 
    printlnMatrix(matrix,countLine,countColumn,7);

    cout << "End of testing." << endl;

}



void test_integrate()
{
    int dotCount;
    double leftWall;
    double rightWall;
    
    cout << "Enter left extreme value: ";
    cin >> leftWall; 
    cout << "Enter right extreme value: ";
    cin >> rightWall;
    cout << "Enter count of dot: ";
    cin >> dotCount;
  
  
  
    const char* func[3] = {"1: f(x) = const;  const is \"1\"",
                     "2: f(x) = sin(x);",
                     "3: f(x) = x^2 + x + 1; "};
  
  
  
    int choice = 0; 
    while (choice < 1 || choice > 3)
    {
        cout << "Please, select function for testing:" << endl; 
        cout <<  func[0]<< endl;
        cout << func[1] << endl; 
        cout << func[2] << endl;
        cin >> choice; 
    }
  
    cout << "The function is  " << func[choice-1] << endl;
    cout << "Integrate...";
    double result;
    switch (choice)
    {
      case 1: 
          {
             
              result = integrate ([](double x) -> double {
                  return 1; 
              }, leftWall, rightWall, dotCount);
             
  
          } break;
      case 2:
          {
              
              result = integrate ([](double x) -> double {
                  return sin(x); 
              }, leftWall, rightWall, dotCount);
          
          } break;
      case 3:
          {
              
              result = integrate ([](double x) -> double {
                  return x*x + x + 1; 
              }, leftWall, rightWall, dotCount);
      
          }break;
  
    }
    cout << "done" << endl;
    cout << "The answer is \" " << result << "\""  << endl;
    cout << "end of testing" << endl;
  
}


void cycle()
{
    int choice = 0;
    while (true)
    {
      cout << "Select testing function:" << endl; 
      cout << "1: \"printlnMatrix\" ;" << endl;
      cout << "2: \"genZigZigMatrix\" ;" << endl; 
      cout << "3: \"integrate\" ;" << endl;
      cout << "-1: exit." << endl;
      cout << ":";
      cin >> choice; 
      if (choice == -1)
          return ;
  
      if (choice == 1 )
          test_printlArray();
      else if (choice == 2)
              test_genZigZagMatrix();
          else 
              test_integrate();
      
      
  
    }
  
}

int main(int count, char* args[])
{   
  cycle();
   
  return 0;
}