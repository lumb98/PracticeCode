OBJS=cansockettest.o cansocket.o
EXENAME=can
CFLAG=-I.


$(EXENAME):$(OBJS)
	g++ -o $(EXENAME) $(OBJS)
cansockettast.o:cansockettest.cpp cansocket.hpp cansocket.o cansocket.cpp
	g++ -c cansockettest.cpp
cansocket.o:cansocket.cpp cansocket.hpp
	g++ -c cansocket.cpp
clean:
	rm can $(OBJS)