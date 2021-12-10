#include <iostream>
#include <cstring>
#include <windows.h>
#include <mysql.h>
#include <sstream>
#include <iomanip>
#include "miscellaneous_functions.cpp"
#include "createdb_function.cpp"

using namespace std;


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
    
    void get_member_details(MYSQL* conn)
    {
        cout<<"\n\n\t\t\t\t\t--------------------------------------------------------------------------------";
        cout<<"\n\t\t\t\t\t\t\t\t     Hello College Student";
        cout<<"\n\t\t\t\t\t--------------------------------------------------------------------------------";
        cout<<"\n\t\t\t\t\tPlease enter the following details:";
        // To be added in a file
        cout<<"\n\n\t\t\t\t\tName: ";
        cin.ignore();
        getline(cin, name);
        cout<<"\t\t\t\t\tE-Mail: ";
        getline(cin, email);
        if (is_email_correct(email)) {
            cout<<"\t\t\t\t\tAadhar Number: ";
            cin>>aadhar_no;

            if (aadhar_no / 1000000000000.0 >= 0.1 && aadhar_no / 1000000000000 < 1)
            {
                cin.ignore();
                cout<<"\t\t\t\t\tCollege Name: ";
                getline(cin, college_name);
                cout<<"\t\t\t\t\tBranch: ";
                getline(cin, branch);
                cout<<"\t\t\t\t\tYear of Graduation: ";
                cin>>year_of_graduation;
                getchar();
                if (year_of_graduation / 10000 == 0 &&  year_of_graduation / 1000>1 && year_of_graduation > 2021 && year_of_graduation < 2027)
                {
                    int q_state=0;
                    stringstream ssobj;
                    string aadhar_no_str = to_string(aadhar_no);
                    uid_no = uid_no_generator(to_string(aadhar_no));
                    password = password_generator(uid_no, name);
                    string year_of_graduation_str = to_string(year_of_graduation);
                    ssobj << "INSERT INTO CollegeStudentTable (uid_no, password, name, email, aadhar_no, college_name, branch, year_of_graduation ) VALUES ('"+uid_no+"', '"+password+"', '"+ name +"', '"+email+"', '"+aadhar_no_str+"', '"+college_name+"', '"+branch+"', '"+ year_of_graduation_str+"')";
                    string query = ssobj.str();
                    const char* q = query.c_str();
                    int query_state = mysql_query(conn, q);
                    if(query_state==0)
                    {
                        cout<<"Record inserted !! ";
                    }
                    else
                    {
                        cout<<"Record not inserted :( ";
                    }

                    cout<<"\n\t\t\t\t\tYou are now a member of our library !";
                    cout<<"\n\t\t\t\t\tPlease remember the following details because you will require them for login !";
                    cout<<"\n\n\t\t\t\t\tUID Number: "<<uid_no;
                    cout<<"\n\t\t\t\t\tPassword: "<<password;
                    cout<<"\n\n\t\t\t\t\tYou can reset your password in profile settings.";
                    cout<<"\n\t\t\t\t\t--------------------------------------------------------------------------------";
                    cout<<"\n\t\t\t\t\t\t\t\tWe hope that you enjoy this program";
                    cout<<"\n\t\t\t\t\t--------------------------------------------------------------------------------";
                    getchar();
                }
                else
                {
                    if (year_of_graduation / 10000 != 0 || year_of_graduation / 1000<1)
                        cout<<"\n\t\t\t\t\tGraduation Year is a 4 digit number !";
                    else
                        cout<<"\n\t\t\t\t\tIf you are a student, then how can your\ngraduation year be before 2021 or after 2026 ?";
                    cout<<"\n\t\t\t\t\t--------------------------------------------------------------------------------";
                    cout<<"\n\t\t\t\t\t\t\t     Please enter all the details carefully";
                    cout<<"\n\t\t\t\t\t--------------------------------------------------------------------------------";
                    get_member_details(conn);
                }
            }
            else 
            {
                cout<<"\n\t\t\t\t\tAadhard Card Number is a 12-digit number !";
                cout<<"\n\t\t\t\t\t--------------------------------------------------------------------------------";
                cout<<"\n\t\t\t\t\t\t\t     Please enter all the details carefully";
                cout<<"\n\t\t\t\t\t--------------------------------------------------------------------------------";
                get_member_details(conn);
            }
        }
        else {
                cout<<"\n\t\t\t\t\tPlease enter a valid email id !";
                cout<<"\n\t\t\t\t\t--------------------------------------------------------------------------------";
                cout<<"\n\t\t\t\t\t\t\t     Please enter all the details carefully";
                cout<<"\n\t\t\t\t\t--------------------------------------------------------------------------------";
                get_member_details(conn);
        }
    }
};

class Member_School_Student:public Member
{
    public:
        string school_name;
        int grade;
    
    void get_member_details()
    {
        cout<<"\n\n\t\t\t\t\t--------------------------------------------------------------------------------";
        cout<<"\n\t\t\t\t\t\t\t\t     Hello School Student";
        cout<<"\n\t\t\t\t\t--------------------------------------------------------------------------------";
        cout<<"\n\t\t\t\t\tPlease enter the following details:";
        // To be added in a file
        cout<<"\n\n\t\t\t\t\tName: ";
        cin.ignore();
        getline(cin, name);
        cout<<"\t\t\t\t\tE-Mail: ";
        getline(cin, email);
        if (is_email_correct(email)) {
            cout<<"\t\t\t\t\tAadhar Number: ";
            cin>>aadhar_no;
            if (aadhar_no / 1000000000000.0 >= 0.1 && aadhar_no / 1000000000000 < 1)
            {
                cin.ignore();
                cout<<"\t\t\t\t\tSchool Name: ";
                getline(cin, school_name);
                cout<<"\t\t\t\t\tGrade: ";
                cin>>grade;
                if (grade >= 6 && grade <= 12)
                {
                    uid_no = uid_no_generator(to_string(aadhar_no));
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
                    cout<<"\n\t\t\t\t\tIf you are a school student, how can your\ngrade be less than 6 or greater than 12 ?";
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
        else{
                cout<<"\n\t\t\t\t\tPlease enter a valid email id !";
                cout<<"\n\t\t\t\t\t--------------------------------------------------------------------------------";
                cout<<"\n\t\t\t\t\t\t\t     Please enter all the details carefully";
                cout<<"\n\t\t\t\t\t--------------------------------------------------------------------------------";
                
        }
    }
};

class Other_Members:public Member
{
    public:
        string profession;

    void get_member_details()
    {
        cout<<"\n\n\t\t\t\t\t--------------------------------------------------------------------------------";
        cout<<"\n\t\t\t\t\t\t\t\t     Hello Other Member";
        cout<<"\n\t\t\t\t\t--------------------------------------------------------------------------------";
        cout<<"\n\t\t\t\t\tPlease enter the following details:";
        // To be added in a file
        cout<<"\n\n\t\t\t\t\tName: ";
        cin.ignore();
        getline(cin, name);
        cout<<"\t\t\t\t\tE-Mail: ";
        getline(cin, email);
        cout<<"\t\t\t\t\tAadhar Number: ";
        cin>>aadhar_no;
        if (is_email_correct(email)) {
            if (aadhar_no / 1000000000000.0 >= 0.1 && aadhar_no / 1000000000000 < 1) {
                cin.ignore();
                cout<<"\t\t\t\t\tProfession: ";
                getline(cin, profession);
                
                uid_no = uid_no_generator(to_string(aadhar_no));
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
            else {
                cout<<"\n\t\t\t\t\tAadhard Card Number is a 12-digit number !";
                cout<<"\n\t\t\t\t\t--------------------------------------------------------------------------------";
                cout<<"\n\t\t\t\t\t\t\t     Please enter all the details carefully";
                cout<<"\n\t\t\t\t\t--------------------------------------------------------------------------------";
                get_member_details();
            }
        }else
        {
            display_wrong_email();
        }
    }
};

void display_wrong_email()

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
    new_member.get_member_details();
}

void other_members()
{
    Other_Members new_member; 
    new_member.get_member_details();
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
            other_members();
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
    int uid_no ;
    string password ;
    cout<<"\t\t\t\t\t--------------------------------------------------------------------------------";
    cout<<"\n\t\t\t\t\t\t\t\t\tEnter your details :";
    cout<<"\n\t\t\t\t\t--------------------------------------------------------------------------------";
    cout<<"\n\t\t\t\t\tUID No.:  ";
    cin.ignore();
    cin>> uid_no;
    cout<<"\n\t\t\t\t\tPassword:";
    getline(cin, password);

}

void main_display_menu()
{
    int choice,cf_flag_01=0;

    //===========================================================================================================//
    //                                The main display menu for the library system                               //
    //===========================================================================================================//

    cout<<"\t\t\t\t\t--------------------------------------------------------------------------------";
    cout<<"\n\t\t\t\t\t\t\t\t\tWelcome to the Library";
    cout<<"\n\t\t\t\t\t--------------------------------------------------------------------------------";
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
    MYSQL* conn = connectdatabase();
    main_display_menu();
    return 0;
}