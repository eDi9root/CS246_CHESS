CXX = g++
CXXFLAGS = -std=c++14 -Werror=vla -MMD
EXEC = chess
OBJECTS = main.o Board.o PiecesType.o TextDisplay.o Move.o Piece.o Subject.o Chess.o Player.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${DEPENDS} ${EXEC}
