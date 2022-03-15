OBJS=main.o sum.o

SumTest:$(OBJS)
	g++ -o SumTest $(OBJS)
main.o:main.cpp sum.h
	g++ -c main.cpp
sum.o:sum.cpp sum.h
	g++ -c sum.cpp
clean:
	rm SumTest $(OBJS)