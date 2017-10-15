
//define zone------------------------------------------------------------------


#include <iostream>


//methods zone-----------------------------------------------------------------
using namespace std;

int* genRandomMatrix(int countLine, int countColumn)
{
    int* matrix = new int[countLine, countColumn];

    for (int i = 0; i < countLine; i++)
    {
        for (int j = 0; j < countColumn; j++)
        {
            matrix[i * countColumn + j] = rand() % 100;
        }
    }
    return matrix;
}


bool chechWall(bool isUp, int i, int j, int countLine, int countColumn)
{
    if (isUp)
    {
        if (j + 1 < countColumn && i - 1 >= 0)
            return true;
    }
    else
    {
        if (j - 1 >= 0 && i + 1 < countLine)
            return true;
    }

    return false;
}

int* genZigZagMatrix(int countLine, int countColumn)
{
    int* matrix = new int[countLine,countColumn];


    int counter = 0; 
    int maxCounterValue = countLine * countColumn;
    bool isUp = true; 
    
    

    int i = 0; int j = 0; 
    while (counter <=  maxCounterValue)    
    {
       
        // cout << i << ' ' << j << endl;
        counter ++;
        matrix[i*countColumn + j] = counter; 
        if (isUp)
            if (j+1 < countColumn)
                j++;
            else 
                i++; 
        else
            if (i+1 < countLine)
                i++;
            else
                j++;
        isUp = !isUp;

        

        while (chechWall(isUp,i,j,countLine,countColumn))
        {    
            // cout << i << ' ' << j << endl;
            counter ++;
            matrix[i*countColumn + j] = counter; 

            if (isUp)
            {
                i--;
                j++;
            }
            else
            {
                i++;
                j--;
            }

         
        }
    }

    return matrix;
}





