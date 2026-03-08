# Find Max Subarray Sum

From issue [\#446](https://buttondown.com/cassidoo/archive/u1f6f5-the-way-to-right-wrongs-is-to-turn-the/) of rendezvous with cassidoo - 2 March 2026

## Question

Find the majority element in an array (one that appears more than n/2 times) in O(n) time and O(1) space without hashmaps. Hint: [the Boyer-Moore Voting algorithm](https://en.wikipedia.org/wiki/Boyer%E2%80%93Moore_majority_vote_algorithm?utm_source=cassidoo&utm_medium=email&utm_campaign=u1f6f5-the-way-to-right-wrongs-is-to-turn-the) might help if you can't figure this one out!

Examples:

```
> majorityElement([2, 2, 1, 1, 2, 2, 1, 2, 2])
2

> majorityElement([3, 3, 4, 2, 3, 3, 1])
3
```

## Approach

It's basically the implementation of **Boyer-Moore Voting Algorithm**. Here's the step by step of it.

Here's the function, and as you can see it receives one argument, `vector<int> &nums` which is a vector of element (in this case is integer)

`int majority_element(vector<int> &nums)`

1. Initiate a variable called `cur_major` that stores the current majority element and `cur_major_count` that stores the value of the `cur_major` (that later in the process will decide whether should we keep the value of `cur_major` or should we change it to another value/element) with `0`
2. Starts a loop that iterates through the input sequence of elements. Inside the loop, we check:
    1. if `cur_major_count == 0` -> set `cur_major` to the current element that we loop through and increment the value of `cur_major_count` 
    2. else:
        1. if `cur_major == current_looped_element` then we increment the value of `cur_major_count`
        2. else, we decrement the value of `cur_major_count`
3. The value/element stored inside `cur_major` after the loop finished will be the majority element inside the input sequence. And, even if there's not exactly one majority element, it will resulting in one of the majority element to be the answer of it.    



## Complexity

Time Complexity: O(n)  
Space Complexity: O(1)

## Note
When I first saw the name of the algorithm, I thought it was familiar. Turns out, I've heard the name "Boyer-Moore" from the Boyer-Moore algorithm for string matching, which was introduced in my Algorithm Strategy course last year! But alas, this one is actually different than the one that's for string matching purpose!