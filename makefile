arrayqueue: driver.o events.h
	g++ -o arrayqueue driver.o
driver.o: driver.cpp arrayQueue.h priArrQueue.h events.h
	g++ -c driver.cpp
events.o: events.cpp events.h
	g++ -c events.cpp
clean:
	rm *.o