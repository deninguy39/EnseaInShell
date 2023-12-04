# Lab 1 : EnseaInShell

NGUYEN Denis and TESTUZ Lauriane 2G1TD2TP3

## Question 1

After understanding how to use exactly the _write_ function with _STDOUT_FILENO_, writing the welcome message was pretty easy. The most difficult part in question 1 was the prompt and understanding that we had to write a while loop to display it (_while (1)_ to be precise).

## Question 2

First, we had to download _fortune_ and _date_, because if not, we could not check if our code was correct. Then, in order to execute a command and return it to the prompt, we had to read the input in the console and to execute it (by using _execlp_, which was not so easy to understand) in the son process _(pid == 0)_. Our main mistake was in fact a misunderstanding : _fortune_ and _date_ were not the only commands, we had to adapt the code for any possible command (by using _console_input_).

## Question 3

We had to compare the shell output and the user command (using _strcmp_) and if the user wrote "exit" in the terminal, the shell is shut. We did not have any particular problem with this question, what took us the longest was to find how to exit the shell (with the code line : _exit(EXIT_SUCCESS)_).

## Question 4

To answer this question, we had to use _WIFEXITED_ and _WIFSIGNALED_ functions in the father process (_pid>0_).
* _WIFEXITED(status)_ is true if the child has ended normally ; _WEXITSTATUS(status)_ displays the output value of the child.
* _WIFSIGNALED(status)_ is true if the child has ended because of a signal ; _WTERMSIG(status)_ displays the signal number which has caused the end of the child.

We had several difficulties for this question :
* The function _printf_ does not work well with _read_ and _write_ so we had to change it by _sprintf_ ;
* We realized that our buffer size was too small to enable the code to run, so we had to change it (to 24 from 512) ;
* _sizeof_ did not work as well, we had to change it by _strlen_.

## Question 5 

To answer this question, we had to learn how to use the _clock_gettime_ function (with _CLOCK_REALTIME_, _&start_ and _&stop_). This question also reminded us how to create a structure with _struct_. What caused us a problem is the fact that because the time was in ms, _stop.tv_sec_ and _start.tv_sec_ were equal to zero. We had to work only with _stop.tv_nsec_ and _start.tv_nsec_. Besides, the definition of the time was not obvious (time=(_stop.tv_nsec-start.tv_nsec_)).

## Question 6

This question enabled us to have several reminders of our C language course :
* The memory allocation (with _free_, _realloc_ and _malloc_) ;
* The use of _strcpy(a,b)_ which pastes b in a.

But this question was also tricky, we had several problems with :
* Using memory allocation : it was not obvious, we thought at the beginning that we can answer the question without using it ;
* Differentiating which pointer was simple and which one was a double pointer ;
* Realizing that we had to change _execlp_ in _execvp_ since we had an argument array ;
* Understanding the use of _splitter_ (which splits the arguments (token) when the following character is encountered) and _strtok_ (which extracts, one by one, each token of a string).
