#include <iostream>

using namespace std;

int Cities(int city, int tank, int A[], int B[]){
    int OriCap=tank;
    //int tankAfter=0;
    int countOfCities=0;
    tank=0;
    if(A[0]+tank<=OriCap){  //set initial tank from home city
       tank+=A[0];
    }
    else if(A[0]+tank>OriCap){
       tank= OriCap;
    }
    if(tank-B[0]>=0){    //remove the consumption from the tank
       tank-=B[0];
    }
    else{
        return countOfCities;
    }
    for(int i=1; i<city; i++){
         if(A[i]+tank<=OriCap){  //add the available refill to the tank
            tank+=A[i];
        }
        else if(A[i]+tank>OriCap){
            tank= OriCap;
        }
        if(tank-B[i]>=0){    //remove the consumption from the tank
            tank-=B[i];
            //tankAfter=tank;
            countOfCities+=1;
        }
        else {
            break;
        }
    }
    return countOfCities;
}

int main()
{
    int NC=0, TC=0;     //numberOfCities, tankCapacity
    cout<< "Enter the number of cities, then the tank capacity:"<<endl;
    cin>>NC>>TC;
    int FA[NC], FCBC[NC];
    cout<< "Enter the Fuel amount you can Fill each city:"<<endl;
    for(int i=0;i<NC; i++){
        cin>>FA[i];
    }
    cout<< "Enter the Fuel Consumption Between each city:"<<endl;
    for(int i=0;i<NC; i++){
        cin>>FCBC[i];
    }
    cout<<"Total Number of Cities: "<<Cities(NC,TC,FA,FCBC);
    return 0;
}
/*TESTCASE1(2)
3
3
3 1 2
2 2 2
*/
/*TESTCASE2(1)
3
2
3 3 0
2 2 2
*/
/*TESTCASE3(0)
4
90
50 40 40 10
60 40 100 150
*/
/* TESTCASE4(1)
5
100
50 60 70 80 10
50 60 100 30 150
*/
/*TESTCASE5(5)
6
140
50 100 115 40 10 20
10 60 100 50 20 10
*/
/*TESTCASE6(0)
10
210
30 70 60 120 100 200 150 80 10 180
60 100 40 200 50 70 80 27 115 110
*/


