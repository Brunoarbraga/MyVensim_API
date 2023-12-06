all : funcional_tests unit_tests src.so



derived_flows.o: ../test/derived_flows/derived_flows.cpp
	g++ -c ../test/derived_flows/derived_flows.cpp -o derived_flows.o -Wall

src.so:
	@g++ -fPIC -shared -o src.so ../src/*.cpp -Wall -g


funcional_tests: src.so derived_flows.o
	@g++ ../test/funcional/*.cpp src.so derived_flows.o -o funcional_tests -Wall


unit_tests: src.so derived_flows.o
	@g++ ../test/unit/*.cpp src.so derived_flows.o -o unit_tests -Wall
	









clean:
	@rm -f *.o *.so funcional_tests unit_tests