#include <iostream>
#include "vectori.h"
using namespace std;

int main()
{
    //cout<<"Cu ce numar ati dori sa initializati vectorul ?";
    //int nr;
    //cin>>nr;
 /*   int x;
    cin>>x;
    cout<<endl;
    vectori A;
    A.afisare();
    cout<<endl;
    //vectori B(A);
   // B.afisare();
  // vectori B;
   //B.afisare();
   A==x;

*/


   /* vectori A(3,4);   //verificare != in cazul acesta, se poate inlocui cu alti operatori pt verificare
    vectori B(3,3);
    A.afisare();
    cout<<endl;
    B.afisare();
    cout<<endl;

    if (B!=A)
        cout<<"Hooray!";
    else cout<<":(";*/


        //double d=A[0];
    //cout<<d;


        //vectori (A);



       /* vectori A(3,4);  //opusul
        vectori C(3,0);
        C=-A;
        C.afisare();*/


        ///citirea mai multor vectori dati de noi si calcularea sumei si maximului

        vectori A;
        A.afisare();
        cout<<endl;
        vectori B;
        B.afisare();
        cout<<endl;
        vectori C;
        C.afisare();
        cout<<endl;



        double* vector_din_A = A.aduV();
        int n_din_A = A.aduN();
        double maxA = vector_din_A[0];

        double* vector_din_B = B.aduV();
        int n_din_B = B.aduN();
        double maxB = vector_din_B[0];

        double* vector_din_C = C.aduV();
        int n_din_C = C.aduN();
        double maxC = vector_din_C[0];

        double s=0;

     //   int n_din_A = A.aduN;
     //   int n_din_B = B.aduN;
      //  int n_din_C = C.aduN;

        int i;

        if (n_din_A==n_din_B && n_din_A==n_din_C){
            for (i=0; i<n_din_A; i++)
                s=s+vector_din_A[i]+vector_din_B[i]+vector_din_C[i];
        }
     //   cout<<s<<endl;
        else cout<<"Nu se poate face suma intrucat numarul elementelor este diferit in fiecare vector"<<endl;
    cout<<s<<endl;
        for (i=0; i<n_din_A; i++)
        {
            if (vector_din_A[i]>maxA)
                maxA=vector_din_A[i];
            if (vector_din_B[i]>maxB)
                maxB=vector_din_B[i];
            if (vector_din_C[i]>maxC)
                maxC=vector_din_C[i];
        }
        cout<<maxA<<" "<<maxB<<" "<<maxC<<" ";



    return 0;
}
