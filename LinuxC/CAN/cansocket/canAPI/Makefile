OBJS=ybw_can.o ybw_convert.o
EXENAME=canapitest
CFLAG=-g -Wall


$(EXENAME):$(OBJS)
	g++ -o $(EXENAME) $(OBJS)

%.o:%.cpp
	g++ -c $ ^ $()

clean:
	rm $(EXENAME) $(OBJS)