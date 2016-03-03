#include<iostream>
#include<vector>
#include<string>

#ifndef SEARCHENGINE_H
#define SEARCHENGINE_H

using namespace std;

class SearchEngine
{
    public:
        SearchEngine();
        ~SearchEngine();
        vector <Media*> search_by_call_no(const string& search_str)const;
        vector <Media*> search_by_subjects(const string& search_str) const;
        vector <Media*> search_by_title(const string& search_str) const;
        vector <Media*> search_by_other(const string& search_str) const;
        void display(const vector<Media*> results) const;
    private:
        vector<Media* > CardCatalog;
        void book();
        void periodic();
        void film();
        void video();
};
#endif
