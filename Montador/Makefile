Compilador = g++
FLAGS = -Wall -Wextra -std=c++11
LIBS = -lm

TARGET = MONTADOR

SRC_DIR = src
INC_DIR = include


SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(SRC_DIR)/%.o, $(SRCS))
FLAGS += -I$(INC_DIR)


$(TARGET): $(OBJS)
	$(Compilador) $(FLAGS) $(OBJS) -o $(TARGET) $(LIBS)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(Compilador) $(FLAGS) -c $< -o $@ $(LIBS)

clean:
	rm -f $(OBJS) $(TARGET)
