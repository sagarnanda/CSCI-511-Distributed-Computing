#include "StringStream.h"
#include <iostream>

using namespace std;
StringStream :: StringStream() : rptr(0), wptr(0)
{

}

void StringStream::frwdrptr()
{
    rptr += 1;
}

void StringStream::frwdwptr()
{
    wptr += 1;
}

void StringStream::bkwdrptr()
{
    rptr -= 1;
}

void StringStream::bkwdwptr()
{
    wptr += 1;
}

streampos StringStream:: w_ptr()
{
    return wptr;
}

char StringStream :: getter()
{
    char t;
    fstream::seekg(rptr);
    fstream::get(t);
    frwdrptr();
//    cout << "Read in Char--> "<<t<<endl;
    return t;
}

void StringStream :: setter(char c)
{
    fstream::seekp(wptr);
    fstream::put(c);
    frwdwptr();
//    cout << "Write out char--> "<<c<<endl;
}
