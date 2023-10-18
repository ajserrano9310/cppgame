CXX = g++

# Compiler flags
CXXFLAGS = -std=c++11 -I/opt/homebrew/Cellar/sfml/2.6.0/include

# Linker flags and libraries
LDFLAGS = -L/opt/homebrew/Cellar/sfml/2.6.0/lib
LIBS = -lsfml-graphics -lsfml-window -lsfml-system

# Source files
SOURCES = main.cpp entity.cpp player.cpp Projectile/projectile.cpp GameConfig.cpp enemy.cpp grunt.cpp

# Object files
OBJECTS = $(SOURCES:.cpp=.o)

# Output executable name
EXECUTABLE = prog

# Main target
all: $(EXECUTABLE)

# Compile source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Link object files to create the executable
$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(OBJECTS) $(LDFLAGS) $(LIBS) -o $(EXECUTABLE)

# Clean up generated files
clean:
	rm -f $(OBJECTS) $(EXECUTABLE)