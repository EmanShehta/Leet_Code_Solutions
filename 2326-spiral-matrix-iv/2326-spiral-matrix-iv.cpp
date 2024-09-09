/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
   vector<std::vector<int>> spiralMatrix(int m, int n, ListNode* head) {
    std::vector<std::vector<int>> matrix(m, std::vector<int>(n, -1));  // تهيئة المصفوفة بالقيمة -1

    int top = 0, bottom = m - 1, left = 0, right = n - 1;  // تحديد الحدود
    ListNode* current = head;

    while (top <= bottom && left <= right) {
        // التحرك من اليسار لليمين في الصف العلوي
        for (int i = left; i <= right; ++i) {
            if (current) {
                matrix[top][i] = current->val;
                current = current->next;
            }
        }
        ++top;

        // التحرك من الأعلى لأسفل في العمود اليمين
        for (int i = top; i <= bottom; ++i) {
            if (current) {
                matrix[i][right] = current->val;
                current = current->next;
            }
        }
        --right;

        if (top <= bottom) {
            // التحرك من اليمين لليسار في الصف السفلي
            for (int i = right; i >= left; --i) {
                if (current) {
                    matrix[bottom][i] = current->val;
                    current = current->next;
                }
            }
            --bottom;
        }

        if (left <= right) {
            // التحرك من الأسفل لأعلى في العمود اليسار
            for (int i = bottom; i >= top; --i) {
                if (current) {
                    matrix[i][left] = current->val;
                    current = current->next;
                }
            }
            ++left;
        }
    }

    return matrix;
}
};
auto init = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();