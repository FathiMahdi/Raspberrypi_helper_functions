SOURCE = blink_thread
TARGET = exe
COMPILER = g++
CPP_FLAGS = "-wall -std=c++11"
C_FLAGS = "-Wall"


all:
	$(COMPILER) $(SOURCE).cpp -o $(TARGET) $(C_FLAGS) -pthread -lwiringPi -lwiringPiDev

