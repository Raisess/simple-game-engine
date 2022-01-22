CC=g++

FLAGS=-w
LINKER_FLAGS=

SRC_DIR=./src
FILES=$(SRC_DIR)/main.cpp \
			$(SRC_DIR)/Engine/Window.cpp

BUILD_DIR=./build
BUILD=DwarfAttack

build:
	mkdir -p $(BUILD_DIR)
	$(CC) $(FLAGS) $(LINKER_FLAGS) $(FILES) -o $(BUILD_DIR)/$(BUILD)

clean:
	rm -rf $(BUILD_DIR)
