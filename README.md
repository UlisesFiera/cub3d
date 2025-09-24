Trivia

	The window size is 1280x800, a 16:10 resolution used classically by Doom to use fewer pixels. It's a callback to the limitations of the time. 

Considerations

	On parsing error, there will inevitably be "still reachable" reports caused by the way 42 forces us to design the get_next_line.c function. They happen only on exit, not at runtime, so they are just ignored.