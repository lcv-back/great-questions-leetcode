# Application2: Dynamic Pricing

## 🎯 **Dynamic Pricing là gì?**

**Dynamic Pricing** là chiến lược điều chỉnh giá **linh hoạt theo thời gian thực** dựa trên nhiều yếu tố như:

| Yếu tố ảnh hưởng       | Ví dụ cụ thể                                  |
| ---------------------- | --------------------------------------------- |
| Cung và cầu            | Giá tăng khi nhiều người tìm mua, giảm khi ế  |
| Hành vi người dùng     | Người hay mua đắt có thể bị “up giá”          |
| Giá đối thủ cạnh tranh | Giá được tự động điều chỉnh thấp hơn đối thủ  |
| Thời điểm              | Flash sale, lễ Tết, cuối tuần                 |
| Khu vực                | Giá ở Hà Nội có thể khác TP.HCM               |
| Lượng hàng tồn kho     | Hàng sắp hết → tăng giá; còn nhiều → giảm giá |

---

## 📦 **Ứng dụng thực tế trong E-commerce:**

| Hệ thống               | Dynamic Pricing hoạt động như thế nào                         |
| ---------------------- | ------------------------------------------------------------- |
| **Shopee/Lazada/Tiki** | Thay đổi giá theo giờ, theo tệp khách hàng, theo chương trình |
| **Grab/Gojek**         | Giá tăng giờ cao điểm (surge pricing)                         |
| **Amazon**             | Thay đổi hàng triệu giá mỗi ngày dựa trên thuật toán          |

---

## 🔁 **Quy trình vận hành Dynamic Pricing**:

1. **Thu thập dữ liệu**: đơn hàng, truy cập, tồn kho, giá đối thủ,...
2. **Tính toán giá tối ưu**: dựa trên mô hình (AI, heuristics, rule-based,...)
3. **Cập nhật giá tự động**: thông qua hệ thống backend API
4. **Theo dõi hiệu quả**: doanh thu, CTR, đơn hàng, tỷ lệ hủy,...

---

## 🔐 **Vai trò quan trọng của Dynamic Pricing:**

| Lợi ích                            | Tác động kinh doanh thực tế                       |
| ---------------------------------- | ------------------------------------------------- |
| Tối đa hóa lợi nhuận               | Bán đúng giá, đúng thời điểm                      |
| Tăng tính cạnh tranh               | Tự động phản ứng với giá của đối thủ              |
| Xả hàng nhanh chóng khi cần        | Giá thấp khi hàng tồn kho cao hoặc sắp hết hạn    |
| Cá nhân hoá trải nghiệm người dùng | Khách VIP có giá ưu đãi, khách lạ trả giá cao hơn |

---

## 💡 **Liên hệ với bài toán XOR trên cây**

Giả sử ta có **các danh mục sản phẩm hoặc sản phẩm riêng lẻ liên kết chặt chẽ với nhau**, tạo thành cấu trúc cây:

| Node | Tên sản phẩm | Giá trị hiện tại (doanh thu, tiềm năng,...) |
| ---- | ------------ | ------------------------------------------- |
| 0    | Điện thoại   | 100                                         |
| 1    | Ốp lưng      | 30                                          |
| 2    | Tai nghe     | 50                                          |

### Trong khi:

- Mỗi cặp sản phẩm liên kết với nhau theo kiểu “bán kèm”.
- Khi bạn giảm giá điện thoại, bạn có thể tăng giá ốp lưng hoặc tai nghe để **bù lợi nhuận**.

→ Điều này mô phỏng thao tác XOR: bạn có thể **cùng lúc thay đổi giá của 2 sản phẩm liên kết** để tạo ra **trạng thái giá tối ưu tổng thể**, nhưng bạn **không được thay đổi đơn lẻ từng cái một – vì có ràng buộc marketing hoặc rủi ro kinh doanh**.

---

## 📈 Mô hình hóa với cây và XOR:

- Cây: các danh mục sản phẩm liên kết với nhau.
- Mỗi sản phẩm có `nums[i]`: giá trị kỳ vọng (doanh thu, lợi nhuận,...).
- Thao tác: thay đổi trạng thái giá của 2 sản phẩm liên kết (XOR mô phỏng tăng/giảm ngược nhau).
- Mục tiêu: chọn các thao tác thay đổi để **tối đa tổng giá trị hệ thống sản phẩm** sau thay đổi.

---

## 🔧 Tích hợp thực tế:

- **Engine Dynamic Pricing** của E-commerce có thể mô hình các mối liên kết sản phẩm (qua cây).
- Hệ thống định kỳ chạy tối ưu (giống bài toán XOR) để điều chỉnh giá sản phẩm kèm.
- Thường kết hợp với:

  - **Machine Learning** để dự đoán giá tốt nhất
  - **Rule Engine** để đảm bảo không vượt giới hạn

---

## ✅ Tổng kết:

| Thành phần                   | Mô tả                                                                 |
| ---------------------------- | --------------------------------------------------------------------- |
| Dynamic Pricing là gì        | Chiến lược thay đổi giá theo dữ liệu thời gian thực                   |
| Lợi ích trong E-commerce     | Tối đa lợi nhuận, phản ứng giá linh hoạt, nâng trải nghiệm người dùng |
| Mối liên hệ với bài toán XOR | Thay đổi giá có điều kiện giữa các cặp sản phẩm để tối ưu tổng thể    |
| Cách tích hợp                | Dữ liệu đầu vào → Engine tính giá → cập nhật giá theo API             |
