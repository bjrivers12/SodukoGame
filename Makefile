# Compiler options
CXX = g++-13

SRC_DIR := /Users/aztlan/work/SodukoGame/src
OBJ_DIR := /Users/aztlan/work/SodukoGame/obj
BIN_DIR := /Users/aztlan/work/SodukoGame/bin

EXE := $(BIN_DIR)/play
SRC := $(wildcard $(SRC_DIR)/*.cpp)
OBJ := $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

CXXFLAGS := -std=c++20 -Iinclude -MMD -MP
CFLAGS   := -Wall -Wextra -pedantic
LDFLAGS  := -Llib
LDLIBS   := -lm

.PHONY: all clean

all: $(EXE)

$(EXE): $(OBJ) | $(BIN_DIR)
	$(CXX) $(LDFLAGS) $^ $(LDLIBS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) $(CFLAGS) -c $< -o $@

$(BIN_DIR) $(OBJ_DIR):
	mkdir -p $@

clean:
	@$(RM) -rv $(BIN_DIR) $(OBJ_DIR)

-include $(OBJ:.o=.d)
