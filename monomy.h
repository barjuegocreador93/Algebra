#include<iostream>//Libreria principal
#include<vector>//libreria de listas
#include<stdlib.h>//libreria de system();
#include<fstream>
#include<math.h>
using namespace std;
char * _cls="cls";
double frac(double a,double b)
{
    return a/b;
}

class polinomy;
class monomy
{
    public:
        monomy();
        void get(double,string,double);
        void make(string tipo_num);
        void print();
        void der(string var);
        void integ(string var);
        bool operator ==(monomy &other);
        monomy &operator =(const monomy &other) ;
        monomy pow_(const double exp);
        monomy operator *(const monomy &other);
    private:
        void oper();
        double num;
        vector<string> lit;
        vector<double> exp;
        friend class polinomy;

};

monomy::monomy()
{

}

void monomy::get(double numer,string liter, double exps)
{
    num=numer;
    lit.push_back(liter);
    exp.push_back(exps);
    oper();
}

void monomy::make(string tipo_num)
{
    if("double"==tipo_num)
    {
        cout<<"Enter the number of your monomy: ";
        cin>>num;
    }else
    if("racional"==tipo_num)
    {
        double a,b;
        cout<<"Entrar numerador: ";
        cin>>a;
        cout<<"Entrar denominador: ";
        cin>>b;
        num=a/b;
    }

    char x='z';
    while(x !='c')
    {
        system(_cls);
        cout<<"Quiere entrar una varable?:(x = si)||(c = no)_: ";
        cin>>x;
        if(x=='x')
        {
            string aux1;
            double aux2;
            system(_cls);
            cout<<"Diga el nombre de la variable nueva: ";
            cin>>aux1;
            lit.push_back(aux1);
            system(_cls);
            cout<<"Diga el exponente de la variable "<<aux1<<": ";
            cin>>aux2;
            exp.push_back(aux2);
        }

    }

}

void monomy::print()
{
    if(num!=1||lit.size()==0)cout<<num;
    for(int i=0;i<lit.size();i++)
    {
           cout<<"["<<lit[i];
           if(exp[i]!=1)cout<<"**"<<exp[i];
           cout<<"]";
    }
}

void monomy::oper()
{
    if(lit.size()!=0)
    {
        for(int i=0;i<lit.size()-1;i++)
        {


        for(int j=i+1;j<lit.size();j++)
        {

                if(lit[i]==lit[j])
                {
                    exp[i]=exp[i]+exp[j];
                    exp.erase(exp.begin()+j);
                    lit.erase(lit.begin()+j);
                    j--;
                }
        }

        }
    }
        for(int i=0;i<lit.size();i++)
        {if(exp[i]==0)
        {
            exp.erase(exp.begin()+i);
            lit.erase(lit.begin()+i);
        }}

}



monomy &monomy::operator =(const monomy  & other)
{

    num=other.num;
    exp=other.exp;
    lit=other.lit;
    return * this;
}

void monomy::der(string var)
{

    for(int i=0;i<lit.size();i++)
    {
        if(lit[i]==var)
        {
            num=num*exp[i];
            exp[i]=exp[i]-1;
        }

    }
    if(lit.size()==0)
    {
        num=0;
    }

    oper();


}



monomy monomy::pow_(const double exps)
{
    monomy a;
    a.num=pow(num,exps);
    for(int i=0;i<lit.size();i++)
    {
        double m=exp[i]*exps;
        a.lit.push_back(lit[i]);
        a.exp.push_back(m);
    }
    return a;
}

monomy monomy::operator *(const monomy &other)
{

   monomy t;

    t.num=num*other.num;
    for(int i=0;i<other.lit.size();i++)
    {
        t.lit.push_back(other.lit[i]);
        t.exp.push_back(other.exp[i]);
    }
    for(int i=0;i<lit.size();i++)
    {
        t.lit.push_back(lit[i]);
        t.exp.push_back(exp[i]);
    }
    t.oper();
    return  t;
}

void monomy::integ(string var)
{
    for(int i=0;i<lit.size();i++)
    {
        exp[i]=exp[i]+1;
        num=num/exp[i];
    }
    if(num!=0.0&&lit.size()==0)
    {
        lit.push_back(var);
        exp.push_back(1.0);
    }
    oper();
}

bool monomy::operator ==(monomy &other)
{
    oper();
    other.oper();
    if(lit.size()==other.lit.size())
    {
        int p[lit.size()];

        for(int i=0;i<lit.size();i++)
        {
           for(int j=0;j<other.lit.size();j++)
           {
               if(lit[i]==other.lit[j])
               {
                   p[i]+=1;
               }
           }
        }
        int s=0;
        for(int i=0;i<lit.size();i++)
        {
            s+=p[i];
        }
        if(s!=lit.size())return 0;
        return 1;
    }
    return 0;
}

