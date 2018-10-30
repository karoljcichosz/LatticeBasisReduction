#include<iostream>
#include<time.h>
#include<math.h>
#include<stdlib.h>
#include<vector>
//#include<boost/multiprecision/cpp_int.hpp>

using namespace std;
//using namespace boost::multiprecision;

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
typ max(typ a, typ b);
typ mi(vector<typ> a, vector<typ> b);
vector<vector<typ> > LLL(vector<vector<typ> > v);
vector<vector<typ> > fill(int n);

int main()
{
    vector< vector<typ> > w;
    int n;
    cout<<"Podaj rzad kraty: "<<endl;
    cin>>n; cin.ignore();
    w=fill(n);
    
//    vector<typ> tmp;
//    tmp.push_back(1);
//    tmp.push_back(0);
//    tmp.push_back(0);
//    w.push_back(tmp);
//    tmp.clear();
//    tmp.push_back(4);
//    tmp.push_back(2);
//    tmp.push_back(15);
//    w.push_back(tmp);
//    tmp.clear();
//    tmp.push_back(0);
//    tmp.push_back(0);
//    tmp.push_back(3);
//    w.push_back(tmp);
//    tmp.clear();


    printM(w, "input");
    w=LLL(w);
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

typ max(typ a, typ b)
{
    if(a>b)
        return a;
    else
        return b;
}
typ mi(vector<typ> a, vector<typ> b)
{
    typ x=scalarP(a,b)/norm(b);
    return x;
}

vector<vector<typ> > LLL(vector<vector<typ> > v)
{
    int k=1;
    int x;
    vector<typ> tmp;
    typ u, uk;
    while(k<v.size())
    {
        for(int j=k-1;j>=0;j--)
        {
            u=mi(v[k],v[j]);
            cout<<"mi="<<u<<endl;
            tmp=multV(v[j],round(u));
            v[k]=subV(v[k],tmp);
            if(j==k-1)
                uk=mi(v[k],v[j]);
        }
        typ l=norm(v[k]);
        typ r=(0.75-uk*uk)*norm(v[k-1]);
        if(l>=r)
        {
            k=k+1;
        }
        else
        {
            swap(v[k],v[k-1]);
            k=max(k-1,1);
        }

    }
    return v;
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
