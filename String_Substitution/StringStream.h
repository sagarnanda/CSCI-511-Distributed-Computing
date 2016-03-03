#ifndef StringStream_H
#define StringStream_H

#include <fstream>

class StringStream : public std::fstream
{
    public:
        StringStream();
        void frwdrptr();
        void frwdwptr();
        void bkwdrptr();
        void bkwdwptr();
        char getter();
        void setter(char);
        streampos w_ptr();

   private:
        streampos rptr;     
        streampos wptr;    
};
#endif
