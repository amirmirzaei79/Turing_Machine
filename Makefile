driver: driver.cpp Turing_Machine.cpp Turing_Machine.h Tape.cpp Tape.h
	g++ -o driver driver.cpp Turing_Machine.cpp Tape.cpp

clean:
	rm driver