Compiler = g++
FLAGS = -Wall -Werror
LIBS = -lm


EXEC = MONTADOR


all: src/preprocess.o src/main.o
    g++ -g src/preprocess.o src/main.o -o main $(LIBS)

preprocess.o: src/preprocess.cpp
    #$(Compiler) $(FLAGS) -o myprogram main.o myfunctions.o $(LIBS)
    g++ -c src/preprocess.cpp 

main.o: main.cpp
    $(Compiler) $(FLAGS) -c main.cpp

#preprocess.o: myfunctions.cpp myheader.h
    #$(Compiler) $(FLAGS) -c myfunctions.cpp

clean:
    rm -f *.o

run:
    ./$(EXEC)


#ainda nao funciona, arruamr depois

   # $(CXX) $(CXXFLAGS) -o myprogram main.o myfunctions.o $(LIBS)