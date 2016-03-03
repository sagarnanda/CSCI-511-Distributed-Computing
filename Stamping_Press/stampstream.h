#ifndef StampStream_H
#define StampStream_H

#include <ostream>
#include "stampbuf.h"
#include "row.h"

using namespace std;

ostream& operator<<(ostream &ss, const row &rhs);
ostream& endrow(ostream &ss);

class stampstream : public ostream
{
    public:
        stampstream(int c, int r);
        ~stampstream();
    private:
        int columns;
        int rows;
};
#endif
