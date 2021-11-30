CXX = g++
CPPFLAGS = -Wall -g

all: output

output: 
	$(CXX) $(CPPFLAGS) *.cpp -o output

clean:
	rm -f output