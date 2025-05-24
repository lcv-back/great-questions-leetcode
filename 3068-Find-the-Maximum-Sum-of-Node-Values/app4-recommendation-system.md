# Application 4: Recommendation System

## 📌 1. Recommendation System là gì?

**Recommendation System** là hệ thống gợi ý **cá nhân hóa sản phẩm hoặc nội dung** cho người dùng dựa trên:

| Nguồn dữ liệu             | Ví dụ                                                    |
| ------------------------- | -------------------------------------------------------- |
| Hành vi người dùng        | Lịch sử mua, xem, tìm kiếm, click, thêm vào giỏ hàng,... |
| Đặc điểm sản phẩm         | Giá, danh mục, thương hiệu, mô tả,...                    |
| Hành vi người dùng khác   | Người giống bạn mua gì, xem gì,...                       |
| Mối quan hệ giữa sản phẩm | Sản phẩm thường được mua chung hoặc so sánh với nhau     |

---

## 🎯 Mục tiêu của hệ thống:

- **Tăng tỷ lệ chuyển đổi (conversion rate)**.
- **Tăng giá trị đơn hàng (AOV - average order value)**.
- **Cải thiện trải nghiệm người dùng**.

---

## 🔄 Các loại hệ thống gợi ý phổ biến:

| Loại                        | Mô tả                                                            |
| --------------------------- | ---------------------------------------------------------------- |
| Content-based Filtering     | Dựa vào đặc điểm sản phẩm người dùng từng tương tác              |
| Collaborative Filtering     | Dựa vào hành vi của người dùng tương tự                          |
| Hybrid System               | Kết hợp cả hai phương pháp                                       |
| Knowledge-based Recommender | Dựa vào logic chuyên biệt (sản phẩm phù hợp mục đích người dùng) |

---

## 🧠 Liên hệ với bài toán XOR trên cây

Giả sử ta có:

- Mỗi **sản phẩm là một node**.
- Mỗi **mối quan hệ giữa sản phẩm** là một cạnh trong cây (ví dụ: "thường được mua chung").
- Mỗi node có một giá trị `nums[i]`: độ hấp dẫn, mức độ tiềm năng chuyển đổi, hay lợi nhuận kỳ vọng khi gợi ý.
- Mỗi thao tác XOR mô phỏng **điều chỉnh trọng số ưu tiên gợi ý giữa hai sản phẩm có liên kết**.

### 🎯 Mục tiêu:

Chọn các **cặp sản phẩm liên kết** để **điều chỉnh thứ tự/điểm ưu tiên gợi ý**, nhằm **tối đa hóa tổng giá trị hệ thống gợi ý** (tức là tăng chuyển đổi, doanh thu,...)

---

## 📦 Tình huống thực tế:

Giả sử:

```plaintext
Sản phẩm:
0: Điện thoại
1: Ốp lưng
2: Tai nghe
3: Củ sạc
```

- `nums = [100, 20, 40, 30]` → điểm ưu tiên ban đầu
- `k = 15` → điều chỉnh gợi ý 2 sản phẩm cùng lúc
- Cấu trúc cây:

```
       0
      / \
     1   2
          \
           3
```

→ Khi bạn quyết định tăng trọng số cho "tai nghe", có thể cần giảm trọng số "củ sạc" để tránh spam hoặc hạn chế hiển thị.

→ Bài toán XOR giúp bạn mô phỏng cách **điều chỉnh song song các sản phẩm liên quan** sao cho toàn bộ danh sách gợi ý đạt hiệu quả tối đa.

---

## ⚙️ Cách hệ thống triển khai thực tế:

1. **Xây dựng đồ thị liên kết sản phẩm**:

   - Từ dữ liệu: "thường được mua cùng", "cùng xem", "hay so sánh".
   - Tối ưu thành **cây hoặc DAG (đồ thị có hướng)** để xử lý hiệu quả.

2. **Tính điểm `nums[i]` cho từng sản phẩm**:

   - Dựa vào lịch sử tương tác, doanh thu, CTR, khả năng chuyển đổi,...

3. **Chạy thuật toán tối ưu gợi ý**:

   - Sử dụng logic bài toán XOR (có thể kết hợp với greedy hoặc DP) để **chọn ra các điều chỉnh tối ưu** trên cây gợi ý.

4. **Xuất danh sách gợi ý cá nhân hóa**:

   - Theo người dùng, danh mục sản phẩm, thời gian,...

---

## ✅ Lợi ích khi ứng dụng:

| Lợi ích                         | Mô tả                                                   |
| ------------------------------- | ------------------------------------------------------- |
| Tăng giá trị đơn hàng           | Gợi ý đúng sản phẩm người dùng dễ mua thêm              |
| Giảm chồng chéo sản phẩm        | Không gợi ý các sản phẩm quá giống hoặc không liên quan |
| Cải thiện tỷ lệ nhấp (CTR)      | Gợi ý chính xác sản phẩm đúng nhu cầu                   |
| Cân bằng hiệu quả toàn hệ thống | Dàn trải gợi ý để nhiều sản phẩm cùng được tiêu thụ     |

---

## 🔧 Tích hợp vào hệ thống E-commerce:

- Hệ thống gợi ý chạy **batch hàng giờ/ngày** hoặc **real-time API**.
- Sử dụng cây sản phẩm và thuật toán tối ưu (giống logic XOR trên cây) để cập nhật danh sách gợi ý liên tục.
- Kết hợp với học máy để dự đoán gain trước khi điều chỉnh.

---

## 📌 Tóm tắt ứng dụng bài toán XOR trong hệ thống gợi ý:

| Thành phần                | Tương ứng trong bài toán                              |
| ------------------------- | ----------------------------------------------------- |
| Sản phẩm                  | Node trong cây                                        |
| Mối liên hệ giữa sản phẩm | Edge trong cây ("thường mua cùng", "gợi ý liên kết")  |
| Điểm ưu tiên gợi ý        | `nums[i]`                                             |
| Điều chỉnh gợi ý          | Thao tác XOR giữa 2 sản phẩm                          |
| Mục tiêu                  | Tối ưu tổng điểm gợi ý cho toàn hệ thống hoặc cá nhân |
