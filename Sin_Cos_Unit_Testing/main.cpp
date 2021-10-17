/*****************************************************************************************************************************
Module Name: White-box texting of sine and cosine of numbers
Author: Faiza Fatma Siddiqui
Date Created/Modified:12.10.2021
Student ID: 200473896
Purpose: CS 700 Assignment 2 
*****************************************************************************************************************************/


/// Library for input output capabilities
#include <iostream>

/// To store a line that is read from input file
using namespace std;
/** These functions compute the sine and cosine of an angle
    expressed in degrees. The result will be
    an integer representing the sine or cosine as
    ten-thousandths. For example, a result of 7071 represents
    7071e-4 or 0.7071.
*/


/// Function Declarations
int sin0to45(int);
int sin45to90(int);
int polyEval(int, int[], int);


/** Function to compute the sine of an angle in degrees
    @param x The angle in degrees
    @return The sine of x
*/
/// Function Definition to compute sine
int sin(int x)
{
  /// To find sine of an angle less than 0
  if (x < 0)
  {
    x = -x;
  }
  x = x % 360;

  /// To find sine of an angle between 0 and 45
  if (0 <= x && x <= 45)
  {
    return sin0to45(x);
  }

  /// To find sine of an angle between 45 and 90
  else if (45 <= x && x <= 90)
  {
    return sin45to90(x);
  }

  /// To find sine of an angle between 90 and 180
  else if (90 <= x && x <= 180)
  {
    return sin(180 - x);
  }

  /// In all other cases, find sine of any angle other than the ranges tested above
  else
  {
    return -sin(x - 180);
  }
}


/** Compute the cosine of an angle in degrees.
    @param x The angle in degrees
    @return The cosine of x
*/
/// Function Definition to compute cosine
int cos(int x)
{
  return sin(x + 90);
}


/** Compute the sine of an angle in degrees
    between 0 and 45.
    pre: 0 <= x < 45
    @param x The angle
    @return The sine of x
*/
/// Function Definition to compute sin(x) for x between 0 and 45 degrees
int sin0to45(int x)
{
  /// Evaluate a polynomial optimized for this range
  int coef[] = { -81, -277, 1747900, -1600 };
  
  /// polyEval is a function to evaluate a polynomial
  return polyEval(x, coef, 4) / 10000;
}


/** Compute the sine of an angle in degrees between 45 and 90.
    pre: 45 <= x <= 90
    @param x The angle
    @return The sine of x
*/
/// Function Definition to compute sin(x) for x between 45 and 90 degrees
int sin45to90(int x)
{
  // Evaluate a polynomial optimized for this range
  int coef[] = { 336, -161420, 75484, 999960000 };

  /// polyEval is a function to evaluate a polynomial
  return polyEval(90 - x, coef, 4) / 100000;
}


/** Function to evaluate a polynomial
    @param x The point at which the polynomial is to be evaulated
    @param coef The array of coefficients
    @param n The number of coefficients (degree + 1)
    @return x^n-1*coef[0] + x^n-2*coef[1] + ... x*coef[n-2] + coef[n-1]
*/
/// Function Definition to evaluate a polynomial
int polyEval(int x, int coef[], int n)
{

  int result = 0;

  for (int i = 0; i < n; i++)
  {
    result *= x;
    result += coef[i];
  }

  return result;
}


/*****************************************************************************************************************************
Module Name: White-box texting of sine and cosine of numbers
Author: Faiza Fatma Siddiqui
Date Created/Modified:12.10.2021
Purpose: Main Function 
No Arguments, 0 is the return value, if no error
******************************************************************************************************************************/
int main()
{
  /*
    For our white box testing, we use different range of values
        to test the outputs of the different functions
    */

  /// Whitebox test cases
  int x = 30;
  int x1 = 50;
  int x2 = 60;
  int x3 = 100;
  int x4 = 120;
  int x5 = -25.00;
  int x6[] = { 10, 0, 35 };
  int n = 8;

  /// Testing sines and printing output
  cout << "sine: " << x1 << " is: " << sin(x1) << endl;
  cout << "sine: " << x3 << " is: " << sin(x3) << endl;
  cout << "sine: " << x5 << " is: " << sin(x5) << endl;

  /// Testing cosines and printing output
  cout << "cosine: " << x1 << " is: " << cos(x1) << endl;
  cout << "cosine: " << x2 << " is: " << cos(x2) << endl;

  /// Testing intsin0to45 and printing output
  cout << "sine: " << x1 << " is: " << sin0to45(x1) << endl;
  cout << "sine: " << x << " is: " << sin0to45(x) << endl;

  /// Testing sine45to90 and printing output
  cout << "sine: " << x4 << " is: " << sin45to90(x4) << endl;

  /// Testing polyeval and printing output
  cout << "Polyeval of: " << x2 << " is: " << polyEval(x2, x6, n) << endl;
  cout << "Polyeval of: " << x1 << " is: " << polyEval(x1, x6, n) << endl;
 
  /// Return 0 if program executed successfully because main function is of type integer
  return 0;
}