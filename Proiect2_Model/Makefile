build:
	-mkdir obj 2> /dev/null
	g++ -c -o obj/AbstractAnimal.o src/AbstractAnimal.cpp
	g++ -c -o obj/Bird.o src/Bird.cpp
	g++ -c -o obj/Fish.o src/Fish.cpp
	g++ -c -o obj/Mammal.o src/Mammal.cpp
	g++ -c -o obj/Aquarium.o src/Aquarium.cpp
	g++ -c -o obj/main.o main.cpp
	g++ -o main obj/main.o obj/AbstractAnimal.o obj/Bird.o obj/Fish.o obj/Mammal.o obj/Aquarium.o

clean:
	-rm -rf obj/ 2> /dev/null
	-rm main 2> /dev/null
