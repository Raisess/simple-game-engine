CC=g++

FLAGS=-w
LINKER_FLAGS=-lSDL2 -lSDL2_ttf

SRC_DIR=./src
ENGINE_FILES=$(SRC_DIR)/Core/Window.cpp \
						 $(SRC_DIR)/Core/ScreenComponent.cpp \
						 $(SRC_DIR)/Core/TextComponent.cpp \
						 $(SRC_DIR)/Core/Camera.cpp \
						 $(SRC_DIR)/Core/Physics.cpp \
						 $(SRC_DIR)/Core/Managers/ScreenComponentManager.cpp \
						 $(SRC_DIR)/Core/Managers/TextComponentManager.cpp \
						 $(SRC_DIR)/Assets/Object.cpp

BUILD_DIR=./build

PLATFORM_FILE=$(SRC_DIR)/examples/platform.cpp
PLATFORM_BUILD=platform

PONG_FILE=$(SRC_DIR)/examples/pong.cpp
PONG_BUILD=pong

platform:
	mkdir -p $(BUILD_DIR)
	$(CC) $(FLAGS) $(LINKER_FLAGS) $(ENGINE_FILES) $(PLATFORM_FILE) -o $(BUILD_DIR)/$(PLATFORM_BUILD)

pong:
	mkdir -p $(BUILD_DIR)
	$(CC) $(FLAGS) $(LINKER_FLAGS) $(ENGINE_FILES) $(PONG_FILE) -o $(BUILD_DIR)/$(PONG_BUILD)

clean:
	rm -rf $(BUILD_DIR)

run:
	clear
	make clean
	make
	chmod +x $(BUILD_DIR)/$(BUILD)
	$(BUILD_DIR)/$(BUILD)
