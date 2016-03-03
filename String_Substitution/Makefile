CC=g++
CFLAGS=-g -c 

all: string_str

string_str: main.o StringStream.o TrackingDeque.o StreamSource.o
	$(CC) main.o StringStream.o TrackingDeque.o StreamSource.o -o a.out

main.o: main.cpp StringStream.h StreamSource.h TrackingDeque.h
	$(CC) $(CFLAGS) main.cpp

StringStream.o: StringStream.cpp
	$(CC) $(CFLAGS) StringStream.cpp

TrackingDeque.o: TrackingDeque.cpp 
	$(CC) $(CFLAGS) TrackingDeque.cpp

StreamSource.o: StreamSource.cpp StringStream.h TrackingDeque.h
	$(CC) $(CFLAGS) StreamSource.cpp

clean: 
	rm -rf *.o a.out
