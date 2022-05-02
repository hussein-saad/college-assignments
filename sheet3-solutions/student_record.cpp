#include <bits/stdc++.h>
using namespace std;
// maximum size of class
const int St_MAX = 20;

struct student{
    int id;
    string name;
    string gender;
    double quiz1,quiz2,mid_term,_final,total;

    // initialization
    student(){
        id=0;
        name ="",gender="";
        quiz1=0,quiz2=0,mid_term=0,_final=0, 0;
    }

    // read student record
    void add_student_record(){
        cout<<"Enter the student id,name,gender (male or female)"
              ",score of (quiz 1, quiz 2, mid term and final)\n";
        cin>>id>>name>>gender>>quiz1>>quiz2>>mid_term>>_final;
        total = quiz1+quiz2+mid_term+_final;
    }

    // print student record
    void print_student_record(){

        cout<<"Student name: "<<name<<"\nid: "<<id<<" \ngender: "
            <<gender<<"\nquiz 1: "<<quiz1<<"\nquiz 2:  "<<quiz2
                <<"\nmid term: "<<mid_term<<"\nfinal: "<<_final<<"\ntotal score: "<<total<<"\n";
    }



};

struct student_record{
    // creat array of student struct
    student st[St_MAX];
    int size;

    student_record(){
        size=0;
    }

    // read all students
    void read_records(){

        if (size >= St_MAX){
            cout<<"Maximum number of students reached\n";
            return;
        }

        cout<<"STUDENT "<<size+1<<"\n";
        cout<<"-----------------------\n";
        st[size].add_student_record();
        size++;
    }

    // check if the record is empty
    int checker(){
        return size;
    }

    // print all students records
    void print_records(){

        if (!checker()){
            cout<<"there is no student\n";
            return;
        }

        for (int i = 0; i < size; i++){
            cout<<"STUDENT "<<i+1<<"\n";
            cout<<"-----------------------\n";
            st[i].print_student_record();
        }
    }


    // find student by id
    bool find_student_by_id(int id){

        for (int i = 0; i < size; i++){
            if (st[i].id == id){
                return true;
            }
        }
        return false;
    }

    // get student by id

    void get_student_by_id(int id){

        bool flag = false;
        for (int i = 0; i < size; i++) {
            if (st[i].id == id) {
                cout << "STUDENT " << i + 1 << "\n";
                cout << "-----------------------\n";
                st[i].print_student_record();
                flag = true;
                break;
            }
        }

        // prompt the user if student not found
        if (!flag)
            cout<<"No student found\n";

    }


    // sort students by their scores
    void sort_student_by_score(){

        for (int i = 0; i < size; i++){
            double mn = st[i].total;
            for (int j = i+1; j < size; j++){
                if (st[j].total < mn){
                    mn = st[j].total;
                    swap(st[i],st[j]);
                }
            }
        }
    }

    // get student with minimum total score
    void get_min_score(){

        if (!checker()){
            cout<<"No student found\n";
            return;
        }

        // sort students by their score in increasing order so the first has a minimum score
        sort_student_by_score();
        cout<<"Student with minimum score\n";
        st[0].print_student_record();
        cout<<"-------------------------------\n";
    }

    // get student with maximum total score
    void get_max_score(){

        if (!checker()){
            cout<<"No student found\n";
            return;
        }

        // sort students by their score in increasing order so the last has a maximum score
        sort_student_by_score();
        cout<<"Student with maximum score\n";
        if (size > 0)
            st[size-1].print_student_record();
        else st[size].print_student_record();
        cout<<"-------------------------------\n";
    }

    // select students by id
    vector<int> select_students_by_id(){
        vector<int> v; // vector to store selected students
        int len;
        // prompt user to enter the number of students to select
        cout<<"how many students you want to calculate their average score\n";
        cin>>len;

        if (len > size){
            cout<<"students are less than that\n";
            return v;
        }

        int id;
        // prompt user to enter the id of students to select
        while (len){
            cout<<"Enter the student id\n";
            cin>>id;
            if (find_student_by_id(id)) {
                v.push_back(id), len--;
            }
            // prompt the user if student not found
            else{
                cout<<"there is no students with this id, please try again \n";
            }
        }
        return v;
    }

    // calculate average score of selected students
    void calculate_average_score(){
        // get selected students
        vector<int> v = select_students_by_id();
        double sum = 0;
        int len = v.size();
        // calculate average score
        for (int i = 0; i < len; i++){
            for (int j = 0; j < St_MAX; j++){
                if (st[j].id == v[i]){
                    sum += st[j].total;
                }
            }
        }
        cout<<"Average score of selected students is "<<sum/len<<"\n";
    }

    // run the program
    void run(){
        int choice;
        //keep running the program until user wants to exit
        while (1){
            cout<<"1. Add student records\n";
            cout<<"2. View all student records\n";
            cout<<"3. Calculate an average of a selected student’s scores\n";
            cout<<"4. Show student who gets the max total score\n";
            cout<<"5. Show student who gets the min total score\n";
            cout<<"6. Find student by ID\n";
            cout<<"7. Sort records by total scores\n";
            cout<<"8. Exit\n";
            cout<<"Enter your choice: ";
            cin>>choice;
            switch (choice) {
                case 1:
                    read_records();
                    break;
                case 2:
                    print_records();
                    break;
                case 3:
                    calculate_average_score();
                    break;
                case 4:
                    get_max_score();
                    break;
                case 5:
                    get_min_score();
                    break;
                case 6:
                    int id;
                    cout<<"Enter the student id\n";
                    cin>>id;
                    get_student_by_id(id);
                    break;
                case 7:
                    sort_student_by_score();
                    break;
                case 8:
                    return;
                default:
                    cout<<"Invalid choice, try again\n";
                    break;
            }
        }
    }



};

int main(){

//    freopen("input.txt", "r", stdin);

    // create a new object
    student_record sr;
    // run the program
    sr.run();
    return 0;

}
