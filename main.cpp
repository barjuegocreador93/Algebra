#include "polinomy.h"
int main()
{
 polinomy a, b, c;
 a.getMonomy(1,"x",0);
 a.getMonomy(3,"x",1);
 b.getMonomy(1,"x",2);

    c=a*b;
    c.print();cout<<"\n";
    c.integ("x");



 c.print();cout<<"\n";
c.der("x");
c.print();cout<<"\n";
    return 0;
}
