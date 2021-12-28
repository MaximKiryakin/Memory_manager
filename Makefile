a.out: solution.o modul_1.o modul_2.o
	gcc solution.o modul_1.o modul_2.o -o solution


modul_1.o: modul_1.c modul_1.h
	gcc modul_1.c -c 

modul_2.o: modul_2.c modul_2.h
	gcc modul_2.c -c 

solution.o: solution.c manager.h
	gcc solution.c -c 


clean:
	rm -f modul_1.o modul_2.o solution.o 