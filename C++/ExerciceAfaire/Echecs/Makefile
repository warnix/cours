SRC_CXX=Piece.cxx Joueur.cxx
CXXFLAGS+=-std=c++11
OBJ=${SRC_CXX:.cxx=.o}

all: testPiece

testPiece: $(OBJ) testPiece.o
	$(CXX) $(OBJ) testPiece.o -o testPiece

%.o: %.cxx
	$(CXX) $(CXXFLAGS) -c $<

clean:
	$(RM) $(OBJ) testPiece.o testPiece *~

