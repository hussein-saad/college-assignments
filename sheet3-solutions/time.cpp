#include <bits/stdc++.h>
using namespace std;

struct Time{
    int hour;
    int minute;
    int second;

    // initialize time
    Time(){
        hour = minute = second = 0;
    }

    // read time
    void read(){
        int h, m, s;
        char first_char, second_char; // for (:) character
        cin>>h>>first_char>>m>>second_char>>s;

        hour = h;
        minute = m;
        second = s;
    }

    // convert time to seconds
    int covert_to_seconds(){
        return hour*3600 + minute*60 + second;
    }

    // convert seconds to time
    void convert_back_to_time(int seconds){
        hour = (seconds/3600)%24;// when divide by 3600, I get the hour and take mod to remove cycles

        // when take the remainder of 3600 this will remove the complete cycles of hours
        // and then divide the remainder by 60 to get the minutes
        minute = (seconds%3600)/60;

        // the remainder of the minutes will be the seconds
        second = seconds%60;

    }
    // print time
    void print(){

        cout<<setfill('0')<<setw(2)<<hour<<":"<<setfill('0')<<setw(2)<<minute<<":"<<setfill('0')<<setw(2)<<second<<"\n";
    }

};

int main(){

    Time t1, t2,result;
    // read two time objects
    cout<<"Enter the first time in 00:00:00 format: ";
    t1.read();
    cout<<"Enter the second time in 00:00:00 format:: ";
    t2.read();
    // convert them to seconds and store them in result
    result.second = t1.covert_to_seconds() + t2.covert_to_seconds();
    // convert the result back to time
    result.convert_back_to_time(result.second);
    // print the result
    cout<<"The sum of the two times is: ";
    result.print();
}

// 11:50:40
// 10:40:10