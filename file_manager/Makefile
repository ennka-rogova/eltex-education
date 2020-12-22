
file_manager: file_manager.o Basic_functions.o output_directory.o current_directory.o Grafical_interface.o
	gcc  file_manager.o  Basic_functions.o output_directory.o current_directory.o Grafical_interface.o -o file_manager -lncurses -g

file_manager.o: file_manager.c Basic_functions.h output_directory.h struct_file.h  current_directory.h Grafical_interface.h
	gcc -c file_manager.c  

output_directory.o: output_directory.c struct_file.h current_directory.h
	gcc -c output_directory.c 
current_directory.o: current_directory.c
	gcc -c current_directory.c 

Basic_functions.o: Basic_functions.c struct_file.h current_directory.h
	gcc -c Basic_functions.c

Grafical_interface.o: Grafical_interface.c struct_file.h current_directory.h output_directory.h
	gcc -c Grafical_interface.c

clean:
	rm -rf *.o file_manager
