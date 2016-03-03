#ifndef StampBuffer_H
#define StampBuffer_H

#include<iostream>
#include"stamp.h"

using namespace std;

class stampbuf:public streambuf
{
    public:
        stampbuf(int c, int r);
        virtual int sync();
        virtual int overflow(int i);
        virtual ~stampbuf();
        void incrow()
        { 
            curr_row++;
        }
        void setColumn(int c)
        {
            curr_col = c;
        }
        void setRow(int r)
        {
            curr_row = r;
        }
    private:
        int max_row;
        int max_col;
        int curr_row;
        int curr_col;
        char* buffer;
};
#endif
