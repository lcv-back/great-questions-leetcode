# Application 3: Ad Budget Allocation

## 🎯 **Ad Budget Allocation là gì?**

**Ad Budget Allocation** là quá trình quyết định **phân bổ ngân sách quảng cáo hợp lý** cho các danh mục, nhóm sản phẩm hoặc chiến dịch sao cho:

- Tối đa hóa hiệu quả quảng cáo (lợi nhuận, lượt click, đơn hàng,...).
- Tối ưu chi phí (không lãng phí ngân sách vào nhóm không hiệu quả).
- Đảm bảo cân bằng giữa các nhóm sản phẩm/đối tượng.

---

## 📦 **Trong hệ thống E-commerce**, ngân sách quảng cáo được phân bổ cho:

| Mục tiêu quảng cáo                | Ví dụ cụ thể                       |
| --------------------------------- | ---------------------------------- |
| Theo nhóm sản phẩm                | Điện thoại, quần áo, mỹ phẩm, v.v. |
| Theo chiến dịch (Flash sale, 9.9) | Ngân sách cho các ngày lễ lớn      |
| Theo khu vực địa lý               | TP.HCM, Hà Nội, Đà Nẵng,...        |
| Theo người dùng mục tiêu          | Nhóm khách hàng VIP, sinh viên,... |

---

## 💡 **Tại sao cần tối ưu ngân sách?**

Vì ngân sách luôn hữu hạn, nhưng hiệu quả quảng cáo **khác nhau giữa các nhóm**, ta cần:

- Phân bổ tiền vào nơi tạo ra nhiều lợi nhuận/đơn hàng nhất.
- Hạn chế chi tiêu vào nhóm không hiệu quả.
- Tự động tái phân bổ ngân sách khi chiến dịch diễn ra.

---

## 🔄 **Liên hệ với bài toán XOR trên cây:**

### 🧠 Mô hình:

| Thành phần thực tế                | Trong bài toán cây XOR                                    |
| --------------------------------- | --------------------------------------------------------- |
| Các nhóm quảng cáo                | Các đỉnh (nodes)                                          |
| Mối liên hệ giữa nhóm quảng cáo   | Các cạnh (edges) → cùng nhóm chiến dịch/sản phẩm liên kết |
| Ngân sách hoặc hiệu quả quảng cáo | `nums[i]` → giá trị hiện tại của nhóm                     |
| Điều chỉnh ngân sách              | XOR mô phỏng việc tăng/giảm ngân sách đồng thời 2 nhóm    |
| Mục tiêu                          | Tối đa hóa tổng hiệu quả quảng cáo sau tái phân bổ        |

---

## 📈 Tình huống minh hoạ:

Giả sử:

- **5 nhóm quảng cáo** liên kết như cây:

  ```
      Campaign A
         |
      Product 1
         |
      Product 2
         |
      Product 3 -- Product 4
  ```

- `nums = [100, 60, 70, 40, 30]` → ROI (return on ad spend) của từng nhóm.

- `k = 20` → mô hình hoá thay đổi ngân sách, ví dụ như **di chuyển 20% ngân sách từ nhóm này sang nhóm kia**.

- Thao tác XOR mô phỏng việc **cân bằng ngân sách giữa 2 nhóm**.

---

## 📌 Ý tưởng tối ưu:

- Bạn **không thể thay đổi một nhóm đơn lẻ** — bạn chỉ được "cân bằng lại" giữa 2 nhóm liên kết (đảm bảo ràng buộc chiến dịch hoặc khu vực).
- Mỗi thao tác chỉ thay đổi 2 nhóm → tổng số nhóm bị ảnh hưởng phải là **số chẵn**.
- Mục tiêu: chọn các cặp nhóm liên kết để điều chỉnh ngân sách sao cho **tổng ROI là lớn nhất**.

---

## ⚙️ Tích hợp vào hệ thống E-commerce:

1. **Thu thập dữ liệu hiệu suất** quảng cáo hàng giờ/ngày (clicks, ROI, conversion).
2. **Biểu diễn các nhóm quảng cáo dưới dạng cây** (dựa trên mối liên hệ sản phẩm hoặc chiến dịch).
3. Chạy thuật toán giống bài toán XOR:

   - Xác định `gain[i] = (nums[i] ^ k) - nums[i]`
   - Tìm cặp nhóm nên đổi ngân sách để có lợi nhất.

4. **Cập nhật ngân sách qua API** của các nền tảng như Google Ads, Meta Ads.

---

## ✅ Lợi ích khi ứng dụng:

| Lợi ích                         | Mô tả                                                                 |
| ------------------------------- | --------------------------------------------------------------------- |
| Tăng hiệu quả chi tiêu          | Dồn tiền vào nhóm đang có ROAS cao hơn                                |
| Giảm rủi ro                     | Không để một nhóm "đốt tiền" mà không ra đơn                          |
| Cân bằng giữa sản phẩm, khu vực | Duy trì sự hiện diện đều giữa các thị trường và ngành hàng            |
| Tự động hóa                     | Có thể chạy mỗi giờ/ngày để tái phân bổ thông minh mà không cần người |

---

## 📌 Tóm tắt ứng dụng bài toán vào Ad Budget Allocation:

| Thành phần                          | Tương ứng trong bài toán XOR                           |
| ----------------------------------- | ------------------------------------------------------ |
| Nhóm quảng cáo                      | Node trong cây                                         |
| Mối liên kết giữa nhóm (chiến dịch) | Edge                                                   |
| Hiệu suất/giá trị nhóm quảng cáo    | `nums[i]`                                              |
| Điều chỉnh ngân sách giữa 2 nhóm    | Thao tác XOR (tăng/giảm đồng thời)                     |
| Mục tiêu                            | Tối đa hoá tổng hiệu suất quảng cáo sau khi điều chỉnh |

---

## 🔧 Bạn có thể phát triển tiếp:

- Kết hợp thêm ràng buộc như giới hạn ngân sách tối đa/tối thiểu mỗi nhóm.
- Dùng thuật toán học máy để **dự đoán gain\[i]** thay vì tính thủ công.
- Giao diện dashboard cho marketing có thể xem đề xuất ngân sách tái phân bổ.
