class Solution {
public:
     vector<int> numSmallerByFrequency(std::vector<std::string>& queries, std::vector<std::string>& words) {
        std::vector<int> flscq;
        std::vector<int> flscw;

        for (const auto& x : queries) {
            int frequency = std::count(x.begin(), x.end(), *std::min_element(x.begin(), x.end()));
            flscq.push_back(frequency);
        }

        for (const auto& x : words) {
            int frequency = std::count(x.begin(), x.end(), *std::min_element(x.begin(), x.end()));
            flscw.push_back(frequency);
        }

        std::vector<int> result;
        for (int fq : flscq) {
            int count = std::count_if(flscw.begin(), flscw.end(), [fq](int fw) {
                return fq < fw;
            });
            result.push_back(count);
        }

        return result;
    }
};
