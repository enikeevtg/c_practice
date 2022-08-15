CF = -Wall -Werror -Wextra

bubble: sorting_algorithms.c
	gcc $(CF) sorting_algorithms.c -o bubble_sorting.exe -D BUBBLE

quick: sorting_algorithms.c
	gcc $(CF) sorting_algorithms.c -o quick_sorting.exe -D QUICK

clean:
	rm -rf *.o *.exe
