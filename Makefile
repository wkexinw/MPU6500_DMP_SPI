CXX=g++
CXXFLAGS= -Wall -g -O2
CXX_OPTS= -Wall -g -O2 

INSTALL=install

PROG=mpu6500

%.o: %.c                                                                         
	$(CXX) $(CXXFLAGS) $(CXX_OPTS) $< -o $@ 


all: $(PROG).o 
	$(CXX) $(LDFLAGS) $(CXXFLAGS) -o $(PROG) \
		main.c \
		MotionSensor/libMotionSensor.a \
		libs/libSPIdev.a -lbcm2835

$(PROG).o: MotionSensor/libMotionSensor.a libs/libSPIdev.a

MotionSensor/libMotionSensor.a:
	$(MAKE) -C MotionSensor/ 

libs/libSPIdev.a:
	$(MAKE) -C libs/SPIdev

install1:
	$(INSTALL) -m 755 $(PROG) $(DESTDIR)/usr/local/bin/

clean:
	cd MotionSensor && $(MAKE) clean
	cd libs/SPIdev && $(MAKE) clean
	rm -rf *.o *~ *.mod
	rm -rf $(PROG)
