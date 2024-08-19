# CP-Trees
-------------------------------------------------------
## Baics
----------
The segment trees is a data structure for range based queries + updates

There are three opertions you need to do:
### 1. Build:
buiding the tree using array ( because you will devide the array, the two halves have the same size ). also the index of the nodes will be from the top to the buttom and that's to maintain the relationship between the suns and their parent ( 2i/2i+1 ). The size will go till (4*n)+1. To build your first tree check that code [tree to find min valus](https://github.com/fatnaoui/CP-Trees/blob/main/10-BuildTreeMIn.cpp)
### 2. Query: 
There are three cases:
 - complete overlap -> when the input range match the node range, then your return the node
 - partial overlap -> when you range is intersection with the code range, then you return (min,max ...) of both sides
 - no overlap -> when there is no intersection between the node range, then you return infinit, or 0 depends on the problem
 - Check the new code after adding the query function [Query code](https://github.com/fatnaoui/CP-Trees/blob/main/11-QueryTreeMIn.cpp)
  
### 3. Update:
if you wanna update an element in the array that's will end up by doing a change in the tree, you can do that by using recursion. Check the update implementation here [update function](https://github.com/fatnaoui/CP-Trees/blob/main/12-UpdateTreeMIn.cpp). The final code with [update range funcition](https://github.com/fatnaoui/CP-Trees/blob/main/13-UpdateRangeTreeMIn.cpp)

These three operations have in total (nlog(n)log(n)) in time comlexity
 - n -> for building
 - log(n) -> for queries
 - log(n) -> for updating
## Lazy Propagation
-------------------
### 1. Updating A Range:
- When updating a point, it will take log(n) where n is the total number of the element
- When updating a range of size k using update range in the previous code, it will take k*log(n)
- What if we want to decrease the complexity of the search by optimizing k. Here comes the Lazy concept that keep track of the change without going deeper in log(k)*log(n) in time complexity [Update Using Lazy Propagation](https://github.com/fatnaoui/CP-Trees/blob/main/14-UpdatingRangeLazy.cpp)
  
