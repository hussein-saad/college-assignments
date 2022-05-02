#include <bits/stdc++.h>
using namespace std;
// maximum size of class
const int St_MAX = 3;

struct student{
    int id;
    string name;
    string gender;
    double quiz1,quiz2,mid_term,final,total;

    // initialization
    student(){
        id=0;
        name ="",gender="";
        quiz1=0,quiz2=0,mid_term=0,final=0, 0;
    }

    // read student record
    void add_student_record(){
        cout<<"Enter the student id,name,gender (male or female)"
              ",score of (quiz 1, quiz 2, mid term and final)\n";
        cin>>id>>name>>gender>>quiz1>>quiz2>>mid_term>>final;
        total = quiz1+quiz2+mid_term+final;
    }

    // print student record
    void print_student_record(){

        cout<<"Student name: "<<name<<"\nid: "<<id<<" \ngender: "
            <<gender<<"\nquiz 1: "<<quiz1<<"\nquiz 2:  "<<quiz2
                <<"\nmid term: "<<mid_term<<"\nfinal: "<<final<<"\ntotal score: "<<total<<"\n";
    }



};

struct system{
    // creat array of student struct
    student st[St_MAX];

    // read all students
    void read_records(){
        for (int i = 0; i < St_MAX; i++){
            cout<<"STUDENT "<<i+1<<"\n";
            cout<<"-----------------------\n";
            st[i].add_student_record();
        }
    }

    // print all students records
    void print_records(){
        for (int i = 0; i < St_MAX; i++){
            cout<<"STUDENT "<<i+1<<"\n";
            cout<<"-----------------------\n";
            st[i].print_student_record();
        }
    }

    // get student by id
    void find_student_by_id(){
        int id;
        cout<<"Enter the student id to search\n";
        cin>>id;
        bool flag = false;
        for (int i = 0; i < St_MAX; i++){
            if (st[i].id == id){
                cout<<"STUDENT "<<i+1<<"\n";
                cout<<"-----------------------\n";
                st[i].print_student_record();
                flag  = true;
                break;
            }
        }
        // prompt the user if student not found
        if (!flag) cout<<"No student found\n";
    }


    // sort students by their scores
    void sort_student_by_score(){

        for (int i = 0; i < St_MAX; i++){
            double mn = st[i].total;
            for (int j = i+1; j < St_MAX; j++){
                if (st[j].total < mn){
                    mn = st[j].total;
                    swap(st[i],st[j]);
                }
            }
        }
    }

    // get student with minimum total score
    void get_min_score(){
        sort_student_by_score();
        cout<<"Student with minimum score\n";
        st[0].print_student_record();
        cout<<"-------------------------------\n";
    }

    // get student with maximum total score
    void get_max_score(){
        sort_student_by_score();
        cout<<"Student with maximum score\n";
        st[St_MAX-1].print_student_record();
        cout<<"-------------------------------\n";
    }
};

int main(){
    struct system s;
    s.read_records();
    s.get_min_score();
    s.get_max_score();
    return 0;
}