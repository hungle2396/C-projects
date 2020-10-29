For each operand that names a file of a type other than directory,
my_ls displays its name as well as any requested, associated information. 
For each operand that names a file of type directory, my_ls displays the 
names of files contained within that directory, as well as any requested, 
associated information.

If no operands are given, the contents of the current directory are displayed. 
If more than one operand is given, non-directory operands are displayed first; 
directory and non-directory operands are sorted separately and in lexicographical order.

The following options are available:
-a Include directory entries whose names begin with a dot (.).
-t Sort by time modified (most recently modified first) before sorting the operands by lexicographical order.

**** Instruction on how to compile and use my_ls. ****
1. Go to ex00 directory
2. Because I created a makefile for this program, you can compile the files by typing "make"
- It will give you the output "my_ls"
3. Feel free to create your own directories with different type of files in them.
- type in your terminal:
- "./my_ls -a" to list all the files in the directory, including the hidden files.
- "./my_ls -t" to sort all the files from most recently modified to least recently modified files, and lexicographical order after.
- "./my_list -at" or "./my_list -ta" or "./my_list -a -t" to sort all the files (including the hidden files) from most recently modified files
  to the least, and lexicographical order after. 
4. To clean/remove the .o files, type "make clean" in your terminal