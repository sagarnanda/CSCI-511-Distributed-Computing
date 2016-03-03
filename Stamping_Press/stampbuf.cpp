#include "stampbuf.h"
#include"stamp.h"

using namespace stamping_press;
stampbuf :: stampbuf(int c, int r):max_row(r), max_col(c), curr_row(0), curr_col(0)
{
    buffer = new char[max_col - 1];
    setp(buffer, buffer+max_col -1 );
    insert_plate(max_col, max_row);
}

int stampbuf :: sync()
{
    for(char *c =pbase(); c != pptr(); c++)
    {
        try
        {
            set_die(*c);
        }
        catch (std::invalid_argument e)
        {
            if(get_die() != *c)
            {
                curr_col++;
                continue;
            }
        }
        try
        {
            stamp(curr_col, curr_row);
        }
        catch (...)
        {
        }
        curr_col++;
    }
    setp(buffer, buffer+max_col-1);
    return 0;
}

int stampbuf :: overflow(int i)
{
    for(char *c =pbase(); c != pptr(); c++)
    {
        try
        {
            set_die(*c);
        }
        catch (std::invalid_argument e)
        {
            if(get_die() != *c)
            {
                curr_col++;
                continue;
            }
        }
        try
        {
            stamp(curr_col, curr_row);
        }
        catch (...)
        {
        }
        curr_col++;
    }
    setp(buffer, buffer+max_col-1);
    sputc(i);
    return 0;
}


stampbuf :: ~stampbuf()
{
    sync();
    delete buffer;
    eject_plate();
}
