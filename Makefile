hello_world: hello_world.cpp
	$(CC) $(CFLAGS) $^ -o $@

.PHONY: clean
clean:
	rm hello_world
