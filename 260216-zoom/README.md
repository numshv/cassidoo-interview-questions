# Zoom 2D Grid by Factor K

> From issue \#444 of rendezvous with cassidoo - 16 February 2026

## Question

You have a 2D grid of numbers. Write a function that zooms in by an integer factor k >= 2 by turning each cell into a k x k block with the same value, returning the bigger grid.

Examples:
```
zoom([[1,2],[3,4]], 2)
[
  [1,1,2,2],
  [1,1,2,2],
  [3,3,4,4],
  [3,3,4,4]
]

zoom([[7,8,9]], 3)
[
  [7,7,7,8,8,8,9,9,9],
  [7,7,7,8,8,8,9,9,9],
  [7,7,7,8,8,8,9,9,9]
]

zoom([[1],[2]], 3)
[
  [1,1,1],
  [1,1,1],
  [1,1,1],
  [2,2,2],
  [2,2,2],
  [2,2,2]
]
```

## Approach

1. Extract input to 2D vector of int `vector<vector<int>>`
2. Pass by reference the input 2D vector and zoom factor to `zoom()` function
3. Initialize the result matrix with its size = original size * zoom factor
`vector<vector<int>> result(n * zoom_factor, vector<int>(m * zoom_factor));`
4. Manually loop to fill it while expanding each character `zoom_factor` time both horizontally and vertically
5. Return the result
6. Print the result

## Complexity

Time Complexity: O(n * m * k²)  
Space Complexity: O(n * m * k²)

## Note
I thought if I return the result matrix as it is (not passing it through pointer or something like that), it'd make a copy (one locally in the zoom function scope and one in the global scope after passed through as a result). Well, apparently that's not how it works. Turns out there's this thing called 

✨ **RVO (Return Value Optimization)** ✨

Where the compiler basically directly build the returned value in the destination location . Thus, there's no copy and memory duplication.