#include "polinomy.h"
int main()
{
 polinomy a, b, c;

 a.setMonomy(1,"x",3);
 b.setMonomy(1,"x",3);
 c=a/b;
 c.print();
    return 0;
}
