#include <iostream>
#include <fstream>
using namespace std;

string remove_comments(string input)
{
    int size = input.length();
    string output;
    bool comment_type_single = false;
    bool comment_type_multi = false;

    for (int i = 0; i < size; i++) 
    {
        // Check single line comment: start
        if (input[i] == '/' && input[i+1] == '/')
        {
            comment_type_single = true;
        } 
        // Check single line comment: end
        else if (comment_type_single == true && input[i] == '\n')
        {
            comment_type_single = false;
        }
        // Check multi line comment: start
        else if (input[i] == '/' && input[i+1] == '*')
        {
            comment_type_multi = true;
        } 
        // Check multi line comment: end
        else if (comment_type_multi == true && input[i] == '*' && input[i+1] == '/')
        {
            comment_type_multi = false;
            i++;
        }
        // In the middle of a comment
        else if (comment_type_single || comment_type_multi) 
        {
            i++;
            continue; 
        } 
        // Add to output if the current token is not a part of a comment
        else if (comment_type_multi == false && comment_type_single == false)
        {
            output += input[i];
        }
    }
    return output;
}

int main(int argc, char* argv[])
{
    string str;
	ifstream inputfile;
    ofstream outputfile;
	inputfile.open(argv[1]);
    outputfile.open("input_C_source_rem.cpp");
    cout << endl << endl;
    cout << "长者语录" << endl << endl;
    while(!inputfile.eof()) // To get you all the lines.
    {
        getline(inputfile,str);
        outputfile << remove_comments(str) << endl;
    }
    inputfile.close();
    outputfile.close();
}