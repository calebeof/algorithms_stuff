def ackermann(m, n):
  if m==0:
    return n+1
  elif n==0:
    return ackermann(m-1, 1)
  else:
    return ackermann(m-1, ackermann(m,n-1))

n = int(input())
for i in range(0, n):
  a,b = [int(x) for x in input().split()]
  print(ackermann(a,b))

'''
TIPS: 
- Ackermann Function grows fast, Ackermann (4,2) has 19729 digits.
- Find some patterns in each m.
- Memoize the cases.
- There are too many recusive calls, so the stack of the compiler will not do it efficiently. Try iterative in some cases (not possible with all).
'''
