class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) 
    {
        vector<vector<bool>> ispre(numCourses, vector<bool>(numCourses, false));
        vector<vector<int>> g(numCourses);
        vector<int> ans, indgree(numCourses);
        for (auto &pre: prerequisites) {
                       g[pre[0]].push_back(pre[1]);

            ispre[pre[0]][pre[1]] = true;

            indgree[pre[1]]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (indgree[i] == 0)
                q.push(i);
        }
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            ans.push_back(cur);
            for (auto nc: g[cur]) {
                 for (int i = 0; i < numCourses; ++i) {
               if(ispre[i][cur]) ispre[i][nc]=true;
        }
                if (--indgree[nc] == 0) {
                    q.push(nc);
                }
            }
        }
        vector<bool> res;
        for (auto &qurey: queries) {
            res.push_back(ispre[qurey[0]][qurey[1]]);
        }
        return res;
}

    };
