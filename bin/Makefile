all : funcional_tests unit_tests

funcional_tests: flow.o model.o system.o funcional_tests.o derived_flows.o ../test/funcional/main.cpp
	@g++ -Wall -o funcional_tests flow.o model.o system.o funcional_tests.o derived_flows.o ../test/funcional/main.cpp


unit_tests: flow.o model.o system.o derived_flows.o unit_test.o unit_flow.o unit_system.o unit_model.o ../test/unit/main.cpp
	g++ flow.o derived_flows.o model.o system.o unit_test.o unit_flow.o unit_system.o unit_model.o ../test/unit/main.cpp  -o unit_tests -Wall
	





funcional_tests.o: ../test/funcional/funcional_tests.cpp
	@g++ -c ../test/funcional/funcional_tests.cpp -o funcional_tests.o -Wall


# unit_test.o: ../test/unit/unit_test.cpp ../test/unit/unit_test.h 
# 	g++ -c ../test/unit/unit_test.cpp -o unit_test.o -Wall 



# vensim.o: ../Vensim/vensimimpl.cpp ../Vensim/vensim.h ../Vensim/vensimimpl.h
# 	g++ -c ../Vensim/vensimimpl.cpp -o vensim.o -Wall





flow.o: ../src/flowimpl.cpp ../src/flow.h ../src/flowimpl.h
	g++ -c ../src/flowimpl.cpp -o flow.o -Wall 

model.o: ../src/modelimpl.cpp ../src/model.h ../src/modelimpl.h
	g++ -c ../src/modelimpl.cpp -o model.o -Wall 

system.o: ../src/systemimpl.cpp ../src/system.h ../src/systemimpl.h
	g++ -c ../src/systemimpl.cpp -o system.o -Wall 


derived_flows.o: ../test/derived_flows/derived_flows.cpp
	@g++ ../test/derived_flows/derived_flows.cpp -c -Wall









unit_flow.o: ../test/unit/unit_flow.cpp ../test/unit/unit_flow.h flow.o
	g++ -c ../test/unit/unit_flow.cpp -o unit_flow.o -Wall 

unit_system.o: ../test/unit/unit_system.cpp ../test/unit/unit_system.h system.o
	g++ -c ../test/unit/unit_system.cpp -o unit_system.o -Wall 

unit_model.o: ../test/unit/unit_model.cpp ../test/unit/unit_model.h model.o
	g++ -c ../test/unit/unit_model.cpp -o unit_model.o -Wall 