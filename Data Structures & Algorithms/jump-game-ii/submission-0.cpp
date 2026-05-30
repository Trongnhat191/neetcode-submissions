class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0; // Nếu mảng chỉ có 1 phần tử, bạn đã ở đích rồi, mất 0 bước nhảy.

        int jumps = 0;
        int current_end = 0;
        int max_reach = 0;

        // Chạy đến n - 2 vì ta không cần nhảy khi đã đứng ở ô cuối cùng
        for (int i = 0; i < n - 1; i++) {
            // Luôn tham lam cập nhật điểm xa nhất có thể đạt được cho lượt sau
            max_reach = max(max_reach, i + nums[i]);

            // Khi đã đi hết phạm vi của bước nhảy hiện tại
            if (i == current_end) {
                jumps++;                 // Bắt buộc phải nhảy thêm 1 bước
                current_end = max_reach; // Cập nhật biên giới mới cho cửa sổ tiếp theo

                // Tối ưu dừng sớm: Nếu biên mới đã bao phủ được hoặc vượt qua đích, dừng luôn
                if (current_end >= n - 1) {
                    break;
                }
            }
        }

        return jumps;
    }
};