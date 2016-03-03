#include"stampstream.h"

using namespace std;

stampstream::stampstream(int c, int r):columns(c),rows(r),ostream(new stampbuf(c,r))
{
}

ostream& endrow(ostream &ss)
{
    stampbuf* sb = (stampbuf*)(ss.rdbuf());
    ss.flush();
    sb->incrow();
    sb->setColumn(0);
    return ss;
}

ostream& operator<<(ostream &ss, const row &rhs)
{
    stampbuf* sb=(stampbuf*)(ss.rdbuf());
    ss.flush();
    sb->setRow(rhs.getRow());
    sb->setColumn(0);
    return ss;
}

stampstream::~stampstream()
{
    delete rdbuf();
}
