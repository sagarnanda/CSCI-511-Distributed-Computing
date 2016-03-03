#include<iostream>
#include<vector>
#include<string>

#include"media.h"
#include"searchengine.h"

using namespace std;

void displayMenu();

int main()
{
    SearchEngine se;
    displayMenu();
    int option =0;
    cin>>option;
    vector<Media *> results;

    while (option != 5)
    {   
        switch (option)
        {
            case 1:
                {
                    string cal_no;
                    cout<<"Enter Call No. =";
                    cin.ignore();
                    getline(cin,cal_no);
                    results = se.search_by_call_no(cal_no);
                    se.display(results);
                    break;
                }
            case 2:
                {
                    string subject;
                    cout<<"Enter Subject = ";
                    cin.ignore();
                    getline(cin,subject);
                    results = se.search_by_subjects(subject);
                    se.display(results);
                    break;
                }
            case 3:
                {
                    string title;
                    cout<<"Enter Title = ";
                    cin.ignore();
                    getline(cin,title);
                    results = se.search_by_title(title);
                    se.display(results);
                    break;
                }
            case 4:
                {
                    string other;
                    cout<<"Enter Other = ";
                    cin.ignore();
                    getline(cin,other);
                    results = se.search_by_other(other);
                    se.display(results);
                    break;
                }
            default:
                {
                    cout<<"Enter Correct Option";
                    break;
                }
        }
        cout<<"\n"<<endl;
        displayMenu();
        cin>>option;
    }
    return 0;
}

void displayMenu()
{
    cout<<"**********************************************Choose Option for Search Category**********************************************"<<endl;
    cout<<"Press 1 for Search by Call Number."<<endl;
    cout<<"Press 2 for Search by Subject."<<endl;
    cout<<"Press 3 for Search by Title."<<endl;
    cout<<"Press 4 for Search by Other"<<endl;
    cout<<"Press 5 to Exit."<<endl;
}
