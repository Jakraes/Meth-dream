all:
	g++ src/*.cpp -Iinc/ -Llib/ -lBearLibTerminal -mwindows -s -O3 -o app.exe

run: all
	./app.exe