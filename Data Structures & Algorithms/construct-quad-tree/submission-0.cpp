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
    Node* quadTree(vector<vector<int>>& grid, int startr, int endr, int startc, int endc) {
        int el = grid[startr][startc];
        bool flag = true;
        for (int i = startr; i <= endr; i++) {
            for (int j = startc; j <= endc; j++) {
                if (grid[i][j] != el) {
                    flag = false;
                    break;
                }
            }
            if (!flag) break;
        }
        if (flag) return new Node(el, true);
        Node* n = new Node(el, false);
        int midr = (startr + endr) / 2, midc = (startc + endc) / 2;
        n -> topLeft = quadTree(grid, startr, midr, startc, midc);
        n -> topRight = quadTree(grid, startr, midr, midc + 1, endc);
        n -> bottomLeft = quadTree(grid, midr + 1, endr, startc, midc);
        n -> bottomRight = quadTree(grid, midr + 1, endr, midc + 1, endc);
        return n;
    }

    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        return quadTree(grid, 0, n - 1, 0, n - 1);
    }
};