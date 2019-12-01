# Simplified Makefile.

APP = fan-daemon
CXX = g++
SRC_DIR = src
OUT_DIR = bin

#compile
$(APP): $(SRC_DIR)/$(APP).cpp
	test -d bin || mkdir -p bin
	$(CXX) $(SRC_DIR)/$(APP).cpp -o $(OUT_DIR)/$(APP)

clean:
	rm -rf bin
	