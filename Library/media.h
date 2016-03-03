#include<string>

#ifndef MEDIA_H
#define MEDIA_H

using namespace std;
class Media
{
    public:
        Media(const string& call_no,const  string& title, const string& subjects, const string& notes);
        virtual ~Media();
        virtual bool comp_call_no(const string& str) const;
        virtual bool comp_title(const string& str) const;
        virtual bool comp_subjects(const string& str) const;
        virtual bool comp_other(const string& str) const = 0;
        virtual void display() const;
    protected:
        string m_call_no;
        string m_title;
        string m_subjects;
        string m_notes;
};
#endif
