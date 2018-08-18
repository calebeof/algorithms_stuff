def bubbleSort(vector):
  for i in range (0, n-1):
    swapped = False
    for i in range (0, n-1):
      if (vector[i]>vector[i+1]):
        vector[i], vector[i+1] = vector[i+1], vector[i]
        swapped = True
    if swapped == False:
      break
  return vector

n = int(input('Write the number of numbers that you want to put in order: \n'))
array = []
for i in range(0,n):
  num = int(input())
  array.append(num)
print(bubbleSort(array))
