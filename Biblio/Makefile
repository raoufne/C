# ============================================================================
# Makefile - Projet Bibliotheque
# ============================================================================
# make      -> compile le programme
# make run  -> compile et execute
# make clean -> nettoie
# ============================================================================

CXX = g++
CXXFLAGS = -Wall -std=c++11

TARGET = Program

# Fichiers sources
SOURCES = main.cpp \
          mainv1.cpp \
          mainv2.cpp \
          mainv3.cpp \
          Livre.cpp \
          Roman.cpp \
          BandeDessinee.cpp \
          Poesie.cpp \
          Theatre.cpp \
          Album.cpp \
          Adherent.cpp \
          Bibliotheque.cpp

OBJECTS = $(SOURCES:.cpp=.o)

# Compilation
all: $(TARGET)
	@echo ""
	@echo "======================================"
	@echo "  Compilation terminee!"
	@echo "  Tapez ./Program pour executer"
	@echo "======================================"

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)
	rm -f *.txt
	@echo "Nettoyage termine!"

run: all
	./$(TARGET)

.PHONY: all clean run
