CXX=g++

test: vector_test matrix_test linear_system

vector_test: Vector_test.cpp Vector.h Vector.cpp
	$(CXX) Vector_test.cpp Vector.cpp -g -o vector_test

matrix_test: Matrix_test.cpp Matrix.h Matrix.cpp Vector.h
	$(CXX) Matrix_test.cpp Matrix.cpp Vector.cpp -g -o matrix_test

linear_system: LinearSystem_test.cpp LinearSystem.h LinearSystem.cpp Matrix.h Matrix.cpp Vector.h Vector.cpp
	$(CXX) LinearSystem_test.cpp LinearSystem.cpp Matrix.cpp Vector.cpp -g -o linear_system

run: vector_test matrix_test linear_system
	./vector_test
	./matrix_test
	./linear_system

clean:
	rm -fr vector_test matrix_test linear_system
