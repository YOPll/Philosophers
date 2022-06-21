# Philosophers
<p align="center">
<a href="https://github.com/YOPll/get_next_line">
  <img src="https://user-images.githubusercontent.com/49567393/145694296-91b27fdf-3666-4670-8a84-23695c2be1a4.png" alt="ft_printf 100/100">
</a>
  <br>
  125/100
</p>

## Introduction to Philosophers

This project focuses on solving the dining philosophers problem - in computer science it is an example problem often used in concurrent algorithm design to illustrate synchronization issues and techniques for resolving them.


* One or more philosophers are sitting at a round table either eating, either thinking, either sleeping. While they are eating, they do not think or sleep; while thinking they don’t eat or sleep; and, of course, while sleeping, they do not eat or think.
* The philosophers sit at a circular table with a large bowl of spaghetti in the center.
* There are some forks on the table. Serving and eating spaghetti with a single fork is very inconvenient, so the philosophers will eat with two forks, one for each hand.
* Each time a philosopher finishes eating, they will drop their forks and start sleeping. Once they have finished sleeping, they will start thinking. The simulation stops when a philosopher dies.
* Every philosopher needs to eat and they should never starve.
* Philosophers don’t speak with each other.
* Philosophers don’t know when another philosopher is about to die.
* Philosophers avoid death.
* Each philosopher is thread.
* One fork between each philosopher, therefore if they are multiple philosophers, there will be a fork at the right and the left of each philosopher.
* To avoid philosophers duplicating forks, there is forks state protection with a mutex for each of them.
* Any change of status of a philosopher will be written as follows (with X replaced with the philosopher number and timestamp_in_ms the current timestamp in milliseconds):
  * timestamp_in_ms X some_action

[SUBJECT](Subject/en.subject.pdf)

### Requirements & usage
Project requires:
* C Lang compiler: **gcc** or **clang**
* Possibility to work with Makefile

### Ressources

* [Parallel Computing](https://computing.llnl.gov/tutorials/parallel_comp/)
* [POSIX Threads](https://computing.llnl.gov/tutorials/pthreads/) ([pthread routines](https://computing.llnl.gov/tutorials/pthreads/#AppendixA))
* [Working example](https://timmurphy.org/2010/05/04/pthreads-in-c-a-minimal-working-example/)
* [Semaphores in C](http://greenteapress.com/thinkos/html/thinkos012.html)
* [fork() example](https://timmurphy.org/2014/04/26/using-fork-in-cc-a-minimum-working-example/)
* [fork() multiple childs](https://stackoverflow.com/questions/876605/multiple-child-process)
* [Semaphore when programs end](https://stackoverflow.com/questions/9537068/sem-close-vs-sem-unlink-when-process-terminates)
