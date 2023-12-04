# Lab 1 : EnseaInShell

NGUYEN Denis and TESTUZ Lauriane 2G1TD2TP3

## Question 1

Writing the welcome message was pretty easy, the most difficult part in question 1 was the prompt, and understand that we had to write a while loop to display it (_while (1)_ to be precise).

## Question 2

First, we had to download _fortune_ and _date_, because if not, we could not check if our code was correct. Then, in order to execute a command and return it to the prompt, we had to read the input in the console and to execute it (by using _execlp_) in the son process _(pid = 0)_. Our main mistake was in fact a misunderstanding : _fortune_ and _date_ were not the only commands, we had to adapt the code for any possible command (by using _console_input_).

## Question 3

We have to compare the shell output and the user command (using _strcmp_) and if the user writes "exit" in the terminal, the shell is shut. We did not have any particular problem with this question, what took us the longest was to find how to exit the shell (with the code line : _exit(EXIT_SUCCESS)_).

## Question 4

To answer this question, we had to use _WIFEXITED_ and _WIFSIGNALED_ functions in the father process.
* _WIFEXITED(status)_ is true if the child has ended normally ; _WEXITSTATUS(status)_ displays the output value of the child
* _WIFSIGNALED(status)_ is true if the child has ended because of a signal ; _WTERMSIG(status)_ displays the signal number which has caused the end of the child

We had several difficulties for this question :
* The function _printf_ does not work well with _read_ and _write_ so we had to change it by _sprintf_
* We realized that our buffer size was too small to enable the code to run, so we had to change it (to 24 from 512)
* _sizeof()_ did not work as well, we had to chage it by _strlen()_*

## Question 5 
