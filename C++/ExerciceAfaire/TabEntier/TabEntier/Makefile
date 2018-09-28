SRC_CXX=TabEntier.cc
CXXFLAGS+=-std=c++11
OBJ=${SRC_CXX:.cxx=.o}

all: testTabEntier

testTabEntier: $(OBJ) main.o
	$(CXX) $(OBJ) main.o -o testTabEntier

%.o: %.cxx
	$(CXX) $(CXXFLAGS) -c $<

clean:
	$(RM) $(OBJ) main.o testTabEntier *~

