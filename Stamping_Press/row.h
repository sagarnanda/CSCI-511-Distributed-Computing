#ifndef ROW_H
#define ROW_H
class row
{
    int row_p;
    public:
    row(int rowP)
    {
        row_p = rowP;
    }
    int getRow() const
    {
        return row_p;
    }
};
#endif
