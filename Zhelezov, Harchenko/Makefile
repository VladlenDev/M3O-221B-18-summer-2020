SRC_DIR= opencvmodel
CC=g++
CFLAGS=-c -Wall -I/usr/local/include/opencv4 -L/usr/local/lib
LDFLAGS=-I/usr/local/include/opencv4 -L/usr/local/lib
SOURCES=$(SRC_DIR)/main.cpp $(SRC_DIR)/Ball.cpp $(SRC_DIR)/Box.cpp $(SRC_DIR)/Counter.cpp $(SRC_DIR)/Finder.cpp $(SRC_DIR)/Intelligence.cpp $(SRC_DIR)/Robot.cpp $(SRC_DIR)/ViewFrame.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=opencvModel
LIBRARIES = -lopencv_core -lopencv_imgproc -lopencv_highgui -lopencv_imgcodecs -lopencv_videoio

all: $(SOURCES) $(EXECUTABLE)	
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@ $(LIBRARIES)

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@


