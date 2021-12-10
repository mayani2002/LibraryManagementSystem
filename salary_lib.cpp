#include<iostream>
#include<cstring>
#include<fstream> 
#include <ctime>
 using namespace std;

   class emp_salary{
   public: 	
      string uid_no, password, designation,name;
      int No_of_days_worked,salary, tax=200,HRA=5000,pf;

   void get_salary_details()
   {
      pf= salary/10;
      cout<<"\n\t\t\t\t UID No. :";
      getline(cin, uid_no);
      cout<<"\n\t\t\t\t Password :";
      getline(cin, password);
      cout<<"\n\t\t\t\t No. of days worked :";
      cin>> No_of_days_worked;
//       switch()
//     {
//       case 1: salary=40000;
//           cout<<"\tDESIGNATION : Librarian";
//           break;
//       case 2: salary=30000;
//           cout<<"\tDESIGNATION : Deputy Librarian";
//           break;
//       case 3: salary=25000;
//           cout<<"\tDESIGNATION : Assistant Librarian";
//           break;
//       case 4: salary=35000;
//           cout<<"\tDESIGNATION : Information Scientist";
//           break;
//       case 5: salary=20000;
//           cout<<"\tDESIGNATION : Professional Assistant";
//           break;
//       case 6: salary=20000;
//           cout<<"\tDESIGNATION : Library Attendant";
//           break;
//       case 7: salary=25000;
//           cout<<"\tDESIGNATION : Section Officer";
//           break;
//       case 8: salary=15000;
//           cout<<"\tDESIGNATION : Personal Assistant";
//           break;
//       case 9: salary=10000;
//           cout<<"\tDESIGNATION : Clerk";
//           break;
//  }
      time_t now = time(0);
      char* dt = ctime(&now);
      tm *ltm = localtime(&now);

      cout<<"\t\t\t\t--------------------------------------------------------------------------------------------------------\n";
      cout<<"\t\t\t\t\t\t\t\t\t NATIONAL LIBRARY  - SALARY SLIP \n";
      cout<<"\t\t\t\t--------------------------------------------------------------------------------------------------------\n";
      cout<<"\t\t\t\t--------------------------------------------------------------------------------------------------------\n";
      cout<<"\t\t\t\tDATE: "<<<<"\t\t\t\t\t\t\t\t\tTIME: "<<dt<<"\n";
      cout<<"\t\t\t\t--------------------------------------------------------------------------------------------------------\n";
      cout<<"\t\t\t\t--------------------------------------------------------------------------------------------------------\n";
      cout<<"\t\t\t\tUID NO. : "<<uid_no<<"EMPLOYEE NAME : "<<name<<"\n";
      cout<<"\t\t\t\tDESIGNATION : "<<designation<<" SALARY : Rs. "<<salary<<"\n";
      cout<<"\t\t\t\t--------------------------------------------------------------------------------------------------------\n";
      cout<<"\t\t\t\t--------------------------------------------------------------------------------------------------------\n";
      cout<<"\t\t\t\tEARNING\t\t\tAMOUNT(Rs.) \t\t\tDEDUCTIONS \t\t\t AMOUNT(Rs.) \n";
      cout<<"\t\t\t\t--------------------------------------------------------------------------------------------------------\n";
      cout<<"\t\t\t\tBASIC PAY\t\t\t"<<salary<<"\t\t\t P.F.\t\t\t"<<pf<<"\n";
      cout<<"\t\t\t\tHRA\t\t\t\t"<<HRA<<"\t\t\tPROF.TAX\t\t\t"<<tax<<"\n";
      cout<<"\t\t\t\t--------------------------------------------------------------------------------------------------------\n";
      cout<<"\t\t\t\tGROSS EARNING\t\t\t\t"<<salary+HRA<<"\t\t\t TOTAL DEDUCT.\t\t\t"<<pf+tax<<"\n";
      cout<<"\t\t\t\t--------------------------------------------------------------------------------------------------------\n";
      cout<<"\t\t\t\t--------------------------------------------------------------------------------------------------------\n";
      cout<<"\t\t\t\tNET PAY : Rs. "<<salary+HRA-pf-tax<<"\n";
      cout<<"\t\t\t\t--------------------------------------------------------------------------------------------------------\n";
      cout<<"\t\t\t\t--------------------------------------------------------------------------------------------------------\n";
      cout<<"\t\t\t\t\t\t\t\t\tYOU ARE DOING GREAT JOB !!!!   \n";
      cout<<"\t\t\t\t--------------------------------------------------------------------------------------------------------\n";
   }
};
