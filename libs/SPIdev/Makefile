CXX=g++
AR=ar
CXXCFLAGS=-Wall -g -O2
CXX_OPTS=-c
LDFLAGS= -lm -lrt

LIB=../libSPIdev.a
OBJ=SPIdev.o

%.o: %.c                                                                         
	$(CXX) $(CXXFLAGS) $(CXX_OPTS) $< -o $@  -lbcm2835

$(LIB): $(OBJ)
	$(AR) rcs $(LIB) $(OBJ)

all: $(LIB)

clean:
	rm -rf *.o
	rm -rf $(LIB)
