explanation about sync question:

2_1_1- deadloc:.
for making deaadlock we changed the function 'test'.
we determine that every philosopher must take left fork first and then right fork. all philosophers took their left fork and then try to reach the right fork but he was taken by other philosopher in that way we have a deadlock.
for doing it we add array of forks that represent for every fork which philosopher is holding it.

2_1_2 - preventing deadlock:
if we want to prevent deadlock we can play with the way philosophers taking forks to eat - which fork they took first.
only odd philosophers start left-hand first, and even philosophers start right-hand first. This does not deadlock, even if you put a delay in between pickup up chopsticks one and two.
in this way we have deadlock free (but may have starvation).

2_2_1 - starvation:
for making starvation we let all philosophers except of philosopher number 4 to take the left fork first and then the right fork(number 4 take right and then left).
in this way we have starvation because number 4 is trying to reach fork that already holded by someone else and because of that he starves.

2_2_2- preventing starvation:
for preventing starvation we implement the code that way that every philosopher after using a reasource (taking fork etc) can't obtain it right after releasing it , he must wait(we used sleep) some time before trying to acquire the fork again. in this way the philosopher that starved now got a chance.

2_3_1 livelock:
for making livelock we give all phillosophers the left fork , and after everyone getting the left fork they  tried to take the right fork(that was already taken).
after the philosophers didn't reach to the right fork they all put down their fork , sleep and then start from the beggining- lefft fork , try to take right , put down etc...

2_3_2 preventing livelock:
for preventing livelock even philosophers took left fork and then right fork , odd philosophers do the opposite , we also add sleep after philosophers trying to eat /eating.


note: the original code is prone to deadlock, although on this system we really won't ever see it because of the of timeslicing between threads .
 The only time that this solution is a problem is if a philosopher's thread gets preempted between picking up the first and the second mutex. That doesn't really ever happen to us when we checked it.