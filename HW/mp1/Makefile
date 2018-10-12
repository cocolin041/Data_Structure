CXXFLAGS = -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic
LDFLAGS = -std=c++1y -stdlib=libc++ -lpthread -lm
CXX = clang++
LD = clang++

# $? and $@ are special predefined macros \
$? : names of the dependencies \
$@ : names of the target
# $(CXX) $(LDFLAGS) $? -o $@

#executable: when you type this, it will execute
mp1 : mp1.o main.o HSLAPixel.o PNG.o lodepng.o
	clang++ mp1.o main.o HSLAPixel.o PNG.o lodepng.o -o mp1

main.o : main.cpp
	clang++ -c main.cpp
mp1.o : mp1.cpp mp1.h
	clang++ -c mp1.cpp
HSLAPixel.o : cs225/HSLAPixel.cpp cs225/HSLAPixel.h
	clang++ -c cs225/HSLAPixel.cpp
PNG.o : cs225/PNG.cpp cs225/PNG.h
	clang++ -c cs225/PNG.cpp
lodepng.o : cs225/lodepng/lodepng.cpp cs225/lodepng/lodepng.h
	clang++ -c cs225/lodepng/lodepng.cpp

test : unit_tests.o mp1.o PNG.o HSLAPixel.o lodepng.o
	$(LD) unit_tests.o mp1.o PNG.o HSLAPixel.o lodepng.o $(LDFLAGS) -o test

unit_tests.o : tests/unit_tests.cpp tests/catch.hpp cs225/PNG.h cs225/HSLAPixel.h
	$(CXX) $(CXXFLAGS) tests/unit_tests.cpp

clean :
	rm mp1 *.o
