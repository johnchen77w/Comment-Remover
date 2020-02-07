all: remove_comments

remove_comments: remove_comments.cpp
	g++ -o remove_comments remove_comments.cpp

clean:
	-rm remove_comments input_C_source_rem.cpp