CPP  = g++ -std=c++11
RES  =
OBJ  = plagiarismCatcher.o fileRead.o getDirectory.o $(RES)
LINKOBJ  = plagiarismCatcher.o fileRead.o getDirectory.o $(RES)
BIN  = cheaters
CXXFLAGS = $(CXXINCS)
CFLAGS = $(INCS)
RM = rm -f


all: cheaters

clean:
	${RM} $(OBJ) $(BIN)

$(BIN): $(OBJ)
	$(CPP) $(LINKOBJ) -o cheaters $(LIBS)

plagiarismCatcher.o: card.cpp
	$(CPP) -c plagiarismCatcher.cpp -o plagiarismCatcher.o $(CXXFLAGS)

fileRead.o: deck.cpp
	$(CPP) -c fileRead.cpp -o fileRead.o $(CXXFLAGS)

getDirectory.o: player.cpp
	$(CPP) -c getDirectory.cpp -o getDirectory.o $(CXXFLAGS)