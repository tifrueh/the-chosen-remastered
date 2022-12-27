SRCS = src/main.cpp src/tui.cpp src/customstring.cpp src/player.cpp
OBJS = $(subst src,build,$(subst .cpp,.o,$(SRCS)))

CXX ?= g++
CPPFLAGS ?=
CXXFLAGS ?=
LDFLAGS ?=

DEBUG ?= n

override CPPFLAGS += -I./include
override CXXFLAGS += -std=c++20 -Wall
override LDFLAGS += -lncurses

DESTDIR ?= /usr/local
DESTDIR_BIN = $(DESTDIR)/bin

TARGET = build/the-chosen-remastered

ifeq ($(DEBUG), y)
	override CXXFLAGS += -g
	override LDFLAGS += -g
endif

MAKE_OBJ = $(CXX) $(CPPFLAGS) $(CXXFLAGS) -c

ifeq ($(LDFLAGS), )
	MAKE_LINK = $(CXX) -o $(TARGET)
else
	MAKE_LINK = $(CXX) $(LDFLAGS) -o $(TARGET)
endif


all : $(TARGET)

$(TARGET) : $(OBJS)
	$(MAKE_LINK) $(OBJS)

build/main.o : src/main.cpp
	$(MAKE_OBJ) src/main.cpp -o build/main.o

build/tui.o : src/tui.cpp
	$(MAKE_OBJ) src/tui.cpp -o build/tui.o

build/customstring.o : src/customstring.cpp
	$(MAKE_OBJ) src/customstring.cpp -o build/customstring.o

build/player.o : src/player.cpp
	$(MAKE_OBJ) src/player.cpp -o build/player.o


.PHONY : clean distclean install uninstall

clean : 
	-rm $(OBJS)

distclean : 
	-rm $(TARGET)

install : $(TARGET)
	@install -d $(DESTDIR_BIN)
	@install $(TARGET) $(DESTDIR_BIN)
	@echo "$(TARGET) was installed to $(DESTDIR)"

uninstall :
	@if [ -f $(DESTDIR_BIN)/$(TARGET) ]; then rm $(DESTDIR_BIN)/$(TARGET); else echo "ERROR: $(TARGET) not installed at location: \"$(DESTDIR_BIN)\" --> please uninstall manually"; fi
