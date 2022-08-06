
# get_next_line ✍️

This project will not only allow you to add a very convenient function to your collection,
but it will also make you learn a highly interesting new concept in C programming: static
variables.
## 🛠 Installation

Clone the repository:

```bash
  git clone https://github.com/salecler/get_next_line.git
```
    
## ⚙️ Deployment

To deploy this project run:

```bash
  make
```
Then you can run it:
````
./gnl
````
## 👨‍🏫 Instructions

• Repeated calls (e.g., using a loop) to your get_next_line() function should let
you read the text file pointed to by the file descriptor, one line at a time.

• Your function should return the line that was read.
If there is nothing else to read or if an error occurred, it should return NULL.

• Make sure that your function works as expected both when reading a file and when
reading from the standard input.

• Please note that the returned line should include the terminating \n character,
except if the end of file was reached and does not end with a \n character.

• Your header file get_next_line.h must at least contain the prototype of the
get_next_line() function.

• Add all the helper functions you need in the get_next_line_utils.c file

• Because you will have to read files in get_next_line(), add this option to your
compiler call: -D BUFFER_SIZE=n
It will define the buffer size for read().
The buffer size value will be modified by your peer-evaluators and the Moulinette
in order to test your code.

• You will compile your code as follows (a buffer size of 42 is used as an example):
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c

• We consider that get_next_line() has an undefined behavior if the file pointed to
by the file descriptor changed since the last call whereas read() didn’t reach the
end of file.

• We also consider that get_next_line() has an undefined behavior when reading
a binary file. However, you can implement a logical way to handle this behavior if
you want to.
## 🤠 Features

Make:
- clean/fclean
- re



## 🔗 Links
[![github](https://img.shields.io/badge/my_portfolio-000?style=for-the-badge&logo=ko-fi&logoColor=white)](https://github.com/salecler?tab=repositories)
[![linkedin](https://img.shields.io/badge/linkedin-0A66C2?style=for-the-badge&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/sacha-leclercq-245584243/)


## 👋 Authors

- [@salecler](https://www.github.com/salecler)

