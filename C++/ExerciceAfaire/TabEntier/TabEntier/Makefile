SRC_CXX=TabGeneric.cc
CXXFLAGS+=-std=c++11
OBJ=${SRC_CXX:.cc=.o}

all: testTabGeneric

testTabGeneric: $(OBJ) main.o
	$(CXX) $(OBJ) main.o -o testTabGeneric

%.o: %.cxx
	$(CXX) $(CXXFLAGS) -c $<

clean:
	$(RM) $(OBJ) main.o testTabGeneric *~

