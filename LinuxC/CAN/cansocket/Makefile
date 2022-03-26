OBJS=cansockettest.o cansocket.o
EXENAME=can
CFLAG=-I.

can:cansockettest.o cansocket.o
	g++ -o can cansockettest.o cansocket.o



# $(EXENAME):$(OBJS)
# 	g++ -o $(EXENAME) $(OBJS)
# cansockettast.o:cansockettest.cpp cansocket.hpp cansocket.o
# 	g++ -c cansockettest.cpp
# cansocket.o:cansocket.cpp cansocket.hpp
# 	g++ -c cansocket.cpp
clean:
	rm can $(OBJS)