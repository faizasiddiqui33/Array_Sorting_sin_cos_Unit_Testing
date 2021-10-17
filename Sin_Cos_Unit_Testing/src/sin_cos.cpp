#include "sin_cos.h"
#include <iostream>
using namespace std;
sin_cos::sin_cos()
{
    //ctor
}

sin_cos::~sin_cos()
{
    //dtor
}
/** These functions compute the sine and cosine of an angle
    expressed in degrees. The result will be
    an integer representing the sine or cosine as
    ten-thousandths. For example, a result of 7071 represents
    7071e-4 or 0.7071.
*/

// Forward declarations
int sin0to45(int);
int sin45to90(int);
int polyEval(int, int[], int);

/** Compute the sine of an angle in degrees.
    @param x The angle in degrees
    @return The sine of x
*/
int sin(int x) {
  if (x < 0) {
    x = -x;
  }
  x = x % 360;
  if (0 <= x && x <= 45) {
    return sin0to45(x);
  }
  else if (45 <= x && x <= 90) {
    return sin45to90(x);
  }
  else if (90 <= x && x <= 180) {
    return sin(180 - x);
  }
  else {
    return -sin(x - 180);
  }
}

/** Compute the cosine of an angle in degrees.
    @param x The angle in degrees
    @return The cosine of x
*/
int cos(int x) {
  return sin(x + 90);
}

/** Compute the sine of an angle in degrees
    between 0 and 45.
    pre: 0 <= x < 45
    @param x The angle
    @return The sine of x
*/
int sin0to45(int x) {
  // Code to compute sin(x) for x between 0 and 45 degrees
  // Evaluate a polynomial optimized for this range.
  int coef[] = {
    -81, -277, 1747900, -1600};
  return polyEval(x, coef, 4) / 10000;
}

/** Compute the sine of an angle in degrees
    between 45 and 90.
    pre: 45 <= x <= 90
    @param x The angle
    @return The sine of x
*/
int sin45to90(int x) {
  // Code to compute sin(x) for x between 45 and 90 degrees
  // Evaluate a polynomial optimized for this range.
  int coef[] = {
    336, -161420, 75484, 999960000};
  return polyEval(90 - x, coef, 4) / 100000;
}

/** Function to evaluate a polynomial
    @param x The point at which the polynomial is to be evaulated
    @param coef The array of coefficients
    @param n The number of coefficients (degree + 1)
    @return x^n-1*coef[0] + x^n-2*coef[1] + ... x*coef[n-2] + coef[n-1]
*/
int polyEval(int x, int coef[], int n) {
  int result = 0;
  for (int i = 0; i < n; i++) {
    result *= x;
    result += coef[i];
  }
  return result;
}


int main()
{
    /*
    for our white box testing, we use different range of values to test
        the outputs of the different functions

    */
    //whitebox test cases

    int x = 30;
    int x1 = 50;
    int x2 = 60;
    int x3 = 100;
    int x4 = 120;
    int x5 = -25.00;
    int x6[] = {10, 0, 35};
    int n = 8;

    //testing sines
    cout <<"sine: " <<x1 << " is: " << sin(x1) << endl;
    cout <<"sine: " <<x3 << " is: " << sin(x3) << endl;
    cout <<"sine: " <<x5 << " is: " << sin(x5) << endl;
    //testing cosines

    cout <<"cosine: " << x1 << " is: " << cos(x1) << endl;
    cout <<"cosine: " << x2 << " is: " << cos(x2) << endl;

    //testing intsin0to45

    cout << "sine: " << x1 << " is: " << sin0to45(x1) << endl;
    cout << "sine: " << x << " is: " << sin0to45(x) << endl;

    //testing sine45to90

    cout <<"sine: " << x4 << " is: " << sin45to90(x4) << endl;

    //testing polyeval
    cout << "Polyeval of: " << x2 << " is: " << polyEval(x2, x6, n) << endl;
    cout << "Polyeval of: " << x1 << " is: " << polyEval(x1, x6, n) << endl;
    return 0;
}

