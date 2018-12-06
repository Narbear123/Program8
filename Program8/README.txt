12/6/2018 Catching plagiarists

This program was written by Naris Anukornchaikul & Mayna Nguyen.

This program takes an input of a directory path, x = how many words should be checked to be a "chunk" when compared to others,
and a threshold minimum number of similarities of x-word chunks there are to be printed out.
The input should look like: ./plagiarismCatcher path/to/files 6 200
where 6 = x word chunks; 200 = threshold number of similarities to be printed to the screen.
The directory path should only have 25 documents (of around 33,000 words total) for this program to work.

The output is a list of what pairs of documents have passed the threshold number of similarities, and how many similarities were found between the documents. The list of pairs is not necessarily in order of number of similarities. 

The program will not work with larger sets of documents. 
