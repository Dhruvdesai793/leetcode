/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* recursion(int startr, int endr, int starth, int endh, vector<vector<int>> &grid){

        Node* newNode = new Node();
        if(check(grid,startr, endr, starth, endh)){
            newNode->isLeaf = true;
            newNode->val = grid[startr][starth];
            return newNode;
        }
        
        newNode->topLeft = recursion(startr, (startr+endr) /2, starth, (endh+starth)/2 , grid);
        newNode->topRight = recursion(startr, (startr+endr)/2, (endh+starth)/2 +1, endh, grid);
        newNode->bottomLeft = recursion(((startr + endr)/2) + 1,endr, starth, (starth + endh)/2, grid );
        newNode->bottomRight = recursion((startr+endr)/2 +1, endr, (starth + endh)/2 + 1, endh, grid);

        return newNode;
    }
    Node* construct(vector<vector<int>>& grid) {
        

        return recursion(0,grid.size() -1, 0, grid.size()-1, grid );



        
    }
    // checking function.
    bool check(vector<vector<int>> & grid, int startr, int endr,int starth, int endh){
        int flag = grid[startr][starth];

        for(int i = startr; i<=endr; i++ ){
            for(int j = starth; j<=endh; j++){
                if(grid[i][j] != flag) return false;
            }
        }
        return true;
    }
};