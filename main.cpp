#include "polinomy.h"
int main()
{
 polinomy a, b, c;

 a.setMonomy(1,"x,2");
 a.setMonomy(1,"z,1");
 b.setMonomy(1,"x,2");
 b.setMonomy(1,"z,1");

 cout<<"dy/dx[ ( ";
 a.print();
 cout<<" ) * (";
 b.print();
 cout<<" ) ]=\n";

 c=(a.der("x")*b)+(a*b.der("x"));
 c.print();cout<<"\n";





    return 0;
}
