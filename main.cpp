#include "polinomy.h"
int main()
{
 polinomy a, b, c;

 a.setMonomy(1,"x,24*z,3");
 b.setMonomy(1,"x,25*z,1");
 cout<<"dy/dx[ ( ";
 a.print();
 cout<<" ) * (";
 b.print();
 cout<<" ) ]=\n";

 c=(a.der("x")*b)+(a*b.der("x"));
 c.print();cout<<"\n";





    return 0;
}
