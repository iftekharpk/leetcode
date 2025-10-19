class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        queue<string> q;
        unordered_set<string> visited;
        string smallest = s;

        q.push(s);
        visited.insert(s);

        while (!q.empty()) {
            string curr = q.front();
            q.pop();

            // সর্বনিম্ন string track রাখো
            smallest = min(smallest, curr);

            // \U0001f539 1. Add operation (odd indices এ a যোগ)
            string added = curr;
            for (int i = 1; i < added.size(); i += 2) {
                added[i] = (added[i] - '0' + a) % 10 + '0';
            }

            // \U0001f539 2. Rotate operation (right rotate by b)
            string rotated = curr.substr(curr.size() - b) + curr.substr(0, curr.size() - b);

            // \U0001f539 নতুন দুইটা অবস্থা check করো
            if (!visited.count(added)) {
                visited.insert(added);
                q.push(added);
            }
            if (!visited.count(rotated)) {
                visited.insert(rotated);
                q.push(rotated);
            }
        }

        return smallest;
    }
};
