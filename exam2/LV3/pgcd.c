/**
 * @note pgcd => highest(grand) common denominator 最大公因数
 * while (a != b)
 * {
 * 	 CHECK WHICH IS BIGGER -> BIGGER - SMALLER [on repeat]
 * }
 * 
 */
#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b)
{
	while (a != b)
	{
		if (a > b)
			a = a - b;
		else
			b = b - a;
	}
	// When nbr1 == nbr2, they are both the GCD of the original numbers
	return (a);
}

int main(int ac, char *av[])
{
	if (ac == 3)
	{
		printf("%i", gcd(atoi(av[1]), atoi(av[2])));
	}
	printf("\n");
	return (0);
}


/*
### Example: Finding the GCD of 48 and 18

- Initial values: `nbr1 = 48`, `nbr2 = 18`.

```c
gcd(48, 18)
```

1. **First Iteration**:
   - `nbr1 = 48`, `nbr2 = 18`.
   - `nbr1 > nbr2`, so subtract `nbr2` from `nbr1`:  
     `nbr1 = 48 - 18 = 30`.

2. **Second Iteration**:
   - `nbr1 = 30`, `nbr2 = 18`.
   - `nbr1 > nbr2`, so subtract `nbr2` from `nbr1`:  
     `nbr1 = 30 - 18 = 12`.

3. **Third Iteration**:
   - `nbr1 = 12`, `nbr2 = 18`.
   - Now, `nbr2 > nbr1`, so subtract `nbr1` from `nbr2`:  
     `nbr2 = 18 - 12 = 6`.

4. **Fourth Iteration**:
   - `nbr1 = 12`, `nbr2 = 6`.
   - `nbr1 > nbr2`, so subtract `nbr2` from `nbr1`:  
     `nbr1 = 12 - 6 = 6`.

5. **Final Step**:
   - Now, `nbr1 = 6` and `nbr2 = 6`, so they are equal.
   - The loop ends, and the function returns `6`.

### Result:
The GCD of 48 and 18 is `6`.

### Breakdown of the Iterations:
|-----------|--------|--------|--------------------------|
| Iteration | `nbr1` | `nbr2` | Larger number subtracted |
|-----------|--------|--------|--------------------------|
| Initial   | 48     | 18     | 48 - 18 = 30             |
| 1st       | 30     | 18     | 30 - 18 = 12             |
| 2nd       | 12     | 18     | 18 - 12 = 6              |
| 3rd       | 12     | 6      | 12 - 6 = 6               |
| End       | 6      | 6      | Loop ends, GCD is 6      |
|-----------|--------|--------|--------------------------|

This shows how the function gradually reduces the numbers by subtracting, 
keeping the GCD the same, until both numbers become equal.
*/