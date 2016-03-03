lib_prj: Media.o Book.o Film.o Periodic.o Video.o SearchEngine.o lib_prj.o 
	g++ Media.o Book.o Film.o Periodic.o Video.o SearchEngine.o lib_prj.o -o lib_prj

lib_prj.o: lib_prj.cpp Media.h SearchEngine.h
	g++ -c -g lib_prj.cpp

Media.o: Media.cpp Media.h
	g++ -c  -g Media.cpp

Book.o: Book.cpp Book.h
	g++ -c  -g Book.cpp

Film.o: Film.cpp Film.h
	g++ -c  -g Film.cpp

Periodic.o: Periodic.cpp Periodic.h
	g++ -c  -g Periodic.cpp

Video.o: Video.cpp Video.h
	g++ -c  -g Video.cpp

SearchEngine.o: SearchEngine.cpp Media.h
	g++ -c -g SearchEngine.cpp
clean:
	rm -f lib_prj lib_prj.exe lib_prj.o Media.o Book.o Film.o Periodic.o Video.o SearchEngine.o