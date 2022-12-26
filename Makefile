SRCS = main.cpp tui.cpp
OBJS = $(subst .cpp,.o,$(SRCS))

CXX ?= g++
CPPFLAGS ?=
CXXFLAGS ?=
LDFLAGS ?=

override CPPFLAGS += -I./include
override CXXFLAGS += -std=c++20

DESTDIR ?= /usr/local
DESTDIR_BIN = $(DESTDIR)/bin

TARGET = the-chosen-remastered

MAKE_OBJ = $(CXX) $(CPPFLAGS) $(CXXFLAGS) -c

ifeq ($(LDFLAGS), )
	MAKE_LINK = $(CXX) -o $(TARGET)
else
	MAKE_LINK = $(CXX) $(LDFLAGS) -o $(TARGET)
endif


all : $(TARGET)

$(TARGET) : $(OBJS)
	$(MAKE_LINK) $(OBJS)

main.o : src/main.cpp
	$(MAKE_OBJ) src/main.cpp

tui.o : src/tui.cpp
	$(MAKE_OBJ) src/tui.cpp


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
