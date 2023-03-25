#include <bits/stdc++.h>

using namespace std;

int main()
{
    int guess;
    srand(time(0));
    int a = rand()%100;
    cout << "enter your first guess "<<endl;
    cin >> guess;
    int count=1;
    while(guess != a){
        if(guess > a){
            cout<<"plz.enter a smaller no."<<endl;
            cin>>guess;
            count++;
        }
        if(guess < a){
            cout<<"plz enter a bigger no."<<endl;
            cin>>guess;
            count++;
        }
    }
    cout<<"you have guessed it right in "<<count << " no. of tries."<<endl;
    return 0;
}