#include <iostream>
#include "StreamSource.h"

int main(int argc, const char * argv[])
{
    StreamSource streamSrc(argv[1] ,  argv[2] , argv[3]);
    streamSrc.readAndReplace();
    return 0;
}
