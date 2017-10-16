//define zone------------------------------------------------------------------

#include <iostream>


//methods zone ----------------------------------------------------------------


double countBySympson(double (*func)(double), double left, double right)
{
    double fleft = func(left);
    double fright = func(right);
    double fmidle = func((left + right) / 2);
    double factor = (right - left) / 6; // can be optimized. 

    double result = factor * (fleft + 4 * fmidle + fright);

    // std:: cout << "Sympson's function has returned:" << result << std:: endl;
    return result;
}


double integrate(double (*func)(double), double leftWall, double rightWall, int dotCount )
{

    double step = (rightWall - leftWall) / dotCount; 

    double current = leftWall + step;
    double result = countBySympson(func,leftWall, current);

     
    while (current < rightWall)
    {
        result += countBySympson(func,current,current + step);
        current += step; 
    }

    current -= step;

    result += countBySympson ( func, current, rightWall);
    

    return result; 
}