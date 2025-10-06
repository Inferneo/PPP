#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using std::cin;
using std::ifstream;
using std::istream_iterator;
using std::ofstream;
using std::ostream_iterator;
using std::sort;
using std::string;
using std::unique_copy;
using std::vector;

int main() { 
    
    string from, to;
    cin >> from >> to;      // get source and target file names

    ifstream is{from};      // open input stream
    ofstream os{to};        // open output stream

    istream_iterator<string> ii {is};               // make input iterator for stream
    istream_iterator<string> eos;                       // input sentinel
    ostream_iterator<string> oo {os, "\n"};       // make output iterator for stream

    vector<string> b{ii, eos};                      // b is a vector initialized from input
    sort(b.begin(), b.end());                       // sort the buffer
    unique_copy(b.begin(), b.end(), oo);    // copy buffer to output
}