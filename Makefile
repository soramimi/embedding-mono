all:
	g++ a.cpp `pkg-config --cflags --libs mono-2`
	mcs -target:library b.cs -out:b.dll
	gcc -shared c.cpp -o lib.so

clean:
	rm -f *.exe
	rm -f *.out
	rm -f *.dll
	rm -f *.so
