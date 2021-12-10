#include <iostream>
#include <regex>

using namespace std;

int initial_acc_no=1000;

void exit_function()
{
    cout<<"\t\t\t\t\t--------------------------------------------------------------------------------";
    cout<<"\n\t\t\t\t\t\t\tWe hope that you enjoyed using this management system";
    cout<<"\n\t\t\t\t\t--------------------------------------------------------------------------------";
    exit(0);
}

string uid_no_generator(string aadhar_no)
{
    string uid_no = to_string(initial_acc_no) + aadhar_no.substr(8, 4);
    initial_acc_no++;
    return uid_no;
}

string password_generator(string uid_no, string name)
{
    string password = name[0] + uid_no;
    return password;
}

bool is_email_correct(string email)
{
    const regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
    return regex_match(email,pattern);
}