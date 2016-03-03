#include<iostream>
#include"media.h"

Media::Media(const string& call_no, const string& title, const string& subject,const  string& notes): m_call_no(call_no),m_title (title),m_subjects (subject),m_notes (notes)
{
}

void Media:: display() const
{
    cout<<"Call_number: "<<m_call_no;
    cout<<"Title: "<<m_title;
    cout<<"Subjects: "<<m_subjects;
    cout<<"Notes: "<<m_notes;
}

bool Media::comp_call_no(const string& str) const
{
    if(m_call_no.find(str) != string::npos)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Media::comp_title(const string& str) const
{
    if(m_title.find(str) != string::npos)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Media::comp_subjects(const string& str) const
{
    if(m_subjects.find(str) != string::npos)
    {
        return true;
    }
    else
    {
        return false;
    }
}

Media :: ~Media() //Virtual Media destructor
{
}
