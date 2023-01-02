SRCS = src/main.cpp src/tui.cpp src/customstring.cpp src/gameentity.cpp src/parser.cpp src/game.cpp src/world.cpp src/player.cpp
OBJS = $(subst src,build,$(subst .cpp,.o,$(SRCS)))

CXX ?= g++
CPPFLAGS ?=
CXXFLAGS ?=
LDFLAGS ?=

DEBUG ?= n

override CPPFLAGS += -I./include
override CXXFLAGS += -std=c++17 -Wall
override LDFLAGS += -lncurses

DESTDIR ?= /usr/local
DESTDIR_BIN = $(DESTDIR)/bin

TARGET = the-chosen-remastered
TARGET_PATH = build/$(TARGET)

ifeq ($(DEBUG), y)
	override CXXFLAGS += -g
	override LDFLAGS += -g
endif

MAKE_OBJ = $(CXX) $(CPPFLAGS) $(CXXFLAGS) -c
MAKE_LINK = $(CXX) $(LDFLAGS) -o $(TARGET_PATH)


all : $(TARGET)

$(TARGET) : $(OBJS)
	$(MAKE_LINK) $(OBJS)

build/%.o : src/%.cpp
	$(MAKE_OBJ) src/$*.cpp -o $@


.PHONY : clean distclean install uninstall

clean : 
	-rm $(OBJS)

distclean : 
	-rm $(TARGET_PATH)

install : $(TARGET)
	@install -d $(DESTDIR_BIN)
	@install $(TARGET_PATH) $(DESTDIR_BIN)
	@echo "$(TARGET) was installed to $(DESTDIR)"

uninstall :
	@if [ -f $(DESTDIR_BIN)/$(TARGET) ]; then rm $(DESTDIR_BIN)/$(TARGET) && echo "$(DESTDIR_BIN)/$(TARGET) was deleted"; else echo "ERROR: $(TARGET) not installed at location: \"$(DESTDIR_BIN)\" --> please uninstall manually"; fi
