all: Utils.h Utils.c hamming_distance.c msb_lsb.c my_arrays.c my_pointers.c more_arrays.c
	@for i in {1..5} ;do \
		echo "Exercise $${i}:"; \
		make Exercise$${i} -s; \
		echo; \
		echo; \
	done;

Exercise1: Utils.c hamming_distance.c
	@gcc -o $@.out Utils.c hamming_distance.c
	@./$@.out

Exercise2: Utils.c msb_lsb.c
	@gcc -o $@.out Utils.c msb_lsb.c
	@./$@.out

Exercise3: my_arrays.c
	@gcc -o $@.out my_arrays.c
	@./$@.out

Exercise4: my_pointers.c
	@gcc -o $@.out my_pointers.c
	@./$@.out

Exercise5: Utils.c more_arrays.c
	@gcc -o $@.out Utils.c more_arrays.c
	@./$@.out

clean:
	@rm ./Exercise*.out -f
