stampingpress: test_stamp.o stamp.o stampbuf.o stampstream.o
	g++ -o stampingpress test_stamp.o stamp.o stampbuf.o stampstream.o

test_stamp.o: stampstream.h stampbuf.h row.h
	g++ -c test_stamp.cpp

stamp.o: stamp.h stamp.cpp
	g++ -c stamp.cpp

stampbuf.o: stampbuf.h stampbuf.cpp stamp.h
	g++ -c stampbuf.cpp

stampstream.o: stampstream.h stampstream.cpp stampbuf.h row.h
	g++ -c stampstream.cpp

clean:
	rm -f stampingpress test_stamp.o stamp.o stampbuf.o stampstream.o stampingpress.exe  
