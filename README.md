# Huffman Tree Compression

A Huffman encoder compression algorithm is used to compress English language text files. 

It is a fairly quick and easy way of turning a sequence of ASCII characters into a compressed bit stream.

To compile:

change directory into the 'src' folder and type make.

To run: (in 'src' directory)

./huffmanencode <inputFilePrefix> <outputFilePrefix>

I/O:

All input files must be located in the input folder, one directory removed from the 'src' directory

All output files will be directed to the output folder, one directory removed from the 'src' directory

For Testing:

in the 'src' folder, run make test.
Note that the 1st test case is directed at testing the input file 'test.txt' and will fail for other input files. 
Other test cases are also directed all at the file 'test.txt'
the purpose of this was to test the frequency map with a known input string.
./
