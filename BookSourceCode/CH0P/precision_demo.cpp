/* Program to demonstrate the effect of precision on different 
   floating-point output formats. */

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
  double d = 12345.6789;
  // Display the column headers
  cout << setw(10) << "precision" << setw(18) << "general" << setw(18) 
       << "fixed" << setw(18) << "scientific\n";
  for (int i = 10; i >= 0; i--) {
    // Set the precision
    cout << setprecision(i);
    cout << setw(10) << i;
    // Set the format to general
    cout << resetiosflags(ios_base::fixed | ios_base::scientific);
    cout << setw(18) << d;
    // Set the format to fixed
    cout << fixed << setw(18) << d;
    // Set the format to scientific
    cout << scientific << setw(18) << d << endl;
  }
}
