# CP-Trees
This a repo for solving CP problems related to Trees
-------------------------------------------------------
The segment trees is a data structure for range based queries + updates

There are three opertions you need to do:
- Build -> buiding the tree using array ( because you will devide the array, the two halves have the same size ). also the index of the nodes will be from the top to the buttom and that's to maintain the relationship between the suns and their parent ( 2i/2i+1 ). The size will go till (4*n)+1. To build your first tree check that code [tree to find min valus](./main/10-BuildTreeMIn.cpp)
- Query
- Update
