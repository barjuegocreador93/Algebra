#include<iostream>//Libreria principal
#include<vector>//libreria de listas
#include<stdlib.h>//libreria de system();
#include<fstream>
#include<math.h>
using namespace std;
char * _cls="clear";
class polinomy;
class monomy
{
    public:
        monomy();
        void get(float,string,float);
        void make(string tipo_num);
        void print();
        void oper();
        void der(string var);
        void integ(string var);
        bool operator ==(monomy &other);
        monomy &operator =(const monomy &other) ;
        monomy MulexpforScalar(float exp) const;
        monomy operator *(const monomy &other);
        monomy operator /(const monomy &other);

    private:
        float num;
        vector<string> lit;
        vector<float> exp;
        friend class polinomy;

};

monomy::monomy()
{

}
void monomy::get(float numer,string liter, float exps)
{
    num=numer;
    lit.push_back(liter);
    exp.push_back(exps);
    oper();
}

void monomy::make(string tipo_num)
{
    if("float"==tipo_num)
    {
        cout<<"Enter the number of your monomy: ";
        cin>>num;
    }else
    if("racional"==tipo_num)
    {
        float a,b;
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
            float aux2;
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
    if(num!=1)cout<<num;
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



 monomy monomy::MulexpforScalar(float exps)const
{
    monomy x;
    x=*this;
    x.num=pow(num,exps);
    for(int i=0;i<lit.size();i++)
    {
        x.exp[i]=x.exp[i]*exps;
    }
    return x;
}

monomy monomy::operator *(const monomy &other)
{

   monomy t;

    t.num=num*other.num;
    for(int i=0;i<lit.size();i++)
    {
        t.lit.push_back(lit[i]);
        t.exp.push_back(exp[i]);
    }
    for(int i=0;i<other.lit.size();i++)
    {
        t.lit.push_back(other.lit[i]);
        t.exp.push_back(other.exp[i]);
    }



    t.oper();

    return  t;
}
monomy monomy::operator /(const monomy &other)
{

   monomy t;
    t.num=num;
    t.exp=exp;
    t.lit=lit;
    t=t * other.MulexpforScalar(-1);

    return  t;
}


void monomy::integ(string var)
{

    for(int i=0;i<lit.size();i++)
    {
        if(var==lit[i]){
        exp[i]=exp[i]+1;
        num=num/exp[i];}
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
    if(lit.size()==other.lit.size())
    {
        for(int i=0;i<lit.size();i++)
        {
            if(lit[i]!=other.lit[i])return 0;
            if(exp[i]!=other.exp[i])return 0;
        }
        return 1;
    }
    return 0;
}

