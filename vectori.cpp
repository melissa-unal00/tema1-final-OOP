#include "vectori.h"
using namespace std;

/*istream& operator >>(istream& in,vectori& A)  // supraincarcarea lui >>
{
    in>>A.n;
    for (int i=0; i<A.n; i++)
        in>>A.v[i];
}

ostream& operator<<(ostream& out, vectori& A) // suspraincarcarea lui <<
{
    out<<A.n;
    for (int i=0; i<A.n; i++)
        out<<A.v[i];
int length (vectori nr_elem) //friend
{
    return nr_elem.n;
}*/



double* reinitializare (int num, double x)  //metoda de reinitializare a vectorului
{
    vectori vec;
	int valoareN = vec.aduN();
	double* valoareV = vec.aduV();
    vec.schimbaN(num);
    for (int i=0; i<valoareN; i++)
		vec.schimbaV(x, i);
    return valoareV;
}

vectori::vectori(int num,double nr) //initializarea cu un numar dat
{
n=num;
v = new double[n];  //declarare globala
for (int i=0; i<n; i++)
        v[i]=nr;
}

vectori::vectori()  //constructor de initializare
{
cout<<"Introduceti numarul de elemente: ";
cin>>n;
v = new double[n];
for (int i=0;i<n;i++)
    {
     cout<<"Introduceti elementul de pe pozitia "<<i<<endl;
     cin>>v[i];
     cout<<endl;
    }
}

vectori::vectori(const vectori& original) //constructor de copiere
{
    n=original.n;
    v=original.v;
}

void vectori:: afisare() //functia de afisare
{
for (int i=0;i<n;i++)
    cout<<v[i]<<" ";
}

vectori vectori::operator=(vectori C) //supraincarcarea operatorului =
{
n=C.n;
v= new double[n];
for (int i=0;i<n;i++)
    v[i]=C.v[i];
return *this;
}

double& vectori::operator[](int i) //metoda operator []
{
return v[i];
}

void operator++(vectori& A) //adunare unara
{
for (int i=0; i<A.n; i++)
    A.v[i]=A.v[i]*2;
}


const vectori operator+ (const vectori& A, const vectori& B) //suma a doi vectori
{
    vectori s;
    s.v=new double[s.n];
    for (int i=0; i<s.n; i++)
        s.v[i]=A.v[i]+B.v[i];
    return s;
}

const vectori operator- (const vectori& A, const vectori& B) //diferenta a doi vectori
{
    vectori s;
    s.v=new double[s.n];
    for (int i=0; i<s.n; i++)
        s.v[i]=A.v[i]-B.v[i];
    return s;
}
const vectori operator- (const vectori& A) //opusul unui vector
{
    vectori aux(A.n,0);
    aux.v=new double[aux.n];
    for (int i=0; i<A.n; i++)
    {
        aux.v[i]=-A.v[i];
    }
    return aux;
}

const vectori operator*(const vectori& A, const vectori& B) //produsul a doi vectori element cu element
{
    vectori prod(A.n,0);
    prod.v=new double[prod.n];
    for (int i=0; i<A.n; i++)
    {
        prod.v[i]=A.v[i]*B.v[i];
    }
        return prod;
}
const vectori operator*(const vectori& A) //produsul unui vector cu un scalar;
{
    int scalar;
    for (int i=0; i<A.n; i++)
    {
        A.v[i]=A.v[i]*scalar;
    }
    return A;
}
void operator+=( vectori &A, vectori &B) //operatorul +=
{
    if (A.n==B.n)
    for (int i=0; i<A.n; i++)
    {
        A.v[i]=A.v[i]+B.v[i];
    }
}
void operator-=( vectori &A, vectori &B) //operatorul -=
{
    if (A.n==B.n)
    for (int i=0; i<A.n; i++)
    {
        A.v[i]=A.v[i]-B.v[i];
    }
}


const int operator!(const vectori& A)   //operatorul !
{
    int ctr=0;
    for (int i=1; i<=A.n; i++)
        if (A.v[i]==0)
            ctr++;
    if (ctr==A.n)
    return 0;
    else
    {
        return 1;
    };
}

bool operator==(vectori A,vectori B)  //== pentru vector-vector
{
if (A.n!=B.n)
    return false;
bool check=true;
for (int i=0;i<A.n;i++)
    {
    if (A.v[i]!=B.v[i])
    check=false;
    }
return check;
}

bool operator!=(vectori A,vectori B)  //!= pentru vector-vector
{
if (A.n!=B.n)
    return true;
bool check=false;
for (int i=0;i<A.n;i++)
    {
    if (A.v[i]!=B.v[i])
    check=true;
    }
return check;
}

bool operator<(vectori A,vectori B)  //< pentru vector-vector
{
if (A.n!=B.n)
    return false;
bool check=true;
for (int i=0;i<A.n;i++)
    {
    if (A.v[i]>B.v[i])
    check=false;
    }
return check;
}

bool operator>(vectori A,vectori B)  //> pentru vector-vector
{
if (A.n!=B.n)
    return false;
bool check=true;
for (int i=0;i<A.n;i++)
    {
    if (A.v[i]<B.v[i])
    check=false;
    }
return check;
}

bool operator>=(vectori A,vectori B)  //>= pentru vector=vector
{
if (A.n!=B.n)
    return false;
bool check=true;
for (int i=0;i<A.n;i++)
    {
    if (A.v[i]<B.v[i])
    check=false;
    }
return check;
}

bool operator<=(vectori A,vectori B)  //<= pentru vector-vector
{
if (A.n!=B.n)
    return false;
bool check=true;
for (int i=0;i<A.n;i++)
    {
    if (A.v[i]>B.v[i])
    check=false;
    }
return check;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

vectori vectori::vectorul_x(double x, int lungime)
{
    vectori aux;
    aux.n=lungime;
    aux.v=new double [aux.n];
    for (int i=0; i<aux.n; i++)
    {
        aux.v[i]=x;
    }
    return aux;
}
bool operator==(vectori A,double x)  //== vector-real
{
    vectori ex;
     bool check=true;
    for (int i=0;i<A.n;i++)
        {
        if (A.v[i]!=ex.vectorul_x(x,A.n))
        check=false;
        }
    return check;
}

bool operator!=(vectori A,double x)  //!= vector-real
{
    vectori ex;
    bool check=true;
    for (int i=0;i<A.n;i++)
        {
        if (A.v[i]==ex.vectorul_x(x,A.n))
        check=false;
        }
    return check;
}

bool operator<(vectori A,double x)  //< vector-real
{
    vectori ex;
    bool check=true;
    for (int i=0;i<A.n;i++)
        {
        if (A.v[i]>ex.vectorul_x(x,A.n))
        check=false;
        }
    return check;
}

bool operator>(vectori A,double x)  //> vector-real
{
    vectori ex;
    bool check=true;
    for (int i=0;i<A.n;i++)
        {
        if (A.v[i]<ex.vectorul_x(x,A.n))
        check=false;
        }
    return check;
}

bool operator<=(vectori A,double x)  //<= vector-real
{
    vectori ex;
    bool check=true;
    for (int i=0;i<A.n;i++)
        {
        if (A.v[i]>ex.vectorul_x(x,A.n))
        check=false;
        }
    return check;
}

bool operator>=(vectori A,double x)  //>= vector-real
{
    vectori ex;
    bool check=true;
    for (int i=0;i<A.n;i++)
        {
        if (A.v[i]<ex.vectorul_x(x,A.n))
        check=false;
        }
    return check;
}

bool operator==(double x, vectori A)  //== real-vector
{
    vectori ex;
    bool check=true;
    for (int i=0;i<A.n;i++)
        {
        if (ex.vectorul_x(x,A.n)!=A.v[i])
        check=false;
        }
    return check;
}

bool operator!=(double x, vectori A)  //!= real-vector
{
    vectori ex;
    bool check=true;
    for (int i=0;i<A.n;i++)
        {
        if (ex.vectorul_x(x,A.n)==A.v[i])
        check=false;
        }
    return check;
}

bool operator<(double x, vectori A)  //< real-vector
{
    vectori ex;
    bool check=true;
    for (int i=0;i<A.n;i++)
        {
        if (ex.vectorul_x(x,A.n)>A.v[i])
        check=false;
        }
    return check;
}

bool operator>(double x, vectori A)  //> real-vector
{
    vectori ex;
    bool check=true;
    for (int i=0;i<A.n;i++)
        {
        if (ex.vectorul_x(x,A.n)<A.v[i])
        check=false;
        }
    return check;
}

bool operator<=(double x, vectori A)  //<= real-vector
{
    vectori ex;
    bool check=true;
    for (int i=0;i<A.n;i++)
        {
        if (ex.vectorul_x(x,A.n)>A.v[i])
        check=false;
        }
    return check;
}

bool operator>=(double x, vectori A)  //>= real-vector
{
    vectori ex;
    bool check=true;
    for (int i=0;i<A.n;i++)
        {
        if (ex.vectorul_x(x,A.n)<A.v[i])
        check=false;
        }
    return check;
}
