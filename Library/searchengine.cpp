#include<iostream>
#include<string>
#include<vector>
#include<fstream>

#include"media.h"
#include"searchengine.h"
#include"book.h"
#include"periodic.h"
#include"video.h"
#include"film.h"

using namespace std;

SearchEngine::SearchEngine()
{
    book();
    film();
    periodic();
    video();
}
void SearchEngine::book()
{

    ifstream inf("book.txt");
    string call_no; 
    while(getline(inf,call_no,'|'))
    {
        string title,subjects,author,description,publisher,city,year,series,notes;
        getline(inf,title,'|');
        getline(inf,subjects,'|');
        getline(inf,author,'|');
        getline(inf,description,'|');
        getline(inf,publisher,'|');
        getline(inf,city,'|');
        getline(inf,year,'|');
        getline(inf,series,'|');
        getline(inf,notes);
        Book* b = new Book(call_no,title,subjects,author,description,publisher,city,year,series,notes);
        CardCatalog.push_back(b);
    }
}
void SearchEngine::periodic()
{
    ifstream inf("periodic.txt");
    string call_no;
    while(getline(inf,call_no,'|'))
    {   
        string title,subjects,author,description,publisher,publisher_history,series,notes,related_titles,other_forms_of_title,govt_doc_no;
        getline(inf,title,'|');
        getline(inf,subjects,'|');
        getline(inf,author,'|');
        getline(inf,description,'|');
        getline(inf,publisher,'|');
        getline(inf,publisher_history,'|');
        getline(inf,series,'|');
        getline(inf,notes,'|');
        getline(inf,related_titles,'|');
        getline(inf,other_forms_of_title,'|');
        getline(inf,govt_doc_no);
        Periodic* p = new Periodic (call_no,title,subjects,author,description,publisher,publisher_history,series,notes,related_titles,other_forms_of_title,govt_doc_no);
        CardCatalog.push_back(p);
    }
}
void SearchEngine::video()
{
    ifstream inf("video.txt");
    string call_no;
    while(getline(inf,call_no,'|'))
    {   
        string title,subjects,description,distributor,notes,series,label;
        getline(inf,title,'|');
        getline(inf,subjects,'|');
        getline(inf,description,'|');
        getline(inf,distributor,'|');
        getline(inf,notes,'|');
        getline(inf,series,'|');
        getline(inf,label,'|');
        Video* v = new Video(call_no,title,subjects,description,distributor,notes,series,label);
        CardCatalog.push_back(v);
    }
}
void SearchEngine::film()
{
    ifstream inf("film.txt");
    string call_no;
    while(getline(inf,call_no,'|'))
    {   
        string title,subjects,director,notes,year;
        getline(inf,title,'|');
        getline(inf,subjects,'|');
        getline(inf,director,'|');
        getline(inf,notes,'|');
        getline(inf,year,'|');
        Film* f= new Film(call_no,title,subjects,director,notes,year);
        CardCatalog.push_back(f);
    }
}
vector <Media*> SearchEngine::search_by_call_no(const string& search_str)const
{
    vector<Media *> results;
    for(int i = 0;i < CardCatalog.size();i++)
    {
        bool re;
        re = CardCatalog[i]->comp_call_no(search_str);
        if(re)
        {
            results.push_back(CardCatalog[i]);
        }
    }
    return results;
}
    
vector <Media*> SearchEngine::search_by_subjects(const string& search_str) const
{
    vector<Media *> results;
    for(int i = 0;i < CardCatalog.size();i++)
    {
        bool re;
        re = CardCatalog[i]->comp_subjects(search_str);
        if(re)
        {
            results.push_back(CardCatalog[i]);
        }
    }
    return results;
}
vector <Media*> SearchEngine::search_by_title(const string& search_str) const
{    vector<Media *> results;
    for(int i = 0;i < CardCatalog.size();i++)
    {
        bool re = CardCatalog[i]->comp_title(search_str);
        if(re)
        {
            results.push_back(CardCatalog[i]);
        }
    }
    return results;

}

vector <Media*> SearchEngine::search_by_other(const string& search_str) const
{
    vector<Media *> results;
    for(int i = 0;i < CardCatalog.size();i++)
    {
        bool re;
        re = CardCatalog[i]->comp_other(search_str);
        if(re)
        {
            results.push_back(CardCatalog[i]);
        }
    }
    return results;
}

void SearchEngine::display(const vector<Media*> results) const
{
    for(int i = 0; i<results.size(); i++) 
    {
        results[i]->display();
    }
    cout <<"Total No. of Matching Result: "<<results.size()<<endl;
}
SearchEngine::~SearchEngine()
{
    for (int i = 0; i <CardCatalog.size(); i++) //Iterate to delete dynamically allocated memory.
    {
        delete CardCatalog[i];
    }
}
