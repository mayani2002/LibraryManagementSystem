#include <iostream>
#include <cstring>
#include <windows.h>
#include <mysql.h>
#include <sstream>

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


bool createCollegeStudentTable(MYSQL* conn)
{
    stringstream ssobj;
    ssobj << "CREATE TABLE CollegeStudentTable("
               " uid_no INT"
               ", password VARCHAR(40)"
               ", name VARCHAR(20)"
               ", email VARCHAR(40)"
               ", aadhar_no BIGINT"
               ", college_name VARCHAR(40)"
               ", branch VARCHAR(20)"
               ", year_of_graduation INT)";

    string query = ssobj.str();
    const char* q = query.c_str();
    int query_state = mysql_query(conn, q);
    if(query_state==0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

bool createSchoolStudentTable(MYSQL* conn)
{
    stringstream ssobj;
    ssobj << "CREATE TABLE SchoolStudentTable("
             " uid_no INT,"" password VARCHAR(40),"
             " email VARCHAR(40),"
             " aadhar_no BIGINT,"
             " school_name VARCHAR(20),"
             " grade INT)";

    string query = ssobj.str();
    const char* q = query.c_str();
    int query_state = mysql_query(conn, q);
    if(query_state==0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

bool createOthersTable(MYSQL* conn)
{
    stringstream ssobj;
    ssobj << "CREATE TABLE OthersTable("
             "uid_no INT, "
             "password VARCHAR(40), "
             "email VARCHAR(40), "
             "aadhar_no BIGINT, "
             "profession INT)" ;

    string query = ssobj.str();
    const char* q = query.c_str();
    int query_state = mysql_query(conn, q);
    if(query_state==0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
