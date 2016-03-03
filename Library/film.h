#ifndef film_H
#define film_H

#include<string>
#include "media.h"
using namespace std;

class Film : public Media
{
    public:
        Film(string call_no, string title, string subjects,string director, string notes, string year);
        bool comp_other(const string& str) const;
        void display() const;
    private:
        string m_director;
        string m_year;
};
#endif
