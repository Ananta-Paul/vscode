import platform
platform.architecture() 
import sys 
sys.maxsize 
print(sys.maxsize) 
a = 2**63-1 
print(a) 
'''import math 
a = 2**63-1 
for num in range(2, a): 
 
 if num > 1: 
 for i in range(2, num): 
 if (num % i) == 0: 
 break 
 else: 
 print(num)'''