#ifndef video_H
#define video_H

#include<string>
#include "media.h"
using namespace std;
class Video : public Media
{
    public:
        Video(string call_no, string title, string subjects,string description,string distributor,string notes,string series,string label);
        bool comp_other(const string& str) const;
        void display() const;
    private:
        string m_description;
        string m_distributor;
        string m_series;
        string m_label;
};
#endif
