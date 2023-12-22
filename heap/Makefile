.PHONY: build run

build:
	docker build . --tag "my_heap"

run:
	docker run -it my_heap ./main.exe

run_tests:
	docker run -it my_heap ./build/heap_test
