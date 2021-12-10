#include <iostream>
#include <cstring>
#include <iomanip>
#include <windows.h>
#include <mysql.h>
#include <sstream>
#include<string> 

using namespace std;

const char* hostname ="localhost";
const char* username ="root";
const char* password ="";
const char* database ="test";
unsigned int port = 3306;
const char* unixsocket = NULL;
unsigned long clientflag = 0;

MYSQL* connectdatabase(){
    MYSQL* conn;
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, hostname, username, password, database, port, unixsocket, clientflag);
    if(conn)
    {
        cout<<"connected to server"<<endl;
    }
    else
    {
        cout<<"failed to connect to server"<<endl;
    }
    return conn;
}

int initial_acc_no=1000;
unsigned int padding = 120;

void exit_function()
{
    cout<<setw(padding) <<"--------------------------------------------------------------------------------\n";
    cout<<setw(padding+10)<<"We hope that you enjoyed using this management system\n";
    cout<<setw(padding) <<"--------------------------------------------------------------------------------";
    exit(0);
}

string uid_no_generator(long long int aadhar_no)
{
    string aadhar_no_str = to_string(aadhar_no);
    string uid_no = to_string(initial_acc_no) + aadhar_no_str.substr(8, 4);
    initial_acc_no++;
    return uid_no;
}

string password_generator(string uid_no, string name)
{
    string password = name[0] + uid_no;
    return password;
}

class Member
{
    public:
        string name,email,uid_no,password;
        long long int aadhar_no;
};

class Member_College_Student:public Member
{
    public:
        string college_name,branch;
        int year_of_graduation;
    
    void get_member_details()
    {
        cout<<"\n\n"<<setw(padding)<<"--------------------------------------------------------------------------------";
        cout<<"\n"<<setw(padding-10)<<"                            Hello College Student";
        cout<<"\n"  <<setw(padding)<<"--------------------------------------------------------------------------------";
        cout<<"\n"<<setw(padding)<<"Please enter the following details:";
        // To be added in a file
        cout<<"\n\n\t\t\t\t\tName: ";
        cin.ignore();
        getline(cin, name);
        cout<<"\t\t\t\t\tE-Mail: ";
        getline(cin, email);
        cout<<"\t\t\t\t\tAadhar Number: ";
        cin >> aadhar_no;
        if ( aadhar_no/1000000000000.0 >=0.1 && aadhar_no/1000000000000.0<2)
        {
            cin.ignore();
            cout<<"\t\t\t\t\tCollege Name: ";
            getline(cin, college_name);
            cout<<"\t\t\t\t\tBranch: ";
            getline(cin, branch);
            cout<<"\t\t\t\t\tYear of Graduation: ";
            cin>>year_of_graduation;
            getchar();
            if (year_of_graduation / 10000 == 0 && year_of_graduation > 2021 && year_of_graduation < 2027)
            {
                uid_no = uid_no_generator(aadhar_no);
                password = password_generator(uid_no, name);
                cout<<"\n\t\t\t\t\tYou are now a member of our library !";
                cout<<"\n\t\t\t\t\tPlease remember the following details because you will require them for login !";
                cout<<"\n\t\t\t\t\tUID Number: "<<uid_no;
                cout<<"\n\t\t\t\t\tPassword: "<<password;
                cout<<"\n\t\t\t\t\tYou can reset your password in profile settings.";
                cout<<"\n\t\t\t\t\t--------------------------------------------------------------------------------";
                cout<<"\n\t\t\t\t\t\t\t\tWe hope that you enjoy this program";
                cout<<"\n\t\t\t\t\t--------------------------------------------------------------------------------";
                getchar();
            }
            else
            {
                if (year_of_graduation / 10000 != 0)
                    cout<<"\n\t\t\t\t\tGraduation Year is a 4 digit number !";
                else
                    cout<<"\n\t\t\t\t\tIf you are a student, then how can your\ngraduation year be before 2021 or after 2026 ?";
                cout<<"\n\t\t\t\t\t--------------------------------------------------------------------------------";
                cout<<"\n\t\t\t\t\t\t\t     Please enter all the details carefully";
                cout<<"\n\t\t\t\t\t--------------------------------------------------------------------------------";
                get_member_details();
            }
        }
        else 
        {
            cout<<"\n\t\t\t\t\tAadhard Card Number is a 12-digit number !";
            cout<<"\n\t\t\t\t\t--------------------------------------------------------------------------------";
            cout<<"\n\t\t\t\t\t\t\t     Please enter all the details carefully";
            cout<<"\n\t\t\t\t\t--------------------------------------------------------------------------------";
            get_member_details();
        }
    }
};

class Member_School_Student:public Member
{
    public:
        string school_name,grade;
    
    void get_member_details()
    {
        
    }
};

class Other_Members:public Member
{
    public:
        string profession;

    void get_member_details()
    {
        
    }
};

class Employee
{
    public:
};

void college_student()
{
    Member_College_Student new_member; 
    new_member.get_member_details();
}

void school_student()
{
    Member_School_Student new_member; 
}

void other_members()
{
    Other_Members new_member; 
}

void student_type()
{
    int choice;
    cout<<"\n\n\t\t\t\t\t--------------------------------------------------------------------------------";
    cout<<"\n\t\t\t\t\t\t\t\t\tNew Registration";
    cout<<"\n\t\t\t\t\t--------------------------------------------------------------------------------";
    cout<<"\n\n\t\t\t\t\tYou are a: ";
    cout<<"\n\t\t\t\t\t1. College Student";
    cout<<"\n\t\t\t\t\t2. School Student";
    cout<<"\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t0. Exit";
    cout<<"\n\t\t\t\t\tEnter your choice: ";
    cin>>choice;
    switch (choice)
    {
        case 1:
            cout<<"\n\t\t\t\t\t--------------------------------------------------------------------------------";
            cout<<"\n\t\t\t\t\t\t\t\tWe hope that you enjoy this program";
            cout<<"\n\t\t\t\t\t--------------------------------------------------------------------------------";
            college_student();
            break;
        case 2:
            cout<<"\n\t\t\t\t\t--------------------------------------------------------------------------------";
            cout<<"\n\t\t\t\t\t\t\t\tWe hope that you enjoy this program";
            cout<<"\n\t\t\t\t\t--------------------------------------------------------------------------------";
            school_student();
            break;
        case 0:
            exit_function();
            break;
        default:
            cout<<"\n\t\t\t\t\t--------------------------------------------------------------------------------";
            cout<<"\n\t\t\t\t\t\t\t\t\tInvalid Choice";
            cout<<"\n\t\t\t\t\t--------------------------------------------------------------------------------";
            student_type();
            break;
    }
}

void other_professions()
{

}

void new_registration() 
{
    int choice;
    cout<<"\n\n\t\t\t\t\t--------------------------------------------------------------------------------";
    cout<<"\n\t\t\t\t\t\t\t\t\tNew Registration";
    cout<<"\n\t\t\t\t\t--------------------------------------------------------------------------------";
    cout<<"\n\n\t\t\t\t\tYou are from: ";
    cout<<"\n\t\t\t\t\t1. Students Category";
    cout<<"\n\t\t\t\t\t2. Other Professions";
    cout<<"\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t0. Exit";
    cout<<"\n\t\t\t\t\tEnter your choice: ";
    cin>>choice;
    switch (choice)
    {
        case 1:
            cout<<"\n\t\t\t\t\t--------------------------------------------------------------------------------";
            cout<<"\n\t\t\t\t\t\t\t\tWe hope that you enjoy this program";
            cout<<"\n\t\t\t\t\t--------------------------------------------------------------------------------";
            student_type();
            break;
        case 2:
            cout<<"\n\t\t\t\t\t--------------------------------------------------------------------------------";
            cout<<"\n\t\t\t\t\t\t\t\tWe hope that you enjoy this program";
            cout<<"\n\t\t\t\t\t--------------------------------------------------------------------------------";
            other_professions();
            break;
        case 0:
            exit_function();
            break;
        default:
            cout<<"\n\t\t\t\t\t--------------------------------------------------------------------------------";
            cout<<"\n\t\t\t\t\t\t\t\t\tInvalid Choice";
            cout<<"\n\t\t\t\t\t--------------------------------------------------------------------------------";
            new_registration();
            break;
    }
}

void member_login()
{

}

void librarian_login()
{

}

void main_display_menu()
{
    int choice,cf_flag_01=0;

    //===========================================================================================================//
    //                                The main display menu for the library system                               //
    //===========================================================================================================//

    cout << setfill(' ')<<setw(padding)<<"--------------------------------------------------------------------------------";
    cout<< setfill(' ') <<setw(padding-50)<<"\n\t\t\t\t\t\t\t\t\tWelcome to the Library\n";
    cout<< setfill(' ') <<setw(padding)<<"--------------------------------------------------------------------------------";
    cout<<"\n\t\t\t\t\t1. New Registration";
    cout<<"\n\t\t\t\t\t2. Member Login";
    cout<<"\n\t\t\t\t\t3. Librarian Login";
    cout<<"\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t0. Exit";
    cout<<"\n\t\t\t\t\tEnter your choice: ";
    cin>>choice;
    switch (choice)
    {
        case 1:
            cout<<"\n\t\t\t\t\t--------------------------------------------------------------------------------";
            cout<<"\n\t\t\t\t\t\t\t\tWe hope that you enjoy this program";
            cout<<"\n\t\t\t\t\t--------------------------------------------------------------------------------";
            new_registration();
            break;
        case 2:
            cout<<"\n\t\t\t\t\t--------------------------------------------------------------------------------";
            cout<<"\n\t\t\t\t\t\t\t\tWe hope that you enjoy this program";
            cout<<"\n\t\t\t\t\t--------------------------------------------------------------------------------";
            member_login();
            break;
        case 3:
            cout<<"\n\t\t\t\t\t--------------------------------------------------------------------------------";
            cout<<"\n\t\t\t\t\t\t\t\tWe hope that you enjoy this program";
            cout<<"\n\t\t\t\t\t--------------------------------------------------------------------------------";
            librarian_login();
            break;
        case 0:
            exit_function();
            break;
        default:
            cout<<"\n\t\t\t\t\t--------------------------------------------------------------------------------";
            cout<<"\n\t\t\t\t\t\t\t\t\tInvalid Choice";
            cout<<"\n\t\t\t\t\t--------------------------------------------------------------------------------\n";
            main_display_menu();
            break;   
    }
}
int main()
{
    connectdatabase();
    main_display_menu();
    return 0;
}