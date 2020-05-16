OBJECTS=main.o

CFLAGS+=-std=c++11 -g -pthread -fsanitize=address

all: $(OBJECTS)
	$(CXX) $(OBJECTS) $(CFLAGS)

%.o: %.cpp
	$(CXX) -c $(CFLAGS) $< -o $@

clean:
	rm -f *.o *.a *.out
