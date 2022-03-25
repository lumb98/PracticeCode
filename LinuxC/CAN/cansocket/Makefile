OBJS=cansockettest.o cansocket.o
EXENAME=can

$(EXENAME):$(OBJS)
	g++ -o $(EXENAME) $(OBJS)
cansockettast.o:cansockettest.cpp cansocket.hpp cansocket.o
	g++ -c cansockettest.cpp
cansocket.o:cansocket.cpp cansocket.hpp
	g++ -c cansocket.cpp
clean:
	rm can $(OBJS)