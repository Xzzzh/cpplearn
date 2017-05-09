INC_DIR:= 
# SRCS:=$(wildcard *.cpp)
SRCS:= TextQuery.cpp Query.cpp 
OBJS:= $(patsubst %.cpp, %.o, $(SRCS))
LIBS:= 

CXX:=g++

CXXFLAGS:= -w -g -std=c++11 $(addprefix -I, $(INC_DIR)) $(LIBS)

all:wordQueryTest.exe andQueryTest.exe and_orQueryTest.exe


wordQueryTest.exe:$(OBJS) wordQueryTest.o get_print.o
	$(CXX) -o $@ $^ $(CXXFLAGS)

andQueryTest.exe:$(OBJS) andQueryTest.o get_print.o
	$(CXX) -o $@ $^ $(CXXFLAGS)

and_orQueryTest.exe:$(OBJS) and_orQueryTest.o get_print.o
	$(CXX) -o $@ $^ $(CXXFLAGS)

clean:
	rm -rf *.exe
	rm -rf *.o
