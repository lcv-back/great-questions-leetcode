# Application 1: Product Distribution Optimization

## 🎯 Mục tiêu của hệ thống phân phối:

Trong một hệ thống E-commerce lớn (như Tiki, Shopee, Amazon), sản phẩm thường được **lưu trữ tại nhiều kho hàng** để phục vụ nhanh các khu vực khác nhau. Mục tiêu là:

- Tối đa hóa khả năng phục vụ đơn hàng.
- Tối ưu hoá tồn kho giữa các kho để **giảm chi phí lưu kho và giao hàng**.
- Đảm bảo rằng kho nào cũng có hàng phù hợp, tránh thừa/thiếu cục bộ.

---

## 🧠 Liên hệ với bài toán XOR:

### 🗺️ Mô hình hóa:

| Thành phần thực tế            | Tương ứng trong bài toán                       |
| ----------------------------- | ---------------------------------------------- |
| Các kho hàng                  | Các node trong cây                             |
| Đường vận chuyển nội bộ       | Các cạnh trong cây                             |
| Số lượng hàng hóa trong kho   | `nums[i]` (giá trị tại mỗi node)               |
| Điều chuyển hàng hóa giữa kho | XOR thao tác: thay đổi trạng thái cả hai kho   |
| Giá trị sản phẩm khi chuyển   | `nums[i] ^ k` → mô phỏng chi phí/lợi nhuận mới |
| Mục tiêu                      | Tổng số lượng/lợi ích cao nhất sau điều phối   |

### 📦 Diễn giải thao tác XOR:

Giả sử `k = 3`, và `nums[i] = 5`:

- `nums[i] ^ k = 5 ^ 3 = 6` ⇒ nghĩa là **sau khi điều phối**, hàng hóa tại kho có trạng thái mới (tăng hoặc giảm), phản ánh **sự chuyển dịch, chi phí hoặc hiệu suất mới**.

---

## 🧮 Tình huống cụ thể:

### Giả sử:

- **Có 5 kho hàng** nối nhau theo cây:

  ```
      0
     / \
    1   2
        |
        3
        |
        4
  ```

- `nums = [10, 15, 12, 8, 7]`: số lượng hàng hóa ban đầu tại các kho.

- `k = 5`: mô hình hóa chi phí / thay đổi trạng thái khi chuyển hàng giữa hai kho.

- `edges = [[0,1],[0,2],[2,3],[3,4]]`: mô hình kết nối thực tế giữa kho.

---

### 🚀 Mục tiêu:

- **Điều chuyển hàng giữa các kho (qua các cạnh)** sao cho:

  - Các kho đạt trạng thái mới (sau XOR với `k` nếu cần).
  - Tổng số lượng hoặc giá trị **sau điều chuyển là cao nhất**.

---

## 🔍 Tại sao lại cần bài toán này?

Trong thực tế:

- Việc điều phối hàng hoá từ kho này sang kho khác có chi phí, rủi ro, nhưng cũng có thể tăng khả năng phục vụ đơn hàng.
- Một số kho gần khu vực đông dân hoặc có chi phí lưu kho rẻ hơn.
- Việc quyết định nên **chuyển gì, chuyển ở đâu, và chuyển bao nhiêu** chính là bài toán tối ưu – tương đương **chọn tập các thao tác XOR giữa các node** để đạt tổng lớn nhất.

---

## ✅ Lợi ích khi ứng dụng:

| Lợi ích thực tế                            | Đạt được nhờ bài toán                             |
| ------------------------------------------ | ------------------------------------------------- |
| Giảm hàng tồn ở kho thừa, tăng ở kho thiếu | Bằng cách chọn các thao tác XOR mang lại lợi ích  |
| Giảm chi phí vận hành kho                  | Giữ hàng ở kho tối ưu (theo vùng hoặc chi phí)    |
| Tăng tốc độ xử lý đơn hàng                 | Nhờ phân bổ hàng phù hợp vị trí nhu cầu           |
| Linh hoạt trong vận chuyển, phân phối      | Cho phép "đảo trạng thái" giữa 2 kho được kết nối |

---

## 🔧 Tích hợp trong hệ thống E-commerce:

1. **Phân tích tồn kho định kỳ:**

   - Hệ thống chạy thuật toán này mỗi tối hoặc mỗi vài giờ.

2. **Mô phỏng giá trị điều chuyển:**

   - Mỗi kho có giá trị sản phẩm khác nhau (do phí, tốc độ bán,...), thuật toán sẽ đánh giá và tối ưu.

3. **Tạo đề xuất điều phối tự động:**

   - Output từ bài toán là: "nên điều phối từ kho A đến kho B các mặt hàng X, Y để tối ưu tổng giá trị."
