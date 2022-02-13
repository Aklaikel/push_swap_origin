import itertools
import subprocess

c = itertools.permutations("12345", 5)
for i in c:
        p1 = subprocess.getoutput(f"./push_swap {' '.join(i)} | ./checker_Mac {' '.join(i)}")
        p2 = subprocess.getoutput(f"./push_swap {' '.join(i)} | wc -l")
        print(p1 + ": " + p2)