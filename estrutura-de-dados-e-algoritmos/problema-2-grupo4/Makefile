CXX      :=	-c++
LDFLAGS  := -L /usr/lib/x86_64-linux-gnu -lGL -lGLU -lglut

BUILD    := ./build
INCLUDE  := -Iinclude/
TARGET   := baseCode
OBJ_DIR  := $(BUILD)/objects
APP_DIR  := $(BUILD)/apps

SRC      := $(wildcard src/struct/*.cpp) \
			$(wildcard src/grafic/*.cpp) \

OBJECTS  := $(SRC:%.cpp=$(OBJ_DIR)/%.o)
DEPENDENCIES \
         := $(OBJECTS:.o=.d)

all: build $(APP_DIR)/$(TARGET)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	$(CXX) $(INCLUDE) -c $< -MMD -o $@ $(LDFLAGS)

$(APP_DIR)/$(TARGET): $(OBJECTS)
	@mkdir -p $(@D)
	$(CXX) -o $(APP_DIR)/$(TARGET) $^ $(LDFLAGS)

-include $(DEPENDENCIES)

.PHONY: all build run clean info

build:
	@mkdir -p $(APP_DIR)
	@mkdir -p $(OBJ_DIR)

run:
	./build/apps/baseCode

clean:
	-@rm -rvf $(OBJ_DIR)/*
	-@rm -rvf $(APP_DIR)/*

info:
	@echo "[*] Application dir: ${APP_DIR}     "
	@echo "[*] Object dir:      ${OBJ_DIR}     "
	@echo "[*] Sources:         ${SRC}         "
	@echo "[*] Objects:         ${OBJECTS}     "
	@echo "[*] Dependencies:    ${DEPENDENCIES}"