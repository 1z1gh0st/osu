XX=g++ 
CXXFLAGS=-c -std=c++11 
exe_file= assignment1

$(exe_file): main.o helper.o terminal_io.o file_io.o sorting.o 
	$(CXX) -std=c++11 main.o helper.o terminal_io.o file_io.o sorting.o -o $(exe_file) 
 
main.o: main.cpp 
	$(CXX) $(CXXFLAGS) main.cpp 
 
helper.o: helper.cpp 
	$(CXX) $(CXXFLAGS) helper.cpp 
 
terminal_io.o: terminal_io.cpp 
	$(CXX) $(CXXFLAGS) terminal_io.cpp 
 
file_io.o: file_io.cpp 
	$(CXX) $(CXXFLAGS) file_io.cpp 
 
sorting.o: sorting.cpp 
	$(CXX) $(CXXFLAGS) sorting.cpp 

clean:
	rm –f *.out *.o $(exe_file)