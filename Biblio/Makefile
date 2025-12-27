# ============================================================================
# Makefile - Compilation du projet Bibliotheque
# ============================================================================
# Commandes:
#   make        -> compile le projet
#   make clean  -> supprime les fichiers générés
#   make run    -> compile et exécute
# ============================================================================

# Compilateur
CXX = g++

# Options de compilation
# -Wall : affiche tous les warnings
# -std=c++11 : utilise le standard C++11
CXXFLAGS = -Wall -std=c++11

# Nom de l'exécutable
TARGET = bibliotheque

# Fichiers sources (.cpp)
SOURCES = main.cpp \
          Livre.cpp \
          Roman.cpp \
          BandeDessinee.cpp \
          Poesie.cpp \
          Theatre.cpp \
          Album.cpp \
          Adherent.cpp \
          Bibliotheque.cpp

# Fichiers objets (.o) générés automatiquement
OBJECTS = $(SOURCES:.cpp=.o)

# ============================================================================
# Règles
# ============================================================================

# Règle par défaut : compiler tout
all: $(TARGET)
	@echo ""
	@echo "======================================"
	@echo "  Compilation terminee avec succes !"
	@echo "  Tapez ./bibliotheque pour executer"
	@echo "======================================"

# Créer l'exécutable à partir des fichiers objets
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

# Règle générique : compiler un .cpp en .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Nettoyer les fichiers générés
clean:
	rm -f $(OBJECTS) $(TARGET)
	@echo "Nettoyage termine !"

# Compiler et exécuter
run: all
	@echo ""
	./$(TARGET)

# Ces règles ne sont pas des fichiers
.PHONY: all clean run