#ifndef book_H
#define book_H

#include<string>
#include "media.h"

using namespace std;
class Book : public Media
{
    public:
        Book(string call_no,string title,string subjects,string author,string description,string publisher,string city,string year,string series,string notes);
        bool comp_other(const string& str) const;
        void display() const;
    private:
        string m_author;
        string m_description;
        string m_publisher;
        string m_city;
        string m_year;
        string m_series;
};
#endif
