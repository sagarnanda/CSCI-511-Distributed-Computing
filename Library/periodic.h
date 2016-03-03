#ifndef periodic_H
#define periodic_H

#include<string>
#include"media.h"

using namespace std;
class Periodic : public Media
{
    public:
        Periodic (string call_no,string title, string subjects,string author,string description,string publisher, string publishing_history, string series, string notes, string related_titles, string other_forms_of_title,string govt_doc_no);
        bool comp_other(const string& str) const;
        void display() const;
    private:
        string m_author;
        string m_description;
        string m_publisher;
        string m_publishing_history;
        string m_series;
        string m_related_titles;
        string m_other_forms_of_title;
        string m_govt_doc_no;
};

#endif
