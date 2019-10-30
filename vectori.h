#ifndef VECTORI_H
#define VECTORI_H
#include <iostream>
using namespace std;

class vectori{
    private:
        int n;
        double* v;
    public:
        vectori(int,double);
        void afisare();
        vectori();
        vectori(const vectori&);

            /*void schimbaN(int valoareNoua);  //setter pt n
            int aduN(); //getter pt n
            void schimbaV(double valoareNoua, int pozitie); //setter pt v
            double* aduV(); //getter pt v*/

//    vectori(const vectori);
        friend int main();
        friend int length(vectori);
        //vectori operator+(const vectori&);
        vectori operator=(vectori);
        double& operator[](int i);

        friend void operator++(vectori&);
        vectori vectorul_x(double x, int lungime);

        double* reinitializare(int num, double x);


        friend const vectori operator+ (const vectori& A,const vectori& B);
        friend const vectori operator- (const vectori& A, const vectori& B);
        friend const vectori operator- (const vectori& A);
        friend const vectori operator==(const vectori& A, const vectori& B);
        friend const vectori operator*(const vectori& A, const vectori& B);
        friend const vectori operator*(const vectori& A);
        friend const int operator!(const vectori& A);

        friend void operator+=(vectori &A, vectori &B);
        friend void operator-=(vectori &A, vectori &B);

        friend bool operator==(vectori A,vectori B);
        friend bool operator!=(vectori A,vectori B);
        friend bool operator<(vectori A,vectori B);
        friend bool operator>(vectori A,vectori B);
        friend bool operator<=(vectori A,vectori B);
        friend bool operator>=(vectori A,vectori B);

        friend bool operator==(vectori A,double x);
        friend bool operator!=(vectori A,double x);
        friend bool operator<(vectori A,double x);
        friend bool operator>(vectori A,double x);
        friend bool operator<=(vectori A,double x);
        friend bool operator>=(vectori A,double x);

        friend bool operator==(double x, vectori A);
        friend bool operator!=(double x, vectori A);
        friend bool operator<(double x, vectori A);
        friend bool operator>(double x, vectori A);
        friend bool operator<=(double x, vectori A);
        friend bool operator>=(double x, vectori A);

    void schimbaN(int valoareNoua)  //setter pt n
    {
        n = valoareNoua;
    }
    int aduN() //getter pt n
    {
        return n;
    }

    void schimbaV(double valoareNoua, int pozitie) //setter pt v
      {
			v[pozitie] = valoareNoua;
      }

    double* aduV() //getter pt v
    {
        return v;
    }




};

#endif // VECTORI_H
