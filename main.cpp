#include<iostream>
#include <stdlib.h>
#include <string.h>
#include<fstream>
#include<ctime>
#include "conio.h"
using namespace std;


//PASSWORD FUNCTION TO CHECK PASSWORD ENTERED


int password()
{
    char ch1;
    char pas[5]="null";                //PASSWORD
    int i,a,n=3;
    while(n)
    {
        a=1;
        ch1=getch();
        cout<<"*";
        for(i=0;i<3;i++)               //CHECK PASSWORD ENTERED
        {
            if(ch1!=pas[i])
            a=0;
            ch1=getch();
            cout<<"*";
        }
        if(a==1)                        //DISPLAY MESSAGE FOR CORRECT PASSWORD
        {
            cout<<"\n\n\n\n\t\t\t\t\t\t\t       Correct Password......Press any key to continue";
            getch();
            n=0;
        }
        else
        {
            n--;                       //DISPLAY MESSAGE FOR INCORRECT PASSWORD
            cout<<"\n\n\n\n\t\t\t\t\t\t\t                Incorrect Password!!!"<<endl;
            cout<<"\t\t\t\t\t\t\t                        Retry..";
        }
    }
    return a;
}


//MESS CLASS TO DISPLAY MESS MENU , REGISTER NEW STUDENT/FACULTY , DISPLAY BILL TILL DATE


class Mess
{
    public:


    void mess_blue_registration(string s)
    {
        time_t tt;                      // Declaring variable to store return value of localtime()
        struct tm * ti;                 // Applying time()
        time (&tt);                     // Using localtime()
        ti = localtime(&tt);
        ofstream fout;  // Create Object of Ofstream
        ifstream fin;
        fin.open("mess_blue_registration.TXT");
        fout.open ("mess_blue_registration.TXT",ios::app); // Append mode
        if(fin.is_open())
        fout<< "\n"<<s<<" "<<asctime(ti); // Writing data to file
        cout<<"You have succesfully registered for Mess Blue";
        fin.close();
        fout.close(); // Closing the file
    }


    void mess_red_registration(string s)
    {
        time_t tt;                      // Declaring variable to store return value of localtime()
        struct tm * ti;                 // Applying time()
        time (&tt);                     // Using localtime()
        ti = localtime(&tt);
        ofstream fout;  // Create Object of Ofstream
        ifstream fin;
        fin.open("mess_red_registration.TXT");
        fout.open ("mess_red_registration.TXT",ios::app); // Append mode
        if(fin.is_open())
            fout<< "\n"<<s<<" "<<asctime(ti);// Writing data to file
        cout<<"You have succesfully registered for Mess Red";
        fin.close();
        fout.close(); // Closing the file
    }


    void mess_green_registration(string s)
    {
        time_t tt;                      // Declaring variable to store return value of localtime()
        struct tm * ti;                 // Applying time()
        time (&tt);                     // Using localtime()
        ti = localtime(&tt);
        ofstream fout;  // Create Object of Ofstream
        ifstream fin;
        fin.open("mess_green_registration.TXT");
        fout.open ("mess_green_registration.TXT",ios::app); // Append mode
        if(fin.is_open())
        fout<< "\n"<<s<<" "<<asctime(ti); // Writing data to file
        cout<<"Yave succesfully registered for Mess Green";
        fin.close();
        fout.close(); // Closing the file
    }



    void bill(string s)
    {
        string line;                // Create Object of Ofstream
        ifstream fin;
        fin.open("bill.TXT");
        while(getline(fin, line))
        {
            if(line.find(s) != string::npos)
            cout<<line<<endl;
        }
        fin.close();
    }




    void mess_menu_red()
    {
        string line;
        ifstream fin;
        fin.open("mess_menu_red.TXT");
        if (fin.fail())                 // check if file is opened successfully
        {
            cout << "Error Opening file ... " << endl;
            return ;        // file opening failed
        }
        while(getline(fin,line))
            cout<<line<<"\n";
        fin.close();
        return ;
    }




    void mess_menu_blue()
    {
        string line;
        ifstream fin;
        fin.open("mess_menu_blue.TXT");
        if (fin.fail())             // check if file is opened successfully
        {
            cout << "Error Opening file ... " << endl;            // check if file is opened successfully
            return ;
        }
        while(getline(fin,line))
            cout<<line<<"\n";
        fin.close();
        return ;
    }



    void mess_menu_green()
    {
        string line;
        ifstream fin;
        fin.open("mess_menu_green.TXT");
        if (fin.fail())         // check if file is opened successfully
        {
            cout << "Error Opening file ... " << endl;            // check if file is opened successfully
            return ;
        }
        while(getline(fin,line))
            cout<<line<<"\n";
        fin.close();
        return ;
    }
};                                              //END OF CLASS MESS





int main()
{
                        //CODE FOR USERNAME PASSWORD

    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
    string s;
    START:reg:
    cout<<"\t\t\t\t\t\t\t\t\tEnter Username:   ";
    cin>>s;
    string searc;
    string temp;
    int offset;
	ifstream fin;
	fin.open("student_data.TXT");
	if(fin.fail())
	{
		cout << "Input file opening failed.\n";
		exit(1);
	}
    bool isFound=0;
	if(fin.is_open())
	{
	    while(!fin.eof())
	    {
            getline(fin,temp);
            if(offset=temp.find(s,0)!=string::npos)
            {
                isFound=1;
                fin.close();
                break;
            }
        }
    }
	if(isFound==0)
    {
        cout <<endl<< "\t\t\t\t\t\t\t\t\t   Name not found!\n";
        fin.close();
        cout<<"\n"<<"\t\t\t\t\t\tPress x for Register using the entered username and other key for retry"<<endl<<endl;
        char ch;
        ch=getch();
        if(ch=='x')
        {
            ofstream fout;  // Create Object of Ofstream
            ifstream fin;
            fin.open("student_data.TXT");
            fout.open ("student_data.TXT",ios::app); // Append mode
            if(fin.is_open())
                fout<< "\n"<<s;
            fin.close();
            fout.close();
            cout<<"\n\t\t\t\t\t\t\t\t\tyou have registered"<<endl;
            goto START;
        }
        else
        goto reg;
    }
    cout<<endl<<"\t\t\t\t\t\t\t\tEnter the 4 digit security password: ";
    int a=password();
    if(a==0)
    {
        cout<<endl<<endl<<"\t\t\t\t\t\t\t       Maximum times attempted restart again!!!!!!";
        return 0;
    }


                //END OF USERNAME PASSWORD

                //MESS MANAGEMENT SYSTEM START


    int n=1;
    while(n){
    system("CLS");
    cout<<"\t\t\t\t     Welcome to Mess Management System"<<endl;
    cout<<"\t\t\t\t     ^^^^^^^ ^^ ^^^^ ^^^^^^^^^^ ^^^^^^"<<endl<<endl;
    string choice;

                //ENTER CHOICE

    cout<<"Enter your choice -"<<endl<<endl;
    cout<<"1. To Apply for Leave  "<<endl<<endl;
    cout<<"2. To Register for different mess"<<endl<<endl;
    cout<<"3. To Display Mess Menu"<<endl<<endl;
    cout<<"4. To Display Bill till date"<<endl<<endl;
    cout<<"DEFAULT MESS RED IS BEEN SELECTED."<<endl<<endl;
    cout<<"Press x to exit"<<endl<<endl;
    Mess m;
    cout<<"Enter your choice  ";
    cin>>choice;
    if(choice[0]!='x')
    {
        switch(choice[0]-'0')
        {
            case 1:ret:                 //CODE FOR APPLING LEAVE
            system("CLS");
            cout<<"\t\t\t\t     Applying for leave"<<endl;
            cout<<"\t\t\t\t     ^^^^^^^^ ^^^ ^^^^^"<<endl<<endl;
            cout<<"Enter date of Departure in the format DD/MM/YYYY"<<endl<<endl;
            char dep[11];
            cin>>dep;
            int depdate,depmonth,depyear;
            depdate=dep[0]*10+dep[1]-11*'0';
            depmonth=dep[3]*10+dep[4]-11*'0';
            depyear=dep[6]*1000+dep[7]*100+dep[8]*10+dep[9]-1111*'0';
            cout<<"Enter date of Arrival in the format DD/MM/YYYY"<<endl<<endl;
            char ari[11];
            cin>>ari;
            int aridate,arimonth,ariyear;
            aridate=ari[0]*10+ari[1]-11*'0';
            arimonth=ari[3]*10+ari[4]-11*'0';
            ariyear=ari[6]*1000+ari[7]*100+ari[8]*10+ari[9]-1111*'0';
            if(strlen(dep)!=10||strlen(ari)!=10)
            {
                    cout<<"You Entered something Wrong while entering leave date"<<endl;
                    cout<<"Enter x to exit this leave menu or any key to re-enter.";
                    char cg;
                    cg=getch();
                    if(cg=='x')
                        break;
                    else
                        goto ret;
            }

            //check weather the entered date is correct

            int ckdate_month31,ckdate_month30,ckfeb;
            ckfeb=((depmonth==2&&depdate<=28&&depdate>=0)||(depmonth==2&&depyear%4==0&&depdate==29));
            ckdate_month31=((depmonth==1||depmonth==3||depmonth==5||depmonth==7||depmonth==8||depmonth==10||depmonth==12)&&(depdate<=31&&depdate>=0));
            ckdate_month30=((depmonth==4||depmonth==6||depmonth==9||depmonth==11)&&(depdate<=30&&depdate>=0));

            int arckdate_month31,arckdate_month30,arckfeb;
            arckfeb=((arimonth==2&&aridate<=28&&aridate>=0)||(arimonth==2&&ariyear%4==0&&aridate==29));
            arckdate_month31=((arimonth==1||arimonth==3||arimonth==5||arimonth==7||arimonth==8||arimonth==10||arimonth==12)&&(aridate<=31&&aridate>=0));
            arckdate_month30=((arimonth==4||arimonth==6||arimonth==9||arimonth==11)&&(aridate<=30&&aridate>=0));
            //cout<<"test="<<ckfeb<<ckdate_month30<<ckdate_month31<<arckdate_month30<<arckdate_month31<<arckfeb;
            if((ckfeb||ckdate_month30||ckdate_month31)&&(arckdate_month30||arckdate_month31||arckfeb))
            {
                cout<<"Date of Departure for leave is "<<depdate<<"/"<<depmonth<<"/"<<depyear<<endl<<endl;
                cout<<"Date of Arrival for leave is "<<aridate<<"/"<<arimonth<<"/"<<ariyear<<endl<<endl;
                ofstream fout;  // Create Object of Ofstream
                ifstream fin;
                fin.open("leave_data.TXT");
                fout.open ("leave_data.TXT",ios::app); // Append mode
                if(fin.is_open())
                fout<< "\nusername       "<<s<<"\n"<<"departure date "<<depdate<<"/"<<depmonth<<"/"<<depyear<<"\n"<<"arrival date   "<<aridate<<"/"<<arimonth<<"/"<<ariyear<<"\n"; // Writing data to file
                cout<<"\nYour leave has been registered";
                fin.close();
                fout.close(); // Closing the file
                char stp1;
                stp1=getch();
                n--;
            }
            else{
                cout<<"You Entered something Wrong while entering leave date"<<endl;
                char stp2;
                stp2=getch();
                }
            break;



                    //CODE FOR REGISTERING DIFFERENT MESS


            case 2:system("CLS");
            cout<<"\t\t\t\t     Register for Mess"<<endl;
            cout<<"\t\t\t\t     ^^^^^^^^ ^^^ ^^^^"<<endl;
            cout<<"Enter your choice -"<<endl<<endl;
            cout<<"1. To Apply for Mess Blue  "<<endl<<endl;
            cout<<"2. To Apply for Mess Red  "<<endl<<endl;
            cout<<"3. To Apply for Mess Green  "<<endl<<endl;
            cout<<"Enter your choice ";
            char choice2;
            cin>>choice2;
            switch(choice2-'0')
            {
                case 1:m.mess_blue_registration(s);
                        break;
                case 2:m.mess_red_registration(s);
                        break;
                case 3:m.mess_green_registration(s);
                        break;
                default:cout<<"You Entered something Wrong while entering Mess choice"<<endl;
                    cout<<"Enter x to exit   ";
                    char cg3;
                    cg3=getch();
                    if(cg3=='x')
                    break;
                    else
                    goto choi3;
            }
            n--;
            break;


                        //CODE FOR DISPLAYING MESS MENU


            case 3:choi3:
            system("CLS");
            cout<<"\t\t\t\t     Display Mess Menu"<<endl;
            cout<<"\t\t\t\t     ^^^^^^^ ^^^^ ^^^^"<<endl;
            cout<<"Enter your choice -"<<endl<<endl;
            cout<<"1. Mess Blue  "<<endl<<endl;
            cout<<"2. Mess Red  "<<endl<<endl;
            cout<<"3. Mess Green  "<<endl<<endl;
            cout<<"Enter your choice ";
            char choice3;
            cin>>choice3;
            switch(choice3-'0')
            {
                case 1:m.mess_menu_blue();
                    break;
                case 2:m.mess_menu_red();
                    break;
                case 3:m.mess_menu_green();
                    break;
                default:cout<<"You Entered something Wrong while entering Mess choice"<<endl;
            }
            cout<<endl<<"Enter x to exit and any other key to display option for mess menu  ";
            char cg3;
            cg3=getch();
            if(cg3=='x')
                break;
            else
                goto choi3;


                    //CODE FOR DISPLAYING MESS BILL TILL DATE


        case 4:
            system("CLS");
            cout<<"Your bill for different mess is shown below\nNAME               MESS GREEN              MESS BLUE                    MESS RED                   TOTAL\n";
            Mess k;
            k.bill(s);
           /*
            cg3=getch();
            if(cg3=='x')
                break;
            default:
                {
                    cout<<"Wrong Input"<<endl<<"Please Choose Again";

                    continue;
                }*/
             cout<<"Press any key to EXIT.";
            char chodef;
            chodef=getch();
            }
        }
        else
            return 0;
    }
    return 0;
}
