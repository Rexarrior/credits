#ifndef ARRAYS_TOOLS
#define ARRAYS_TOOLS


//define zone------------------------------------------------------------------

#include <cstdlib>
#include <iostream>



//methods----------------------------------------------------------------------


int* genRandomMatrix(int, int );

int* genZigZagMatrix(int,int, bool);

template<typename T>
void printlnMatrix(T* matrix, int countLine,  int countColumn, const int fieldWidth = 7 , const  int precisionValue = 5)
{
    using namespace std;
  
  
    
    for (int i = 0; i < countLine; i++)
    {
        for (int j = 0; j < countColumn; j++)
        {
            cout.width(fieldWidth);
            cout.precision( precisionValue);
            cout <<  matrix[i * countColumn + j] ;
        }
        cout << std::endl;
    }

    
    return;
}
#endif
