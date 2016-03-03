#include<string>
#include<iostream>
#include"video.h"

Video::Video(string call_no, string title, string subjects,string description,string distributor,string notes,string series,string label):Media(call_no,title,subjects,notes), m_description(description),m_distributor(distributor),m_series(series),m_label(label)
{
}
void Video::display() const
{
    Media::display();
    cout<<"Description: "<<m_description;
    cout<<"Distributor: "<<m_distributor;
    cout<<"Series: "<<m_series;
    cout<<"Label: "<<m_label << endl;
}
bool Video::comp_other(const string& str) const
{
    if(Media::m_notes.find(str) != string::npos ||m_description.find(str) != string::npos || m_distributor.find(str) != string::npos || m_series.find(str) != string::npos || m_label.find(str) != string::npos)
    {
        return true;
    }
    else
    {
        return false;
    }
}
