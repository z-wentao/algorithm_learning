/*
对于一个节点x， 如果我们把它从树中删除，那么原来的一棵树可能会分成若干个不相连的部分，
其中每一部分都是一颗子树。
设 max_part(x) 表示在删除节点 x 后产生的子树中， 最大的一棵的大小。 使 max_part 函数取到
最小值的节点 p 就称为整棵树的重心。
*/
void dfs(int x) {
    v[x] = 1; size[x] = 1;  // 子树 x 的大小
    int max_part = 0;       // 删掉 x 后分成的最大子树的大小
    for (int i = head[x]; i; i = next[i]) {
        int y = ver[i];
        if (v[y]) continue; // 点 y 已经被访问过了
        dfs(y);
        size[x] += size[y]; // 从子节点向父节点递推
        max_part = max(max_part, size[y]); 
    }
    max_part = max(max_part, n - size[x]); // n 为整棵树的节点数目
    if (max_part < ans) {   
        ans = max_part;     // 全局变量 ans 记录重心对应的max_part
        pos = x;            // 全局遍历 pos 记录了重心
    }
}