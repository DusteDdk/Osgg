DATADIR?=./

CXX?=g++

CXXFLAGS+=-Wall `sdl-config --cflags` -DDATADIR="\"$(DATADIR)\""

LIBS+=`sdl-config --libs` -lSDL_ttf -lSDL_image -lSDL_mixer -lGL -lm

SOURCES=main.cpp text.cpp sound.cpp
OBJECTS=$(SOURCES:.cpp=.o)

EXECUTABLE=osgg

all: $(SOURCES) $(EXECUTABLE)

server: server.cpp
	$(CXX) $(CXXFLAGS) $(LDFLAGS) server.cpp $(LIBS) -o $@

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(LDFLAGS) $(OBJECTS) $(LIBS) -o $@

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o $(EXECUTABLE)
