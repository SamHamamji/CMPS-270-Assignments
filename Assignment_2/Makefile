all: my_btree.cpp my_stack.cpp my_graph.cpp
	@echo "Exercise 1:"
	@make Exercise1 -s
	@echo; echo;

	@echo "Exercises 2 and 3:"
	@make Exercise2 -s
	@echo; echo;

	@echo "Exercise 4 and 5:"
	@make Exercise4 -s

Exercise1: my_btree.cpp
	@g++ -o $@.out my_btree.cpp
	@./$@.out

Exercise2 Exercise3: my_stack.cpp
	@g++ -o $@.out my_stack.cpp
	@./$@.out

Exercise4 Exercise5: my_graph.cpp
	@g++ -o $@.out my_graph.cpp
	@./$@.out

clean:
	@rm ./Exercise*.out -f
