#include<iostream>
#include<time.h>
#include<math.h>
#include<stdlib.h>
#include<vector>

using namespace std;

typedef long long int moj_typ;
typedef long double typ;

typ fpow(typ a, typ b);
typ norm(vector<typ> a);
typ scalarP(vector<typ> a, vector<typ> b);
vector<typ> addV(vector<typ> a, vector<typ> b);
vector<typ> subV(vector<typ> a, vector<typ> b);
vector<typ> multV(vector<typ> a, typ b);
void printV(vector<typ> a, string msg);
void printM(vector<vector<typ> > a, string msg);
vector<vector<typ> > GL(vector<vector<typ> > v);
vector<vector<typ> > fill(int n);


int main()
{
    vector< vector<typ> > w;
    int n=2;
    w=fill(n);
    printM(w, "input");
    w=GL(w);
	printM(w,"result");
    return 0;
}

typ fpow(moj_typ a, moj_typ b)
{
    if(b==0)
        return 1;
    if(b%2==1)
        return a*fpow(a,b-1);
    else
    {
        typ x=fpow(a,b/2);
        return x*x;
    }
}
typ norm(vector<typ> a)
{
    typ w=0;
    for(int i=0;i<a.size();i++)
    {
        w=w+(a[i]*a[i]);
    }
    return w;
}
typ scalarP(vector<typ> a, vector<typ> b)
{
    typ w=0;
    for(int i=0;i<a.size();i++)
    {
        w=w+(a[i]*b[i]);
    }
    return w;
}
vector<typ> addV(vector<typ> a, vector<typ> b)
{
    vector<typ> c;
    for(int i=0;i<a.size();i++)
    {
        c.push_back(a[i]+b[i]);
    }
    return c;
}
vector<typ> subV(vector<typ> a, vector<typ> b)
{
    vector<typ> c;
    for(int i=0;i<a.size();i++)
    {
        c.push_back(a[i]-b[i]);
    }
    return c;
}
vector<typ> multV(vector<typ> a, typ b)
{
    vector<typ> c;
    for(int i=0;i<a.size();i++)
    {
        c.push_back(a[i]*b);
    }
    return c;
}
void printV(vector<typ> a,string msg)
{
    cout<<msg<<":\n";
    for(int i=0;i<a.size();i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void printM(vector<vector<typ> > a, string msg)
{
    cout<<msg<<":\n";
    for(int i=0;i<a.size();i++)
    {
        for(int j=0;j<a.size();j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }

}

vector<vector<typ> > GL(vector<vector<typ> > v)
{
    while(1)
    {
        typ n1,n2,m;
        n1=norm(v[0]);
        n2=norm(v[1]);
        if(n2<n1)
        {
            swap(n1,n2);
            swap(v[0],v[1]);
        }
        m=scalarP(v[0],v[1])/n1;

        m=round(m);
        cout<<"m="<<m<<endl;
        if(m==0)
            return v;
        else
            v[1]=subV(v[1],multV(v[0],m));
    }

}

vector<vector<typ> > fill(int n)
{
	typ x;
	vector<vector<typ> >  outer;
	for(int i=0; i<n;i++)
	{
		vector<typ> inner;
		cout<<"Podaj wektor:\n";
		for(int j=0; j<n;j++)
		{
			cin>>x;
			inner.push_back(x);
		}
		outer.push_back(inner);
	}
	return outer;
}
