#include<string>
#include<iostream>
#include"periodic.h"

Periodic::Periodic(string call_no,string title, string subjects,string author,string description,string publisher, string publishing_history, string series, string notes, string related_titles, string other_forms_of_title,string govt_doc_no):Media (call_no, title, subjects,notes),m_author(author),m_description (description),m_publisher(publisher),m_publishing_history(publishing_history),m_series(series),m_related_titles(related_titles),m_other_forms_of_title (other_forms_of_title),m_govt_doc_no (govt_doc_no)
{
}

void Periodic::display() const
{
    Media::display();
    cout<<"Author: "<<m_author;
    cout<<"Description: "<<m_description;
    cout<<"Publisher: "<<m_publisher;
    cout<<"Publishing History: "<<m_publishing_history;
    cout<<"Series: "<<m_series;
    cout<<"Related Titles: "<<m_related_titles;
    cout<<"Other Forms of Title: "<<m_other_forms_of_title;
    cout<<"Govt Doc Number: "<<m_govt_doc_no << endl;
}
bool Periodic::comp_other(const string& str) const
{
    if (Media::m_notes.find(str) != string::npos ||m_author.find(str) != string::npos || m_description.find(str) != string::npos || m_publisher.find(str) != string::npos || m_publishing_history.find(str) != string::npos || m_series.find(str) != string::npos || m_related_titles.find(str) != string::npos || m_other_forms_of_title.find(str) != string::npos || m_govt_doc_no.find(str) != string::npos)
    {
        return true;
    }
    else 
    {
        return false;
    }

}
