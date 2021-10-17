#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

//======================================================================
/** dfdfs **/
void merge( int A[], int first, int mid, int last, int temp[] )
{
   int iA = first, iB = mid, n = last - first;
   for ( int t = 0; t < n; t++ ) temp[t] = ( iB == last ||  ( iA != mid && A[iA] < A[iB] ) ) ? A[iA++] : A[iB++];
   copy_n( temp, n, A + first );
}

void mergeSort( int A[], int n, int start, int temp[] )
{
   if ( n < 2 || ( n == 2 && A[start] <= A[start+1] ) ) return;
   int nlow = n / 2, nhigh = n - nlow, mid = start + nlow;
   mergeSort( A, nlow , start, temp );
   mergeSort( A, nhigh, mid  , temp );
   merge( A, start, mid, start + n, temp );
}

void mergeSort( int A[], int n )
{
   int *temp = new int[n];
   mergeSort( A, n, 0, temp );
   delete [] temp;
}

//======================================================================

int main()
{

   const int N = 10000000;
       // Make N big enough to be worthwhile
   static int A[N];
   srand( time( 0 ) );
   for ( int &e : A ) e = 1 + rand() % 100;


//////////////////
   clock_t t1 = clock();     // START YOUR CLOCK JUST ABOVE WHAT YOU WANT TO TIME

   mergeSort( A, N );        // Whatever you are timing

   clock_t t2 = clock();     // STOP YOUR CLOCK JUST BELOW WHAT YOU WANT TO TIME
//////////////////

   cout << "\nSorting " << N << " numbers took " << 1000.0 * ( t2 - t1 ) / CLOCKS_PER_SEC << " milliseconds\n\n" << endl;
}
