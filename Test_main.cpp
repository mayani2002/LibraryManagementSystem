#include <iostream>
#include <windows.h>
#include <iomanip>
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

void createTable(MYSQL* conn, string tableName)
{
    unsigned int padding = 40;
    stringstream ssobj;
    ssobj << "CREATE TABLE "+ tableName +"(user_name VARCHAR(20), email VARCHAR(40), password VARCHAR(40) )";
    string query = ssobj.str();
    const char* q = query.c_str();
    int query_state = mysql_query(conn, q);
    if(query_state==0)
    {
        cout<< setw(padding)<<"table created successfully !!!"<<endl;
    }
    else
    {
        cout<<"table not created !!"<<endl;
    }
}

void insertion(MYSQL* conn,string tableName)
{
    int q_state=0;
    stringstream ss;
    string user_name, email, password ;

    cout<<"Enter the user name"<<endl;
    cin>>user_name;
    cout<<"Enter the email"<<endl;
    cin>>email;
    cout<<"Enter the password"<<endl;
    cin>>password;
    ss << "INSERT INTO " + tableName + "(user_name, email, password) VALUES ('"+user_name+"', '"+email+"', '"+password+"')";
    string query = ss.str();
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
}

void display(MYSQL* conn,string tableName)
{
    MYSQL_ROW row;
    MYSQL_RES* res;
    if(conn){
        cout<<endl<<endl;
        stringstream ss;
        ss <<"SELECT * FROM "+tableName+"";
        string query = ss.str();
        const char* q = query.c_str();
        int query_state = mysql_query(conn,q);
        if(!query_state){
            res = mysql_store_result(conn);
            int count = mysql_num_fields(res);

            while(row = mysql_fetch_row(res)){
                for(int i=0; i<count;i++)
                    cout<<"\t"<<row[i]<<"\t";
                cout<<endl;
            }
        }
    }
    else
    {
        cout<<"Error occurred"<<endl;
    }
}

int main()
{
     MYSQL* conn = connectdatabase();
     string tableName;
     cout<<"enter Table Name :";
     cin >> tableName;
     createTable(conn,tableName);

     while(1){
     int n=0;
     cout<<"SELECT \n 1.INSERT \n 2.DISPLAY"<<endl<<endl;
     cin>>n;
         switch (n)
         {
             case 1: insertion(conn,tableName);
                     break;
             case 2: display(conn,tableName);
                     break;
         }
     cout<<endl<<endl;
     }
     return 0;
}
