#ifndef StreamSource_H
#define StreamSource_H

#include "TrackingDeque.h"
#include "StringStream.h"
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

class StreamSource
{
    public:
        StreamSource(string , string , string);
        ~StreamSource();
        void readAndReplace();

    private:
        StringStream stream;
        string fileName;
        string oldStr;
        string newStr;
        int matchSize;
        int prevmatchSize;
        int oldStringLength;
        int oldAndNewStrCmp;
        char get(char &readChar);
        TrackingDeque<char> mydeque;
        bool eofr;
        bool subStr;

        bool compare_character(char &readChar);
        void nothingMatched(char readChar);
        void partiallyMatched(char readChar);
        void completeMatched(char readChar);
        void getAllCharFromDeque();
};
#endif
