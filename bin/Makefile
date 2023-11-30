# creates the test executables and cleans the .o's from bin
all : funcional_tests unit_tests clean





funcional_tests: src.so funcional_test.so ../test/funcional/main.cpp
	@g++ src.so funcional_test.so ../test/funcional/main.cpp -o funcional_tests -Wall


unit_tests: src.so unit_test.so ../test/unit/main.cpp
	g++  src.so unit_test.so ../test/unit/main.cpp  -o unit_tests -Wall
	
	




#-------------------------------------------------------------------------
# Building the .so file for the funcional test files
funcional_test.so: funcional_tests.o derived_flows.o
	g++ -shared -fPIC -o $@ $^

funcional_tests.o: ../test/funcional/funcional_tests.cpp
	g++ -c -fPIC $< -o $@ -Wall
#-------------------------------------------------------------------------





# vensim.o: ../Vensim/vensimimpl.cpp ../Vensim/vensim.h ../Vensim/vensimimpl.h
# 	g++ -c ../Vensim/vensimimpl.cpp -o vensim.o -Wall




#-------------------------------------------------------------------------
# Building the .so file for the source files
src.so: flow.o model.o system.o
	g++ -shared -fPIC -o $@ $^



flow.o: ../src/flowimpl.cpp ../src/flow.h ../src/flowimpl.h
	g++ -c -fPIC $< -o $@ -Wall 

model.o: ../src/modelimpl.cpp ../src/model.h ../src/modelimpl.h
	g++ -c -fPIC $< -o $@ -Wall 

system.o: ../src/systemimpl.cpp ../src/system.h ../src/systemimpl.h
	g++ -c -fPIC $< -o $@ -Wall 


derived_flows.o: ../test/derived_flows/derived_flows.cpp
	g++ -c -fPIC $< -o $@ -Wall
#---------------------------------------------------------------------








#-------------------------------------------------------------------------
# Building the .so file for the unit test files
unit_test.so: unit_test.o unit_flow.o unit_system.o unit_model.o derived_flows.o
	g++ -shared -fPIC -o $@ $^


unit_test.o: ../test/unit/unit_test.cpp ../test/unit/unit_test.h 
	g++ -c -fPIC $< -o $@ -Wall  

unit_flow.o: ../test/unit/unit_flow.cpp ../test/unit/unit_flow.h flow.o
	g++ -c -fPIC $< -o $@ -Wall  

unit_system.o: ../test/unit/unit_system.cpp ../test/unit/unit_system.h system.o
	g++ -c -fPIC $< -o $@ -Wall  

unit_model.o: ../test/unit/unit_model.cpp ../test/unit/unit_model.h model.o
	g++ -c -fPIC $< -o $@ -Wall  
#-------------------------------------------------------------------------------





# clean the .o files from bin
clean:
	rm -f *.o