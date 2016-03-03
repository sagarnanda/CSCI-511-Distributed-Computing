#include "StreamSource.h"
#include <iostream>

StreamSource :: StreamSource(string oldStringP, string newStringP, string fileNameP)
{
   fileName = fileNameP;
   oldStr = oldStringP;
   newStr = newStringP;
   matchSize = 0;
   oldStringLength = -1;
   prevmatchSize =0;
   eofr = false;
   stream.open(fileName.c_str() , std::ios::out|std::ios::in );

   if(newStr.length() == oldStr.length() )
   {
      oldAndNewStrCmp = 0;
   }
   else if(newStr.length() < oldStr.length())
   {
      oldAndNewStrCmp = 1;
   }
   else
   {
      oldAndNewStrCmp = 2;
   }
   subStr = true;
   int i =0;
   //Code to check if old string is recursion of new string
   while(i < newStr.length())
   {
      int counter = oldStr.length();
      int j =0;
      while(counter > 0 && subStr)
      {
         if(oldStr[j] == newStr[i])
         {
            j++;
            i++;
            counter--;
         }
         else
         {
            subStr = false;
            break;
         }
      }
      i++;
   }
}

char StreamSource :: get(char &readC)
{
    /*
    if(partiallyMatched > 0)
    {
        readC = oldStr[partiallyMatched + counter++];
    }
    */
   if(--oldStringLength > 0)
   {
      //readC = oldStr[partiallyMatched + counter];
      readC = oldStr[prevmatchSize - oldStringLength];
   }
   else if(mydeque.size() > 0 && oldAndNewStrCmp != 2)
   {
      readC = mydeque.front();
      mydeque.pop_front();
   }
   else
   {
      if(mydeque.size() > 685)
      {
         readC = mydeque.front();
         mydeque.pop_front();
         return readC;
      }
      if(!eofr)
      {
         readC = stream.getter();
      }
      else
      {
         readC = EOF;
      }
      if(stream.eof() && !eofr) // 1st time we are setting eof
      {
         eofr = true;
         stream.clear();
         readC = EOF;
      }
      //take from deque
      else if(mydeque.size() > 0)
      {
         char ch = readC;
         readC = mydeque.front();
         mydeque.pop_front();
         mydeque.push_back(ch);
      }
   }
   return readC;
}
void StreamSource :: readAndReplace()
{
   char readC;
   while(get(readC) != EOF)
   {
      //if (compare_character(readC) == true && oldStringLength <= 0)
      if (compare_character(readC) == true)
      {
         matchSize++;
         continue;
      }
      //Partial Match
      if(matchSize > 0 && matchSize < oldStr.length() )
      {
         partiallyMatched(readC);
         char temp = mydeque.front();
         //int pos = stream.w_ptr;
         if(temp == readC)
         {
            oldStringLength = matchSize;
            prevmatchSize = matchSize;
         }
         matchSize =0;
      }
      //No Match
      else if(matchSize==0)
      {
         nothingMatched(readC);
      }
      //Complete Match
      else
      {
         completeMatched(readC);
         prevmatchSize = matchSize;
         matchSize =0;
      }
   }
   //Wash out elements from deque
   getAllCharFromDeque();
   stream.flush();
}

void StreamSource :: getAllCharFromDeque()
{
   stream.clear();
   char readC;
   bool readChar = true;
   //cout << "before draining " << mydeque.max_size << endl;
   while(mydeque.size() > 0)
   {
      if(readChar)
      {
        readC = mydeque.front();
        mydeque.pop_front();
      }
      if (compare_character(readC) == true)
      {
         matchSize++;
         continue;
      }
      if(matchSize==0)
      {
         nothingMatched(readC);
      }
      else if(matchSize > 0 && matchSize < oldStr.length())
      {
         //write all the characters till matchSize from oldString
         for(int i = 0; i < matchSize; i++)
         {
            stream.setter(oldStr[i]);
         }
         matchSize =0;
      }
      //Complete Match
      else
      {
         if(subStr)
         {
            for(int i =0 ; i < newStr.length() ; i++)
            {
               stream.setter(newStr[i]);
            }
            stream.setter(readC);
         }
         else
         {
               if(oldAndNewStrCmp == 2)
               {
                  int i=0;
                  for(i =0 ; i < newStr.length(); i++)
                  {
                     stream.setter(newStr[i]);
                  }
                  mydeque.push_front(readC);
                  
               }
               else
               {
                  for(int i =0; i < newStr.length(); i++)
                  {
                     stream.setter(newStr[i]);
                  }
                  stream.setter(readC);
               }
               //completeMatched(readC);
         }
         matchSize =0;
      }
   }

   if(matchSize > 0)
   {
      if(matchSize < oldStr.length()) //Partial Match
      {
         for(int i=0; i < matchSize; i++)
         {
            stream.setter(oldStr[i]);
         }
      }
      else if(matchSize == oldStr.length())
      {
         for(int i = 0; i < newStr.length(); i++)
         {
            stream.setter(newStr[i]);
         }
      }
   }
}

bool StreamSource :: compare_character(char &readC)
{
   if(oldStr[matchSize] == readC)
   {
      return true;
   }
   else
      return false;
}

void StreamSource :: nothingMatched(char readC)
{
   stream.setter(readC);
}

void StreamSource :: partiallyMatched(char readC)
{
   stream.setter(oldStr[0]);
   if(oldStringLength  < 0)
   {
    mydeque.push_back(readC);
   }
}

void StreamSource :: completeMatched(char readC)
{
   
   if(oldAndNewStrCmp == 2)
   {
      int i=0;
      for(i =0 ; i < matchSize; i++)
      {
         stream.setter(newStr[i]);
      }
      mydeque.push_front(readC);
      
      for( int j = newStr.length() -1 ; j >= i ; j--)
      {
         mydeque.push_front(newStr[j]);
      }
   }
   else
   {
      for(int i =0; i < newStr.length(); i++)
      {
         stream.setter(newStr[i]);
      }
      stream.setter(readC);
   }
}

StreamSource :: ~StreamSource()
{
   stream.close();
   truncate(fileName.c_str(),stream.w_ptr());
}
