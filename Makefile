# Компилятор и флаги
CXX = g++
CXXFLAGS = -std=c++11 -lstdc++
TARGET = EVE_V2
SOURCES = main.cpp directory_util.cpp helpers_func.cpp
.PHONY: clean
OBJECTS = $(SOURCES:.cpp=.o)
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
clean:
	rm -f $(OBJECTS) $(TARGET)
del_o:
	rm -f $(OBJECTS)
