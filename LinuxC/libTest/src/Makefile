VPATH = ../include 
cc=g++
prom=sum
# src=$(shell find ./ -name "*.cpp")
# include= $(shell find ./ -name "*.hpp")
obj= sum.o main.o

CFLAGS = -g -Wall

# $(prom):$(obj)
# 	$(cc) -o $(prom) $(obj)

# %.o: %.cpp $(include)
# 	$(cc) -c $< -o $@

$(prom):$(obj)
	$(cc) -o $(prom) sum.o main.o

main.o:main.cpp sum.h
	$(cc) -c main.cpp -I ../include

sum.o:sum.cpp sum.h
	$(cc) -c sum.cpp -I ../include


clean:
	rm -rf $(prom) $(obj)