#include "monomy.h"



class polinomy
{
    public:
        polinomy();
        void make(string tip_num);
        void setMonomy(float,string);
        void oper();
        polinomy der(string var)const;
        polinomy integ(string var)const;
        void print();
        void eraseMonomy(monomy &a);
        polinomy &operator=(const polinomy &);
        polinomy operator*(const polinomy &);
        polinomy operator/(const polinomy &);
        polinomy operator+(const polinomy &a);
        polinomy operator-(const polinomy &a);
        polinomy infunc(string vars_val)const;



    private:
        vector<monomy> alg;
};

polinomy::polinomy()
{

}

void polinomy::make(string tip_num)
{
    char x='z';
    while(x!='c')
    {
        system(_cls);
        cout<<"Crear un monomio?:(x=si||c=no)_:";
        cin>>x;
        if(x=='x')
        {

            monomy a;
            a.make(tip_num);
            alg.push_back(a);
        }
    }
    for(int i=0;i<alg.size();i++)
    {
        alg[i].oper();
    }
    system(_cls);
}

void polinomy::oper()
{
    for(int i=0;i<alg.size()-1;i++)
    {
        for(int j=i+1;j<alg.size();j++)
        {

                if(alg[i]==alg[j])
                {
                    alg[i].num=alg[i].num+alg[j].num;
                    alg.erase(alg.begin()+j);
                    j--;
                }

        }
    }
}



void polinomy::print()
{
    for(int i=0;i<alg.size();i++)
    {
        if(alg[i].num>0&&i!=0)cout<<"+";
        alg[i].print();
    }
}

polinomy polinomy::der(string var) const
{
    polinomy y;
    y.alg=alg;
    for(int i=0;i<alg.size();i++)
    {
        y.alg[i].der(var);
    }
    if(var!="c")
    {
        monomy z;
        z.get(1,"c,1");
        y.eraseMonomy(z);
    }
    y.oper();
    return y;

}

polinomy polinomy::integ(string var) const
{
    polinomy y;
    y.alg=alg;
    for(int i=0;i<alg.size();i++)
    {
        y.alg[i].integ(var);
    }
    if(alg.size()!=0)
    {
        monomy c;
        c.get(1,"c,1");
        y.alg.push_back(c);
    }
    y.oper();
    return y;

}

void polinomy::setMonomy(float num,string var)
{
    monomy j;
    j.get(num,var);

    alg.push_back(j);
    oper();
}

polinomy &polinomy::operator=(const polinomy &a)
{
    alg=a.alg;
    return *this;
}

polinomy polinomy::operator*(const polinomy &a)
{
    polinomy z;

    for(int i=0;i<alg.size();i++)
    {

        for(int j=0;j<a.alg.size();j++)
        {
            monomy m;
            m=alg[i]*a.alg[j];
            z.alg.push_back(m);
        }
    }
    z.oper();
    return z;
}

polinomy polinomy::operator/(const polinomy &a)
{
    polinomy z;

    for(int i=0;i<alg.size();i++)
    {

        for(int j=0;j<a.alg.size();j++)
        {
            monomy m;
            m=alg[i]/a.alg[j];
            z.alg.push_back(m);
        }
    }
    z.oper();
    return z;
}



polinomy polinomy::operator+(const polinomy &a)
{
    polinomy z;
    for(int i=0;i<alg.size();i++)
    {
        z.alg.push_back(alg[i]);
    }
    for(int i=0;i<a.alg.size();i++)
    {
        z.alg.push_back(a.alg[i]);
    }

    z.oper();
    return z;
}

polinomy polinomy::operator-(const polinomy &a)
{
    polinomy z;
    for(int i=0;i<alg.size();i++)
    {
        z.alg.push_back(alg[i]);
    }
    for(int i=0;i<a.alg.size();i++)
    {

            monomy x;
            x.num=a.alg[i].num*(-1);
            x.exp=a.alg[i].exp;
            x.lit=a.alg[i].lit;
            z.alg.push_back(x);
    }

    z.oper();
    return z;
}

void polinomy::eraseMonomy(monomy &a)
{

    for(int i=0;i<alg.size();i++)
    {
        if(a==alg[i])
        {
            alg.erase(alg.begin()+i);
        }
    }
}

polinomy polinomy::infunc(string a) const
{
    polinomy f;
    for(int i=0;i<alg.size();i++)
        f.alg.push_back(alg[i].infunc(a));
    f.oper();
    return f;

}


