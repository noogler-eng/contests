// Partition dp
// intution - 
// (1 + 2 + 3) * (5)
// (1 + 2) * (3 + 5)
// ......

// different set of rules
// we have a choice to solve which portion
// we can make group

// certain rules 
// 1. starts with entire block / array (i -> start, j -> end)
// 2. try all partition (run a loop to try out all partition)
// 3. return the best 2 partition possible
