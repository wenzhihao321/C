.PHONY:cloud 

cloud:util.hpp cloud.cpp 
	g++ -g -o $@ $^ -L./lib -lpthread -lstdc++fs -ljsoncpp -lbundle
.PHONY:clean
clean:
	rm -f cloud
