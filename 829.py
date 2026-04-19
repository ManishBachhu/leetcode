def consecutiveNumbersSum(self, N):
    count = 0
    for i in range(1, int(math.sqrt(N))+1):
        if N%i == 0:
            if i%2:
                count += 1
            if (N/i)%2 and N/i != i:
                count += 1
    return count

"""
Reasoning:
Say the sum of x, x+1, x+2, ..., x+k is N, the sum can be rewritten in
(x + (x+k)) * (k + 1) / 2 = N, and we are looking for all integer pairs x and k that can satisfy this equation.
The left hand side can be rearranged to
((2x + k) / 2) * (k + 1) = N or (2x + k) * (k + 1) / 2 = N which we can further simplify to
(x + k/2) * (k + 1) = N or (2x + k) * ((k + 1) / 2) = N. This is where the magic happens:

Observe that

when k is an even number, k+1 will be an odd number. And because (x + k/2) * (k + 1) = N we know that (x + k/2) * odd = N.
when k is an odd number, 2x+k will be an odd number. And because (2x + k) * ((k + 1) / 2) = N we know that odd * ((k + 1) / 2) = N.
What this means is that the left hand of the equation will always have an odd multiplier. So far we have proved that for every x and k pair that we are looking for, one of the multiplier on the left hand side is an odd factor of N. Now we need to prove that for every odd factor of N, we can have a integer solution for x and k:

when k is an even number and k+1 is the odd factor of N. Then (x + k/2) * odd = N and x + k/2 = N / odd factor. Since k is even x + k/2 will be an integer and therefore solvable.
when k is an odd number and 2x+k is the odd factor of N. Then odd* ((k + 1) / 2) = N and (k + 1) / 2 = N / odd factor. Since k is odd k + 1 will be even and (k + 1) / 2 will be an integer and therefore solvable.
Now we have proven that the number of x and k pairs such that (x + (x+k)) * (k + 1) / 2 = N is the exact number of N’s odd factors.
"""
