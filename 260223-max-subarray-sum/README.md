# Find Max Subarray Sum

> From issue \#445 of rendezvous with cassidoo - 23 February 2026

## Question

Given an array of integers, find the contiguous subarray that has the largest sum and return that sum. A subarray must contain at least one element. If all elements are negative, return the largest (least negative) value. If you need a hint, look up Kadane's Algorithm!

Examples:

```
> maxSubarraySum([-2, 1, -3, 4, -1, 2, 1, -5, 4])
6
> maxSubarraySum([5])
5
> maxSubarraySum([-1, -2, -3, -4])
-1
> maxSubarraySum([5, 4, -1, 7, 8])
23
```

## Approach
1. set the `cur_sum`and `max_sum` with `numbers[0]`
2. loop from begin to end of the array and do this:
    - compare the value of `cur_sum + numbers[i]` with `numbers[i]` and set the `cur_sum` with the bigger one between the two. *why this logic?* because, if the later is bigger, ain't no way the first option + the rest of the number will be bigger than the later option + the rest of the number

        `(100 + x) will always bigger than (1 + x)`    *with x = the rest of the number*

        Thus, we should reset the "pivot" number to `numbers[i]`

    - update the `max_sum` with `cur_sum` if `cur_sum` is bigger than `max_sum`


## Complexity

Time Complexity: O(n)  
Space Complexity: O(1)

## Note
Nothing special tbh