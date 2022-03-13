CC=g++

FLAGS=-w
LINKER_FLAGS=-lSDL2 -lSDL2_ttf

SRC_DIR=./src
FILES=$(SRC_DIR)/main.cpp \
			$(SRC_DIR)/Core/Window.cpp \
			$(SRC_DIR)/Core/ScreenComponent.cpp \
			$(SRC_DIR)/Core/TextComponent.cpp \
			$(SRC_DIR)/Core/Camera.cpp \
			$(SRC_DIR)/Core/Physics.cpp \
			$(SRC_DIR)/Core/Managers/ScreenComponentManager.cpp \
			$(SRC_DIR)/Core/Managers/TextComponentManager.cpp \
			$(SRC_DIR)/Assets/Player.cpp \
			$(SRC_DIR)/Assets/Platform.cpp

BUILD_DIR=./build
BUILD=main

build:
	mkdir -p $(BUILD_DIR)
	$(CC) $(FLAGS) $(LINKER_FLAGS) $(FILES) -o $(BUILD_DIR)/$(BUILD)

clean:
	rm -rf $(BUILD_DIR)

run:
	clear
	make clean
	make
	chmod +x $(BUILD_DIR)/$(BUILD)
	$(BUILD_DIR)/$(BUILD)
