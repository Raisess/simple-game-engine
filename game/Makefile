CC=g++

FLAGS=-w
LINKER_FLAGS=-lSDL2 -lSDL2_ttf

SRC_DIR=./src
FILES=$(SRC_DIR)/main.cpp \
			$(SRC_DIR)/Engine/Window.cpp \
			$(SRC_DIR)/Engine/ScreenComponent.cpp \
			$(SRC_DIR)/Engine/TextComponent.cpp \
			$(SRC_DIR)/Engine/Camera.cpp \
			$(SRC_DIR)/Engine/Physics.cpp \
			$(SRC_DIR)/Engine/Managers/ScreenComponentManager.cpp \
			$(SRC_DIR)/Engine/Managers/TextComponentManager.cpp \
			$(SRC_DIR)/Game/Player.cpp \
			$(SRC_DIR)/Game/Platform.cpp

BUILD_DIR=./build
BUILD=DwarfAttack

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
