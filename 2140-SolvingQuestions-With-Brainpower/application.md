# Solving Questions with Brainpower

Bài toán này thực chất là một bài toán về **lập trình động (Dynamic Programming)**, trong đó bạn cần tối ưu hóa việc lựa chọn giải quyết câu hỏi nào để đạt được điểm số tối đa mà không vi phạm các ràng buộc. Bài toán này có thể được áp dụng trong các tình huống thực tế như:

### Ứng dụng trong thực tế:

1. **Quản lý tài nguyên**: Trong nhiều tình huống thực tế, bạn cần đưa ra quyết định tối ưu hóa việc sử dụng tài nguyên. Ví dụ: nếu bạn là người quản lý dự án, bạn cần đưa ra quyết định xem bạn sẽ chọn nhiệm vụ nào để thực hiện (với tài nguyên có hạn) và nhiệm vụ nào nên bỏ qua.

2. **Lịch làm việc cá nhân**: Nếu bạn có một danh sách các công việc cần làm trong ngày (ví dụ như hoàn thành các bài kiểm tra, dự án, hoặc nhiệm vụ), mỗi công việc yêu cầu một lượng thời gian và năng lượng nhất định. Tuy nhiên, nếu bạn chọn làm một công việc, bạn có thể không làm được các công việc khác trong một khoảng thời gian sau đó. Mục tiêu là chọn những công việc tối ưu để đạt được kết quả tốt nhất trong thời gian có hạn.

3. **Quản lý chương trình đào tạo hoặc thi cử**: Trong trường hợp có nhiều câu hỏi thi, và bạn cần ra quyết định xem nên làm câu nào và bỏ qua câu nào để tối đa hóa điểm số, hoặc lựa chọn các khóa học hoặc bài học trong một chương trình đào tạo, với các quy tắc về thời gian và năng lượng cần thiết cho mỗi bài học.

4. **Game**: Trong các trò chơi chiến thuật, bạn phải đưa ra quyết định về việc làm nhiệm vụ nào trong trò chơi để đạt điểm cao nhất mà không làm ảnh hưởng đến khả năng hoàn thành các nhiệm vụ sau này. Đây cũng là một bài toán tối ưu hóa giống như trên.

### Lập trình:

Trong lập trình, bài toán này có thể được giải quyết bằng cách sử dụng **Dynamic Programming (DP)**, cụ thể là sử dụng một mảng `dp[]` để lưu trữ số điểm tối đa có thể đạt được từ mỗi câu hỏi đến cuối cùng. Cách tiếp cận này sẽ giúp bạn tối ưu hóa việc lựa chọn câu hỏi nào để giải quyết, đồng thời đảm bảo tuân thủ các ràng buộc của bài toán.

Cách giải quyết có thể được tóm tắt như sau:

1. **Khởi tạo một mảng DP**: Mỗi phần tử `dp[i]` sẽ lưu trữ điểm số tối đa có thể đạt được nếu bạn bắt đầu từ câu hỏi thứ `i`.
2. **Lặp qua từng câu hỏi**: Đối với mỗi câu hỏi, bạn có hai lựa chọn:
   - **Giải quyết câu hỏi**: Nếu bạn giải quyết câu hỏi, bạn sẽ nhận điểm và bỏ qua một số câu hỏi phía sau, tính toán lại điểm tối đa có thể đạt được từ câu hỏi tiếp theo sau khi bỏ qua các câu hỏi bị hạn chế.
   - **Bỏ qua câu hỏi**: Nếu bạn bỏ qua câu hỏi, bạn có thể giải quyết câu hỏi tiếp theo.
3. **Lưu kết quả tối ưu** vào mảng DP.

### Ví dụ mã Python để giải quyết bài toán:

```python
def mostPoints(questions):
    n = len(questions)
    dp = [0] * (n + 1)  # dp[i] will store the maximum points we can earn starting from question i

    # Traverse the questions in reverse order
    for i in range(n - 1, -1, -1):
        points, brainpower = questions[i]
        # Option 1: Skip this question
        dp[i] = dp[i + 1]
        # Option 2: Solve this question (and skip brainpower number of questions)
        dp[i] = max(dp[i], points + (dp[i + brainpower + 1] if i + brainpower + 1 < n else 0))

    # The answer is the max points starting from question 0
    return dp[0]

# Test example
questions = [[3, 2], [4, 3], [4, 4], [2, 5]]
print(mostPoints(questions))  # Output should be 7
```

### Giải thích mã:

- Mảng `dp[i]` lưu trữ điểm tối đa bạn có thể kiếm được nếu bắt đầu từ câu hỏi thứ `i`.
- Duyệt từ cuối mảng về đầu, tại mỗi câu hỏi bạn có hai lựa chọn:
  - **Bỏ qua câu hỏi đó**: Chỉ cần lấy điểm tối đa của câu hỏi kế tiếp (`dp[i + 1]`).
  - **Giải quyết câu hỏi đó**: Thêm điểm từ câu hỏi này (`points`) và sau đó tính điểm từ câu hỏi sau khi bỏ qua các câu hỏi bị hạn chế bởi `brainpower`.
- Cuối cùng, điểm tối đa bạn có thể nhận được là `dp[0]`, nghĩa là điểm tối đa bắt đầu từ câu hỏi đầu tiên.

### Kết luận:

Bài toán này có thể được áp dụng trong nhiều lĩnh vực thực tế như quản lý thời gian, dự án, và thậm chí trong các trò chơi. Việc sử dụng lập trình động giúp tối ưu hóa việc đưa ra các quyết định về việc giải quyết hay bỏ qua các câu hỏi để đạt được kết quả tốt nhất.
