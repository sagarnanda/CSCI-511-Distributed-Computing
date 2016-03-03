#include<string>
#include<iostream>
#include"book.h"

Book::Book(string call_no,string title,string subjects,string author,string description,string publisher,string city,string year,string series,string notes):Media (call_no,title,subjects,notes),m_author(author), m_description(description),m_publisher (publisher),m_city (city),m_year (year),m_series (series)
{
}
void Book::display() const
{
    Media::display();
    cout<<"Author: "<<m_author;
    cout<<"Description: "<<m_description;
    cout<<"Publisher: "<<m_publisher;
    cout<<"City: "<<m_city;
    cout<<"Year: "<<m_year;
    cout<<"Series: "<<m_series<<endl;
}
bool Book::comp_other(const string& str) const
{
    if (Media::m_notes.find(str) != string::npos || m_author.find(str) != string::npos || m_description.find(str) != string::npos || m_publisher.find(str) != string::npos || m_city.find(str) != string::npos || m_year.find(str) != string::npos ||m_series.find(str) != string::npos)
    {
        return true;
    }
    else
    {
        return false;
    }
}
