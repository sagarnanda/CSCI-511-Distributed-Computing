#include<string>
#include<iostream>
#include"film.h"

Film::Film(string call_no, string title, string subjects, string director, string notes, string year):Media(call_no,title,subjects,notes),m_director(director),m_year(year)
{
}

void Film::display() const
{
    Media::display();
    cout<<"Director: "<<m_director;
    cout<<"Year: "<<m_year << endl;
}
bool Film::comp_other(const string& str) const
{
    if(Media::m_notes.find(str) != string::npos ||m_director.find(str) != string::npos || m_year.find(str) != string::npos)
    {
        return true;
    }
    else
    {
        return false;
    }
}
