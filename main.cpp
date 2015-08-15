#include "polinomy.h"
int main()
{
 polinomy a, b, c;
 a.getMonomy(1,"x",3);

 b.getMonomy(1,"x",2);
 b.getMonomy(2,"x",frac(4,6));

c=(a+a)/b;

cout<<"F[x] =  ";c.print();cout<<"\n";
cout<<"|F[x]dx =  ";c.integ("x");
c.print();cout<<"\n";
cout<<"[|F[x]dx]/dx =   ";c.der("x");
c.print();cout<<"\n";
    return 0;
}
