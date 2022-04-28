VPATH = src:include:lib
cc=g++
prom=sum
src=$(shell find ./ -name "*.cpp")
include= $(shell find ./ -name "*.hpp")
lib=$(shell find ./lib/ -name "*.a")
obj= main.o

CFLAGS = -g -Wall -I include


$(prom):$(obj)	
	$(cc) -o $@  $^ 

%.o:%.cpp
	$(cc) -c $^ $(CFLAGS)
	
.PHONY : clean	
clean:
	rm -rf $(prom) $(obj)









# cc=g++
# prom=sum
# src=$(shell find ./ -name "*.cpp")
# include= $(shell find ./ -name "*.hpp")
# obj= sum.o main.o

# CFLAGS = -g -Wall

# # $(prom):$(obj)
# # 	$(cc) -o $(prom) $(obj)

# # %.o: %.cpp $(include)
# # 	$(cc) -c $< -o $@

# $(prom):$(obj)
# 	$(cc) -o $(prom) ./src/sum.o ./src/main.o

# main.o:./src/main.cpp ./include/sum.hpp
# 	$(cc) -c ./src/main.cpp

# sum.o:./src/sum.cpp sum.hpp
# 	$(cc) -c ./src/sum.cpp


# clear:
# 	rm -rf $(prom) $(obj)